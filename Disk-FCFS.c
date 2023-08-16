#include<stdio.h>

void main()
{
    int n,hp,diff = 0,seek = 0;

    printf("Enter the Number of Tracks : ");
    scanf("%d",&n);
    printf("Enter the Head Pointer : ");
    scanf("%d",&hp);

    int t[n];

    printf("Enter the Tracks to be Traversed\n");
    for(int i = 0 ; i < n ; i++)
    {
        diff = 0;
        printf("Enter Track %d : ",i+1);
        scanf("%d",&t[i]);

        diff = hp - t[i];
        if(diff < 0)
        {
            diff = t[i] - hp;
        }

        hp = t[i];

        seek = seek + diff;
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ==> ",t[i]);
    }

    printf("\nTotal Seek Time : %d",seek);
}
