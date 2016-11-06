/**
 * Title : Circular Queue ADT (using arrays)
 * Author : Divyaksh Shukla
 * Compiled on : Wednesday 28 September 2016 
*/

#include<stdio.h>

#define MAX 1000

struct CQueue
{
        char value[MAX][MAX];
        int front;
        int rear;
};

void add(struct CQueue cqueue)
{
        if((cqueue.rear+1)%MAX==cqueue.front)
        {
                fprintf(stderr,"\n\nQUEUE FULL\n\n");
                return;
        }
        else if(cqueue.rear==-1)
        {
                cqueue.front = 0;
                cqueue.rear = 0;
        }
        else
        {
                cqueue.rear = (cqueue.rear+1)%MAX;
        }

        printf("Enter value:");
        scanf("%s",cqueue.value[cqueue.rear]);

        return;
}

void delete(struct CQueue cqueue)
{
        if(cqueue.front==-1)
        {
                fprintf(stderr,"\n\nQUEUE EMPTY\n\n");
                return;
        }
        else if((cqueue.front+1)%MAX==cqueue.rear)
        {
                cqueue.front = -1;
                cqueue.rear = -1;
                return;
        }

        cqueue.front = (cqueue.front+1)%MAX;
}

void display(struct CQueue cqueue)
{
        int i = cqueue.front;
        while(i!=cqueue.rear)
        {
                printf("%s",cqueue.value[i]);
                i = (i+1)%MAX;
        }
}

int main()
{
        int choice = 0;
        struct CQueue cqueue;
        printf("\n\t\tCIRCULAR QUEUE\n\n");
        printf("1.Add\n2.Delete\n3.Display\n4.EXIT\n\n");

        while(choice!=4)
        {
                printf("Enter your choice:");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                        add(cqueue);
                        break;

                        case 2:
                        delete(cqueue);
                        break;

                        case 3:
                        display(cqueue);
                        break;

                        case 4:
                        break;

                        default:
                        fprintf(stderr,"\n\nINVALID CHOICE\n\n");
                        break;
                }
        }
        return 0;
}
