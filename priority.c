#include<stdio.h>
void main()
{
    int n,i,bt[20], at[20],j,sum=0,bt1[20],wt[20],tat[20],t,p[20], index,pr=-1,temp=-1;
    float avg_wt=0, avg_tat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nBurst Time of P%d = ",i);
        scanf("%d",&bt[i]);
        sum=sum+bt[i];
        bt1[i]=bt[i];
        wt[i]=0;
        tat[i]=0;
        printf("Arrival Time of P%d = ",i);
        scanf("%d",&at[i]);
        printf("Priority of P%d = ",i);
        scanf("%d",&p[i]);
        if(temp<p[i])
            temp=p[i];
    }
    t=0;
    printf("\nGantt Chart\n");
    while(t<sum)
    {
        pr=temp+1;
        for(i=1;i<=n;i++)
        {
            if(bt[i]>0 && at[i]<=t)
            {
                if(pr>p[i])
                {
                    pr=p[i];
                    index=i;
                }
            }
        }
        printf("P%d --> ",index);
        bt[index]=0;
        wt[index]=t-at[index];
        tat[index]=wt[index]+bt1[index];
        t=t+bt1[index];
    }
    printf("END\n");
    for(i=1;i<=n;i++)
    {
        avg_wt=avg_wt+wt[i];
        avg_tat=avg_tat+tat[i];
    }
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=1;i<=n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i, at[i],bt1[i],wt[i],tat[i]);
    }
    avg_wt=avg_wt/n;
    avg_tat=avg_tat/n;
    printf("\nAverage waiting time = %.2f\nAverage turnaround time = %.2f",avg_wt,avg_tat);
}
