#include<stdio.h>

typedef struct page{
    int frameNumber , frequency , lastUsed;
}page;

int findLFU(page frames[],int nf)
{
    int minFreq = frames[0].frequency;
    int minlast = frames[0].lastUsed;
    int minIndex = 0;

    for(int i = 1 ; i < nf ; i++)
    {
        if(frames[i].frequency < minFreq || (frames[i].frequency == minFreq && frames[i].lastUsed < minlast))
        {
            minFreq = frames[i].frequency;
            minlast = frames[i].lastUsed;
            minIndex = i;
        }
    }
    return minIndex;
}

void main()
{
    int np,nf;

    printf("Enter the Number of Pages :  ");
    scanf("%d",&np);
    printf("Enter the Number of Frames :  ");
    scanf("%d",&nf);

    int pages[np];
    page frames[nf];

    for(int i = 0 ; i < nf ; i++)
    {
        frames[i].frameNumber = -1;
        frames[i].frequency = 0;
        frames[i].lastUsed = 0;
    }

    printf("Enter the Pages :  ");
    for(int i = 0 ; i < np ; i++)
    {
        scanf("%d",&pages[i]);
    }

    int pagefault;

    for(int i = 0 ; i < np ; i++)
    {
        int currentPage = pages[i];
        int hit = 0;
        for(int j = 0 ; j < nf ; j++)
        {
            if(frames[j].frameNumber == currentPage)
            {
                printf("\nHIT\t");
                hit = 1;
                frames[j].frequency++;
                frames[j].lastUsed = i;
                break;
            }
        }
        if(hit == 0)
        {
            pagefault++;

            int lfu = findLFU(frames,nf);
            frames[lfu].frameNumber = currentPage;
            frames[lfu].frequency = 1;
            frames[lfu].lastUsed = i;
        }

        printf("\nFOR %d : ",currentPage);
        for(int j = 0 ; j < nf ; j++)
        {
            if(frames[j].frameNumber == -1)
            {
                break;
            }
            printf(" %d ",frames[j].frameNumber);

        }
    }

    printf("\nTotal Page Faults: %d\n", pagefault);
}
