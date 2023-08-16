#include<stdio.h>
typedef struct process{
    int at,bt,tat,wt,pid,prio;
}process;
void main()
{
    int n , ct = 0;
    float awt,avg_tat;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    process p[n];
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the Arrival time and Burst time and Priority of P%d : ",i+1);
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].prio);
        p[i].pid = i+1;
    }
    //sort
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = 1 ; j < n - i - 1 ; j++)
        {
            if(p[j].prio < p[j+1].prio)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(ct < p[i].at)
        {
            ct = p[i].at + p[i].bt;
        }
        else
        {
            ct = ct + p[i].bt;
        }

        p[i].tat = ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        awt = awt + p[i].wt;
        avg_tat = avg_tat + p[i].tat;
    }
    awt = awt/n;
    avg_tat = avg_tat/n;
    printf("\n--------------------------------------------\n");
    printf("PID\tAT\tBT\tTAT\tWT\n");
    printf("--------------------------------------------\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
    }
    printf("\nAverage Turn Around Time : %.2f ms",avg_tat);
    printf("\nAverage Waiting Time : %.2f ms",awt);

    printf("\n\nGHANTT CHART\n");
    int i,j;


    printf("+");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("--");
        }
        printf("+");
    }
    printf("\n|");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt - 1 ; j++)
        {
            printf(" ");
        }
        printf("P%d",p[i].pid);
        for(j = 0 ; j < p[i].bt - 1 ; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n+");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("--");
        }
        printf("+");
    }
    printf("\n0");
    ct = 0;
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("  ");
        }
        if(ct < p[i].at)
        {
            ct = p[i].at + p[i].bt;
        }
        else
        {
            ct = ct + p[i].bt;
        }
        if(ct > 9)
        {
            printf("\b");
        }
        printf("%d",ct);
    }

}
