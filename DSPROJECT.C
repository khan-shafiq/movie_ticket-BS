#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100
 FILE *fp,*fopen();

 

   int seats1= 10;
   int seats2= 10;
   int seats3= 10;

   struct movie
    {
      int st;
      char name1[MAX];
      long long phone;
      char moname[MAX];
      struct movie *next;
    };
   struct tm *ti;
/*********************************************************************/
/* Function to insert seat details of the guest who has booked the seat in the movie booking system. */
/* front: front pointer,bokg: no of seats, name: guest name */
/* phno: guest phone number */
/* Returns the new front pointer. */
/*********************************************************************/

 struct movie* insert(struct movie *front, int bokg, char name[], long long phno,char m[])
  {
     struct movie *newnode;

     newnode = (struct movie*) malloc(sizeof(struct movie));

     if (newnode == NULL)
      {
	printf("\n Allocation failed\n");
	exit(2);
      }
     newnode->st = bokg;

     strcpy(newnode->name1, name);
     strcpy(newnode->moname, m);

     newnode->phone=phno;
     newnode->next = front;

     front = newnode;
     return(front);
  } /*End of insert() */

/* Function to display a seat details in a movie booking system */

 void printDetails(struct movie *p)
  {
  
  
    printf("\n ------------------------------------------------------ ");
    printf("\n Details of the booked seats are given below \n");
	printf("\n The movie booked is :");
	puts(p->moname);
    printf("\n >>No of seats booked : %d",p->st);
	printf("\n >>Name : %s", p->name1);
	printf("\n >>Phone number : %lld\n",p->phone);
    printf(" -------------------------------------------------------- \n");
	
	
  } /*End of printDetails() */
  
 /*Function to copy data into the File*/

void filesave(struct movie *p)
{	
    fprintf(fp,"\n ------------------------------------------------------ ");
    fprintf(fp,"\n Details of the booked seats are given below \n");
    fprintf(fp,"\n The movie booked is :");
    fprintf(fp,"%s\n",p->moname);
 	fprintf(fp,"\n >>No of seats booked : %d",p->st);
	fprintf(fp,"\n >>Name : %s", p->name1);
	fprintf(fp,"\n >>Phone number : %lld\n",p->phone);
	fprintf(fp," -------------------------------------------------------- \n");
 
}/*End of File Function*/

/* ********************************************************/
/* Function to cancel booking based on phone number and restore the seats to  the movie */
/* front: front pointer, ph: phone number,movs: movie name */
/* Returns: the modified booking. */
/* ********************************************************/

 struct movie* deleteBooking(struct movie *front, long long ph,char movs[])
  {
     struct movie *ptr;
     struct movie *bptr; /* bptr is pointing to the booking behind ptr */

     char k[]="Kingsman_the_golden_circle";
     char a[]="Avengers_age_of_ultron";
     char t[]="Thor_ragnarok";

     if (front->phone == ph )
       {
	 if (strcmp(k,movs)==0)
	   seats1=seats1+front->st;

	 else if(strcmp(a,movs)==0)
	   seats2=seats2+front->st;

	 else if(strcmp(t,movs)==0)
	   seats3=seats3+front->st;

	else
	 printf("\n Error");
	 ptr = front;

	 printf("\n Booking is cancelled :");
	 printf("\n Details are :");

	 printDetails(front);
	 front = front->next;
	 free(ptr);

	 return(front);
       }

  for(ptr=front->next, bptr=front; ptr!=NULL; ptr=ptr->next, bptr=bptr->next)
   {
      if (ptr->phone == ph)
	{
	   if(strcmp(k,movs)==0)
	   seats1=seats1+ptr->st;

	   else if(strcmp(a,movs)==0)
	   seats2=seats2+ptr->st;

	   else if(strcmp(t,movs)==0)
	   seats3=seats3+ptr->st;

      else
	   printf("\n Error");
	   printf("\n Booking is cancelled :");

	   printDetails(ptr);
	   bptr->next = ptr->next;

	   free(ptr);
	   return(front);
	}
   }

 printf("\n Booking with phone number %lld not found ", ph);
 return(front);

  } /*End of deleteBooking() */

/*****************************************************************/
/* Function to search the booking in a linear fashion based on phone number */
/* front: front pointer, p: phone number. */
/*****************************************************************/

 void search(struct movie *front, long long p)
  {
    struct movie *ptr;

      for (ptr = front; ptr != NULL; ptr = ptr -> next)
       {
	 if (ptr->phone == p)
	   {
	      printf("\n Your booking details are");
	      printDetails(ptr);
	      return;
	   }
       }
    printf("\n Booking with phone no %lld not found ", p);
  } /*End of search() */

/* Function to display booking of the day */
 void display(struct movie *front)
  {
    struct movie *ptr;

     for (ptr = front; ptr != NULL; ptr = ptr->next)
      {
	printDetails(ptr);
      }
  } /*End of display() */
  
   /*Function to copy data into the file*/
   
   void file(struct movie *front)
  {
    struct movie *ptr;

     for (ptr = front; ptr != NULL; ptr = ptr->next)
      {
	filesave(ptr);
      }
  }/*End of file function*/

/* Function to display the menu of the movie booking system */
 void menu()
  {
    printf("---------------------------------------------------------\n");

    printf("Press 1 to CANCEL your booking \n");
    printf("Press 2 to DISPLAY bookings of the day \n");
    printf("Press 3 to SEARCH for a booking \n");
    printf("Press 4 to GO BACK to movie selection menu \n");
    printf("----------------------------------------------------------\n");
  } /*End of menu() */

