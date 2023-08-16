#include<stdio.h>

int mutex = 1 , full = 0 , empty = 3 , x = 0;

void  main()
{
    int choice;
    while(1)
    {
        printf("\n1.Producer\n2.Consumer\n3.Exit\n");
        printf("\nEnter your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1://PRODUCER
                if((mutex == 1) && (empty != 0))
                {
                    producer();
                }
                else
                {
                    printf("\n\nBUFFER IS FULL\n");
                }
                break;
            case 2://CONSUMER
                if((mutex == 1) && (full != 0))
                {
                    consumer();
                }
                else
                {
                    printf("\n\nBUFFER IS EMPTY\n");
                }
                break;
            case 3://EXIT
                return;
        }
    }
}
int signal(int s)
{
    return (++s);
}
int wait(int s)
{
    return (--s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces item %d\n",x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    printf("\nConsumer consumes item %d\n",x);
    x--;
    mutex = signal(mutex);
}
