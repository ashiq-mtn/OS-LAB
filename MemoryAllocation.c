#include<stdio.h>

void main()
{
    int np,nb,p[10],b[10],rem_b[10],b_sort[10],b_alloc[10];

    printf("Enter the Number of Blocks : ");
    scanf("%d",&nb);

    printf("Enter the Block Sizes : ");
    for(int i = 0 ; i < nb ; i++)
    {
        scanf("%d",&b[i]);
        rem_b[i] = b[i];
        b_sort[i] = i;
        b_alloc[i] = -1;
    }

    printf("Enter the Number of Processes : ");
    scanf("%d",&np);

    printf("Enter the Process Sizes : ");
    for(int i = 0 ; i < np ; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("\nBLOCK\tSIZE\n");
    for(int i = 0 ; i < np ; i++)
    {
        printf("%d\t%d\n",i+1,b[i]);
    }
    printf("\nPROCESS\tSIZE\n");
    for(int i = 0 ; i < np ; i++)
    {
        printf("%d\t%d\n",i+1,p[i]);
    }
    //sort
    for(int i = 0 ; i < nb-1 ; i++)
    {
        for(int j = 0 ; j < nb-i-1 ; j++)
        {
            if(b[b_sort[j]] > b[b_sort[j+1]])
            {
                int temp = b_sort[j];
                b_sort[j] = b_sort[j+1];
                b_sort[j+1] = temp;
            }
        }
    }

    int choice;
    printf("\n\n---------MENU---------\n");
    printf("1.First Fit\n2.Worst Fit\n3.Best Fit\n");
    printf("\nEnter your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1://FIRST FIT
            for(int i = 0 ; i < np ; i++)
            {
                for(int j = 0 ; j < nb ; j++)
                {
                    if(p[i] <= rem_b[j])
                    {
                        rem_b[j] = 0;
                        b_alloc[j] = i+1;
                        break;
                    }
                }
            }
            break;
        case 2://WORST FIT
            for(int i = 0 ; i < np ; i++)
            {
                for(int j = nb-1 ; j >= 0 ; j--)
                {
                    if(p[i] <= rem_b[b_sort[j]])
                    {
                        rem_b[b_sort[j]] = 0;
                        b_alloc[b_sort[j]] = i+1;
                        break;
                    }
                }
            }
            break;
        case 3://BEST FIT
            for(int i = 0 ; i < np ; i++)
            {
                for(int j = 0 ; j < nb ; j++)
                {
                    if(p[i] <= rem_b[b_sort[j]])
                    {
                        rem_b[b_sort[j]] = 0;
                        b_alloc[b_sort[j]] = i+1;
                        break;
                    }
                }
            }
            break;
        default:
            printf("\n!!--INVALID CHOICE--!!\n");
            return;
    }

    printf("\n\nBLOCK\tSIZE\tALLOCATED PROCESS\n");
    for(int i = 0 ; i < np ; i++)
    {
        printf("%d\t%d\t",i+1,b[i]);
        if(b_alloc[i] > -1)
        {
            printf("%d\n",b_alloc[i]);
        }
        else
        {
            printf("-\n");
        }
    }

    printf("\nUnallocated Processes : ");
    for(int i = 0 ; i < np ; i++)
    {
        int flag = 0;
        for(int j = 0 ; j < nb ; j++)
        {
            if(b_alloc[j] == i+1)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf(" %d ",i+1);
        }
    }
    printf("\n\n");
}
