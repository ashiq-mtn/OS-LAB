#include<stdio.h>

void main()
{
    int n,hp,max,temp;

    printf("Enter the Number of Tracks : ");
    scanf("%d",&n);
    printf("Enter the Maximum Range of Disk : ");
    scanf("%d",&max);
    printf("Enter the Head Pointer : ");
    scanf("%d",&hp);

    int t[n+2];

    printf("Enter the Tracks to be Traversed\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter Track %d : ",i+1);
        scanf("%d",&temp);
        if(temp > max)
        {
            printf("!!Invalid Request!!\nEnter another Request : ");
            scanf("%d",&temp);
        }

        t[i] = temp;
    }

    t[n] = hp;
    t[n+1] = max;

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < n+1-i ; j++)
        {
            if(t[j] > t[j+1])
            {
                int temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    int head;

    for(int i = 0 ; i < n+2 ; i++)
    {
        if(t[i] == hp)
        {
            head = i;
        }
    }
    printf(" ");
    for(int i = head ; i < n+2 ; i++)
    {
        printf("%d ==> ",t[i]);
    }
    printf("0 ==> ");
    for(int i = 0 ; i < head ; i++)
    {
        printf("%d ==> ",t[i]);
    }

    int seek = (max - hp) + max + (t[head-1]);

    printf("\nTotal Seek Time : %d",seek);
}
