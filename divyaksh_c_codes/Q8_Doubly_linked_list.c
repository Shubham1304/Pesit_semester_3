#include<stdio.h>
#include<stdlib.h>

struct Dll
{
        long data;
        struct Dll *lLink;
        struct Dll *rLink;
};

typedef struct Dll DLL;

void insertFront(DLL**,DLL**,long);
void insertRear(DLL**,DLL**,long);
void deleteFront(DLL**,DLL**);
void deleteRear(DLL**,DLL**);

void insertFront(DLL **front,DLL **rear,long element)
{
        DLL *temp = (DLL *)(malloc(sizeof(DLL)));
        
        if(temp == NULL)
        {
                fprintf(stderr,"\n\nHEAP FULL\n\n");
                return;
        }

        if ((*front)==NULL)
        {
                (*rear) = temp;
                (*front) = temp;
                (*front)->rLink = NULL;
                (*front)->lLink = NULL;
        }
        else
        {
                (*front)->lLink = temp;
                temp->rLink = (*front);
                temp->lLink = NULL;
                (*front) = temp;
        }

        (*front)->data = element;
}

void insertRear(DLL **front,DLL **rear,long element)
{
        DLL *temp = (DLL *)(malloc(sizeof(DLL)));

        if(temp == NULL)
        {
                fprintf(stderr,"\n\nHEAP FULL\n\n");
                return;
        }

        if ((*rear)==NULL)
        {
                (*rear) = temp;
                (*front) = temp;
                (*rear)->rLink = NULL;
                (*rear)->lLink = NULL;
        }
        else
        {
                (*rear)->rLink = temp;
                temp->lLink = (*rear);
                temp->rLink = NULL;
                (*rear) = temp;
        }

        (*rear)->data = element;
}

void deleteFront(DLL **front,DLL **rear)
{
        DLL *temp;
        if((*front)==NULL)
        {
                fprintf(stderr,"\n\nNO DATA Stored\n\n");
                return;
        }

        else if((*front)->rLink==NULL && (*front)->lLink==NULL)
        {
                temp = (*front);
                (*front) = NULL;
                (*rear) = NULL;
                free(temp);
                return;
        }
        else
        {
                temp = (*front);
                (*front) = temp->rLink;
                (*front)->lLink = NULL;
                free(temp);
                return;
        }
}

void deleteRear(DLL **front,DLL **rear)
{
        DLL *temp;
        if((*rear)==NULL)
        {
                fprintf(stderr,"\n\nNO DATA Stored\n\n");
                return;
        }

        else if((*rear)->rLink==NULL && (*rear)->lLink==NULL)
        {
                temp = (*rear);
                (*front) = NULL;
                (*rear) = NULL;
                free(temp);
                return;
        }
        else
        {
                temp = (*rear);
                (*rear) = temp->lLink;
                (*rear)->rLink = NULL;
                free(temp);
                return;
        }
}

void displayDLL(DLL *front,DLL *rear)
{
        DLL *temp = front;

        while(temp!=NULL)
        {
                printf("%ld\n",temp->data);
                temp = temp->rLink;
        }
}

int main()
{
        DLL *front,*rear;
        int choice = 0;
        long element;

        printf("\t\tDOUBLY LINKED LIST\n\n");
        printf("1.Insert FRONT\n2.Insert REAR\n3.Delete FRONT\n4.Delete REAR\n5.Display\n6.EXIT\n\n");

        while(choice!=6)
        {
                printf("CHOICE:");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                        printf("Enter the value to be added:");
                        scanf("%ld",&element);
                        insertFront(&front,&rear,element);
                        break;

                        case 2:
                        printf("Enter the value to be added:");
                        scanf("%ld",&element);
                        insertRear(&front,&rear,element);
                        break;

                        case 3:
                        deleteFront(&front,&rear);
                        break;

                        case 4:
                        deleteRear(&front,&rear);
                        break;

                        case 5:
                        displayDLL(front,rear);
                        break;

                        case 6:
                        break;

                        default:
                        fprintf(stderr,"\n\nINVALID CHOICE\n\n");
                        break;
                }
        }

        //clearDLL(&front,&rear);
        return 0;
}
