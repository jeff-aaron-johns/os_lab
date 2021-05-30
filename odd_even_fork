/*Program to create 2 process- one parent process must bring odd numbers up to limit n. At the same time child process must bring even numbers upto n. Also print the process id */

#include<stdio.h>
#include<unistd.h>

int main()
{
  int limit,i,fid;
  printf("Enter the limit \n");
  scanf("%d",&limit);
 
  fid=fork();
  
  if(fid>0)
	{
	  printf("\nIt is parent process");
		
		   for(i=0;i<limit;i++)
		    {
                      if(i%2!=0)
			{
			  printf("\n" "%d",i);
                        }
		     }
                    printf("\nParent process id is: ""%d",getppid());
	 }
   else
	 {
	   
 	   printf("\nIt is child process");

		   for(i=0;i<limit;i++)
		    {
                      if(i%2==0)
			{
			  
			  printf("\n" "%d ",i);
                        }
		     }
                    printf("\nchild process id is :""%d",getpid());

		
 	   }
}
