#include<stdio.h>
void main()
{
    int n,m;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    printf("Enter the Number of Resources : ");
    scanf("%d",&m);

    int alloc[n][m],max[n][m],need[n][m],avai[m];

    printf("Enter the Allocation Matrix\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Allocation for P%d : ",i+1);
        for(int j = 0 ; j < m ; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("\nEnter the Maximum Matrix\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Max for P%d : ",i+1);
        for(int j = 0 ; j < m ; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nNeed Matrix\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j]; //calculating NEED
            printf(" %d ",need[i][j]);
        }
        printf("\n");
    }

    printf("Enter the Available : ");
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d",&avai[i]);
    }

    int work[m],finish[n],safeSequence[n],ind = 0;

    for(int i = 0 ; i < n ; i++)
    {
        finish[i] = 0;
    }
    for(int i = 0 ; i < m ; i++)
    {
        work[i] = avai[i];  //WORK = AVAILABLE
    }
    //calculation
    for(int k = 0 ; k < n ; k++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 0;
                for(int j = 0 ; j < m ; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)  // NEED < AVAILABLE
                {
                    safeSequence[ind++] = i+1;
                    for(int y = 0 ; y < m ; y++)
                    {
                        work[y] += alloc[i][y];
                        finish[i] = 1;
                    }
                }
            }

        }
    }

    int flag = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(finish[i] == 0)  // PROCESS IS NOT COMPLETED
        {
            flag = 0;
            printf("\n!!DEADLOCK OCCURS!!\n");
            break;
        }
    }
    if(flag == 1)
    {
        printf("\n\n--++--Safe Sequence--++--\n\n");
        for(int i = 0 ; i < n-1 ; i++)
        {
            printf(" P%d ==> ",safeSequence[i]);
        }
        printf(" P%d ",safeSequence[n-1]);
    }
}
