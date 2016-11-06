#include<stdio.h>
#include<stdlib.h>

typedef struct Students
{
        char name[100];
        char usn[10];
        char branch [3];
        int sem;
        long phNo;
        struct Students *next;
}Student;
void create(Student *,int);
void insertFront(Student *);
void insertRear(Student *);
void deleteFront(Student *);
void deleteRear(Student *);

void create(Student *node,int n)
{
        int i = n;
        while(i>=1)
        {
                insertFront(node);
                i--;
        }
        return;
}

void insertFront(Student *head)
{
        Student *temp;
        temp = (Student *)(malloc(sizeof(Student)));

        if(temp==NULL)
        {
                fprintf(stderr,"\n\nHEAP FULL\n\n");
                return;
        }

        temp->next = head;
        head = temp;

        printf("Name:");
        fgets(temp->name,100,stdin);
        printf("USN:");
        fgets(temp->usn,10,stdin);
        printf("Branch:");
        fgets(temp->branch,3,stdin);
        printf("Semester:");
        scanf("%d",&temp->sem);
        printf("Phone Number:");
        scanf("%ld",&temp->phNo);
}

void insertRear(Student *head)
{
        Student *temp,*term;
        term = (Student *)(malloc(sizeof(Student)));

        if(term==NULL)
        {
                fprintf(stderr,"\n\nHEAP FULL\n\n");
                return;
        }

        temp = head;
        while(temp->next!=NULL)
        {
                temp = temp->next;
        }

        temp->next = term;
        term->next = NULL;

        printf("Name:");
        fgets(term->name,100,stdin);
        printf("USN:");
        fgets(term->usn,10,stdin);
        printf("Branch:");
        fgets(term->branch,3,stdin);
        printf("Semester:");
        scanf("%d",&term->sem);
        printf("Phone Number:");
        scanf("%ld",&term->phNo);
}

void deleteFront(Student *head)
{
        Student *temp;
        temp = head;
        if(head==NULL)
        {
                fprintf(stderr,"\n\nLIST EMPTY\n\n");
                return;
        }
        head = temp->next;
        free(temp);
}

void deleteRear(Student *head)
{
        Student *temp;
        temp = head;
        if(temp->next==NULL)
        {
                head = NULL;
                free(temp);
                return;
        }
        while((temp->next)->next!=NULL)
        {
                temp = temp->next;
        }

        free(temp->next);
}

void display(Student *head)
{
        Student *temp;
        temp = head;
        while(temp!=NULL)
        {
                printf("Name:");
                fputs(temp->name,stdin);
                printf("USN:");
                fputs(temp->usn,stdin);
                printf("Branch:");
                fputs(temp->branch,stdin);
                printf("Semester:");
                printf("%d",temp->sem);
                printf("Phone Number:");
                printf("%ld",temp->phNo);
        }
}

int main()
{
        Student *head;
        //        head = (Student)(malloc(sizeof(Student)));

        int choice = 0,num = 0;

        printf("\n\n\tLINKED LIST OPERATIONS\n\n");
        printf("1.CREATE\n2.INSERT front\n3.INSERT rear\n4.DELETE front\n5.DELETE rear\n6.DISPLAY\n7.EXIT\n");

        while(choice!=7)
        {
                printf("CHOICE: ");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                printf("Enter the number of students:");
                                scanf("%d",&num);
                                create(head,num);
                                break;

                        case 2:
                                insertFront(head);
                                break;

                        case 3:
                                insertRear(head);
                                break;

                        case 4:
                                        deleteFront(head);
                                        break;

                        case 5:
                                        deleteRear(head);
                                        break;

                        case 6:
                                        display(head);
                                        break;

                        case 7:
                                        break;

                        default:
                                        fprintf(stderr,"\n\nINVALID CHOICE\n\n");
                                        break;
                }
        }
        return 0;
}
