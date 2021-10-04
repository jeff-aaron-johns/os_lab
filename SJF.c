#include <stdio.h>

int main()
{ 
	int at[20],bt[20],ct[20],tat[20],wt[20],process[20];
	int n,i,j,temp,current_time=0,start_time,completed=0,count;
	float avg_tat=0,avg_wt=0;
		
	printf("Enter the number of process : ");
	scanf("%d", &n);
	printf("Enter arrival time and burst time for each process\n\n ");

	for(i=0;i<n;i++)
			{
				printf("Arrival Time of process %d  :  ",i);
				scanf("%d",&at[i]);

				printf("Burst Time of process %d  :    ",i);
				scanf("%d",&bt[i]);

				process[i]=i;

				printf("\n");
			}

	for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(at[i]>at[j])
				{

				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=process[i];
				process[i]=process[j];
				process[j]=temp;

				}
		}
	}


	printf("\n\nProcess \tArrival time \tBurst time \tCompletion time \tTurnaround time \twaiting Time\n\n");

		while(completed<n)
			{
				count=0;
				for(i=completed;i<n;i++)
			{
			if(at[i]<=current_time)
			{
				count++;
			}
			else
			{
				break;
			}

			}

	if(count>1)
		{
		for(i=completed;i<(completed+count-1);i++)
			{
				for(j=i+1;j<completed+count;j++)
				{
				if(bt[i]>bt[j])
				{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=process[i];
				process[i]=process[j];
				process[j]=temp;

				}
				}
		}
	}

	start_time=current_time;
	ct[completed]=start_time+bt[completed];
	tat[completed]=ct[completed]-at[completed];
	wt[completed]=tat[completed]-bt[completed];
	current_time=ct[completed];

	printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d",process[completed],at[completed],bt[completed],ct[completed],tat[completed],wt[completed]);
	printf("\n");

	avg_tat=avg_tat+tat[completed];
	avg_wt=avg_wt+wt[completed];
	completed++;

	}

	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;

	printf("Average Turn around Time = %f\n",avg_tat);

	printf("Average Waiting Time = %f\n",avg_wt);

	return 0;

	}





























