/* Function to select the option */
 char option()
  {
    char choice;

    printf("\n\n>> Enter your choice: ");
    switch(choice=getche())
     {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5': return(choice);

	default : printf("\n Invalid choice.");
     }
    return choice;
  } /*End of option() */

/* The main() program begins */
 int main()
  {


    struct movie *linkList;
    
	
    char name[21];
    long long phno;
    char choice;
    int sts;
    int book;
    int s1,s2,s3;
  
    char mona[100];

    char k[]="Kingsman_the_golden_circle";
    char a[]="Avengers_age_of_ultron";
    char t[]="Thor_ragnarok";
      time_t lt;
	lt=time(NULL);
	ti=localtime(&lt);
		
		linkList = NULL;
	    
  
	 
    printf("\n***************WELCOME TO THE MOVIE TICKET BOOKING SYSTEM***************\n");
    printf("\n                 There are three movies available today.\n");
    printf("\n1) Kingsman the golden circle.");
    printf("\n2) Avengers age of ultron.");
    printf("\n3) Thor ragnarok.");
    printf("\n4) MORE.");
    printf("\n5) SAVE and EXIT the booking system for the day.\n");

     do
      {
	printf("\n Select one of the option from the given menu->");
	scanf("%d",&book);

	switch(book)
	{
	 case 1: printf("\n The no of seats available for the movie < Kingsman the golden circle > are: %d \n",seats1);

		 if(seats1==0)
		  {
		   printf(" Sorry it's Housefull !!!! \n");
		   printf(" You can enjoy another movie\n");
		  }
		 else
		  {
		   printf("\n How may seats do you want->");
		   scanf("%d",&s1);

		    if(s1<=0 || s1>seats1)
		       {
			printf(" plz Enter a valid no of seat\n ");
			break;
		       }
		   seats1=seats1-s1;

		   printf(" Enter the details of seat no \n\n");
		   printf(" Enter your name : ");

		   fflush(stdin);
		   gets(name);

		   printf(" Enter your phone number : ");
		   scanf("%lld",&phno);
		      strcpy(mona,k);
		   linkList = insert(linkList, s1, name, phno,mona);
		  }
		    break;

	 case 2: printf("\n The no of seats available for the movie < Avengers age of ultron > are: %d\n",seats2);

		 if(seats2==0)
		  {
		    printf(" Sorry it's Housefull !!!! \n");
		    printf(" You can go for another movie \n");
		  }
		 else
		  {
		    printf("\n How may seats do you want->");
		    scanf("%d",&s2);

		     if(s2<=0 || s2>seats2)
		       {
			printf(" plz Enter a valid no of seat\n ");
			break;
		       }
		    seats2=seats2-s2;

		    printf(" Enter the details of seat no \n\n");
		    printf(" Enter your name : ");

		    fflush(stdin);
		    gets(name);

		    printf(" Enter your phone number : ");
		    scanf("%lld",&phno);
             strcpy(mona,a);
		    linkList = insert(linkList, s2, name, phno,mona);
		  }
		 break;

	 case 3: printf("\n The no of seats available for the movie < Thor ragnarok > are: %d\n",seats3);

		 if(seats3==0)
		  {
		    printf(" Sorry it is Housefull !!!! \n");
		    printf(" You can go for another movie \n");
		  }
		 else
		  {
		    printf("\n How may seats do you want->");
		    scanf("%d",&s3);

		     if(s3<=0 || s3>seats3)
		       {
			printf(" plz Enter a valid no of seat\n ");
			break;
		       }

		    seats3=seats3-s3;

		    printf("Enter details of seat no \n\n");
		    printf("Enter your name : ");

		    fflush(stdin);
		    gets(name);

		    printf("Enter your phone number : ");
		    scanf("%lld",&phno);
			    strcpy(mona,t);
		    linkList = insert(linkList, s3, name, phno,mona);
		  }
		break;

	 case 4: menu(); /*Function call */
		 do
		  {
		    choice = option(); /*to choose oeration to be performed */

		    switch(choice)
		     {
		       case '1':
			   
				printf("\n\n Enter your phone number to cancel your booking->\n");
				scanf("%lld", &phno);
			    linkList = deleteBooking(linkList, phno, mona);
				break;

		       case '2':
				if (linkList == NULL)
				  {
				    printf(" No bookings available");
				    break;
				  }
				 display(linkList);
				 break;

			case '3':
				 printf("\n\n Enter your phone number to search for your booking->");
				 scanf("%lld", &phno);

				 search(linkList, phno);
				 break;

			case '4':     printf("\n\n                       *****MOVIE LIST MENU*****\n");
				      printf("\n                 There are three movies available today.\n");
				      printf("\n1) Kingsman the golden circle.");
				      printf("\n2) Avengers age of ultron.");
				      printf("\n3) Thor ragnarok.");
				      printf("\n4) MORE.");
				      printf("\n5) SAVE and EXIT the booking system for the day.\n");
		     }
		  } while (choice != '4');
	    break;

	 case 5:
	  fp=fopen("Booking.txt","a+");
				file(linkList);
				fprintf(fp,"\nDate of Bookings\n %s",asctime(ti));
				  fclose(fp);
		exit;

	 default: printf("\n Plz select the proper option\n");
	}
      } while(book!=5);

 
  } /*End fo main()*/

