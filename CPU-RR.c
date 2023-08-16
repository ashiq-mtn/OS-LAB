#include<stdio.h>

typedef struct process{
    int bt,tat,wt,pid,rt;
}process;

void main()
{
    int n , tq;
    float awt,avg_tat;

    printf("Enter the Number of Processes : ");
    scanf("%d",&n);

    process p[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Burst Time of P%d : ",i+1);
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i+1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int ct = 0,currentTime = 0,completed = 0;

    while(completed != n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].rt > 0)
            {
                if(p[i].rt < tq)
                {
                    ct = p[i].rt;
                }
                else
                {
                    ct = tq;
                }

                p[i].rt = p[i].rt - ct;
                currentTime = currentTime + ct;

                if(p[i].rt == 0)
                {
                    completed++;
                    p[i].tat = currentTime;

                }
            }

        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
        awt += p[i].wt;
        avg_tat += p[i].tat;

    }

    awt /= n;
    avg_tat /= n;

    printf("\n-----------------------------------------\n");
    printf("PID\tBT\tTAT\tWT\n");
    printf("-----------------------------------------\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].tat,p[i].wt);
    }

    printf("\nAverage Turn Around Time : %.2f ms",avg_tat);
    printf("\nAverage Waiting Time : %.2f ms",awt);

    /*printf("\n\n------------------GHANTT CHART------------------\n\n");

    int i,j;
    printf("+");
    for( i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("--");
        }
        printf("+");
    }
    printf("\n|");
    for( i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt-1 ; j++)
        {
            printf(" ");
        }
        printf("P%d",p[i].pid);
        for(j = 0 ; j < p[i].bt-1 ; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    printf("+");
    for( i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("--");
        }
        printf("+");
    }
    printf("\n0");
    ct = 0;
    for( i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < p[i].bt ; j++)
        {
            printf("  ");
        }

        ct = ct + p[i].bt;

        if(ct > 9)
        {
            printf("\b");
        }
        printf("%d",ct);

    }*/
}

