#include<stdio.h>

void main()
{
    int np,nf;

    printf("Enter the Number of Page Referencing Sequence : ");
    scanf("%d",&np);
    printf("Enter the Number of Frames : ");
    scanf("%d",&nf);

    int frame[nf] , page[np];

    for(int i = 0 ; i < nf ; i++)
    {
        frame[i] = -1;
    }

    printf("Enter the Page Referencing Sequence : ");
    for(int i = 0 ; i < np ; i++)
    {
        scanf("%d",&page[i]);
    }

    int nextalloc = 0,pagefault = 0;

    for(int i = 0 ; i < np ; i++)
    {
        int hit = 0;
        for(int j = 0 ; j < nf ; j++)
        {
            if(page[i] == frame[j])
            {
                printf("\n\n--HIT--");
                hit = 1;
                break;
            }
        }
        if(hit == 0)
        {
            pagefault++;
            frame[nextalloc] = page[i];
            nextalloc = (nextalloc + 1) % nf;
            printf("\nFOR %d : ",page[i]);
            for(int j = 0 ; j < nf ; j++)
            {
                if(frame[j] == -1)
                {
                    break;
                }
                printf(" %d ",frame[j]);
            }
        }
    }
    printf("\n\nPAGE FAULT : %d",pagefault);
}

