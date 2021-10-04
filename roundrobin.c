//Round Robin CPU Scheduling

#include<stdio.h>


void main()
{
	
	int i,n,ct=0,x,count,time_quantum;
	float wt=0,tat=0;
	int at[20],bt[20],temp[20];
	float avgtat,avgwt;

	printf("Enter total number of processes : ");
	scanf("%d",&n);
	x=n;

	for(i=0;i<n;i++)
		{
		printf("\n Enter Arrival Time of Process[%d]: ",i+1);
		scanf("%d",&at[i]);

		printf("\n Enter Burst Time of Process[%d] : ",i+1);
		scanf("%d",&bt[i]);

		temp[i]=bt[i];

		}

	printf("Enter the time quantum : ");
	scanf("%d",&time_quantum);

	printf("\nProcess No \t\t Arrival Time \tBurst Time \tCompletion time \tTurn around time \tWaiting Time\n");

	for(ct=0,i=0;x!=0;)

		{
		if(temp[i] <= time_quantum && temp[i] > 0)

		{

		 ct = ct+temp[i];
		 temp[i]=0;
		 count=1;

		}

		else if(temp[i]>0)
		{
		temp[i]=temp[i]-time_quantum;
		ct=ct+time_quantum;
		}

	if(temp[i] == 0 && count == 1)
	{
		x--;


		printf("\nProcess[%d] \t\t%d \t\t%d \t\t%d \t\t\t%d \t\t\t\%d", i+1,at[i],bt[i],ct, ct-at[i],ct-at[i]-bt[i]);
		 wt= wt + ct - at[i] - bt[i];

		tat = tat + ct- at[i];


		count=0;

	}

	if(i==n-1)
	
	{
	i=0;

	}

	else if(at[i + 1] <= ct)
	{

	i++;

	}

	else

	{

	i = 0;

	}

	}

	avgwt= wt/n;

	avgtat= tat/n;

	printf("\n Average Turn Around Time :  %f\n" ,avgtat);

	printf("\n Average Waiting Time : %f\n" , avgwt);

	

}









  

