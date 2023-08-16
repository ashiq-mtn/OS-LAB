#include<stdio.h>

void main()
{
    int n , hp , max;
    printf("Enter the Number of Tracks : ");
    scanf("%d",&n);
    printf("Enter the Maximum Range of Disk : ");
    scanf("%d",&max);
    printf("Enter the Head Pointer : ");
    scanf("%d",&hp);

    int t[n+2] , q[n];

    printf("Enter the Tracks to be Traversed : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&q[i]);
        t[i] = q[i];
    }

    t[n] = hp;
    t[n+1] = max;

    for(int i = 0 ; i < n+2 ; i++)
    {
        for(int j = 0 ; j < (n+2)-i-1 ; j++)
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

    for(int i = head ; i < n+2 ; i++)
    {
        printf(" %d ==> ",t[i]);
    }
    for(int i = head-1 ; i >= 1 ; i--)
    {
        printf(" %d ==> ",t[i]);
    }
    printf(" %d ",t[0]);

    int seek = (max - hp) + (max - t[0]);

    printf("\nTotal Seek Time : %d",seek);
}
