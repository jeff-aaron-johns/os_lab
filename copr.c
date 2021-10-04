#include<stdio.h>
 
int mutex=1,full=0,empty,x=0;
void producer();
void consumer();
int wait();
int signal();
 void main()
 {
 	int choice,n;
 	printf("Enter the buffer size : ");
 	scanf("%d",&n);
 	empty =n;
 	printf("\n1.Producer\n2.Consumer\n3.Exit");
 	while(choice<3)
 	{
 		printf("\nEnter your choice : ");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1:
 				if((mutex==1) && (empty!=0))
 					producer();
 				else
 					printf("Buffer is full");
 				break;

 			case 2:
 				if((mutex==1) && (full!=0))
 					consumer();
 				else
 					printf("Buffer is empty");
 				break;


 			case 3:
 				break;
 		}
 	}
 }

 int wait(int s)
 {
 	return(--s);
 }

 int signal(int s)
 {
 	return(++s);
 }

 void producer()
 {
 	mutex = wait(mutex);
 	full = signal(full);
 	empty = wait(empty);
 	x++;
 	printf("\nproducer produces the item %d",x);
 	mutex = signal(mutex);
 }

 void consumer()
 {
 	mutex = wait(mutex);
 	full = wait(full);
 	empty = signal(empty);
 	printf("\nconsumer consumes the item %d",x);
 	x--;
 	mutex = signal(mutex);
 }
