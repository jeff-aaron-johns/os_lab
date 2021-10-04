//First in First Out

#include<stdio.h>

int main()
{ 
	int at[20],bt[20],ct[20]={0},tat[20]={0},wt[20]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
		
	printf("Enter the number of process : ");
	scanf("%d", &n);
	printf("Enter arrival time and burst time for each process\n\n ");

	for(int i=0;i<n;i++)
			{
				printf("Arrival Time of process[%d]  :  ",i+1);
				scanf("%d",&at[i]);

				printf("Burst Time of process[%d]  :    ",i+1);
				scanf("%d",&bt[i]);

				printf("\n");
			}

        //Calculating completion time

	for(int j=0;j<n;j++)
		{	
			sum=sum+bt[j];
			ct[j]=ct[j]+sum;
		}

	//Calculating Turn around time and Waiting time

	for(int k=0;k<n;k++)
		{
			tat[k]=ct[k]-at[k];
			totalTAT=totalTAT+tat[k];
		}

	
	for(int k=0;k<n;k++)
		{
			wt[k]=tat[k]-bt[k];
			totalWT=totalWT+wt[k];
		}


		printf("Solution : \n\n");
		printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

	
	for(int i=0;i<n;i++)
		{
			printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		}


		printf("\n\n Average Turnaround time = %f\n",totalTAT/n);
		printf("\n\n Average Waiting time = %f\n\n",totalWT/n);

		return 0;

		}

