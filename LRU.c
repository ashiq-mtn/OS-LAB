#include<stdio.h>

void main()
{
    int np,nf;

    printf("Enter the Number of Page Referencing Sequences : ");
    scanf("%d",&np);

    printf("Enter the Number of Frames : ");
    scanf("%d",&nf);

    int pages[np] , frames[nf];

    for(int i = 0 ; i < nf ; i++)
    {
        frames[i] = -1;
    }

    printf("Enter the Page Referencing Sequences : ");
    for(int i = 0 ; i < np ; i++)
    {
        scanf("%d",&pages[i]);
    }

    int pagefault;

    for(int i = 0 ; i < np ; i++)
    {
        int hit = 0;
        for(int j = 0 ; j < nf ; j++)
        {
            if(pages[i] == frames[j])
            {
                printf("\n\nHIT\n\n");
                hit = 1;
                break;
            }
        }
        if(hit == 0)
        {
            pagefault++;

            int lru;

            if(pagefault > nf)
            {
                int framesClone[nf];
                for(int j = 0 ; j < nf ; j++)
                {
                    framesClone[j] = frames[j];
                }
                for(int j = i-1 ; j >= 0 ; j--)
                {
                    for(int k = 0 ; k < nf ; k++)
                    {
                        if(pages[j] == framesClone[k])
                        {
                            lru = pages[j];
                            framesClone[k] = -1;
                        }
                    }
                }
                printf("\nLRU : %d\n",lru);

                for(int k = 0 ; k < nf ; k++)
                {
                    if(frames[k] == lru)
                    {
                        frames[k] = pages[i];
                    }
                }

            }
            else
            {
                frames[pagefault-1] = pages[i];
            }

            printf("\nFOR %d : ",pages[i]);
            for(int k = 0 ; k < nf ; k++)
            {
                if(frames[k] == -1)
                {
                    break;
                }
                printf(" %d ",frames[k]);
            }
        }
    }
    printf("\nPAGE FAULT : %d",pagefault);
}
