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
Student *create(Student *,int);
Student *insertFront(Student *);
Student *insertRear(Student *);
Student *deleteFront(Student *);
Student *deleteRear(Student *);

Student *create(Student *node,int n)
{
        int i = n;
        while(i>=1)
        {
                node = insertFront(node);
                i--;
        }
        return node;
}

Student *insertFront(Student *head)
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
        scanf("%s",temp->name);
        printf("USN:");
        scanf("%s",temp->usn);
        printf("Branch:");
        scanf("%s",temp->branch);
        printf("Semester:");
        scanf("%d",&temp->sem);
        printf("Phone Number:");
        scanf("%ld",&temp->phNo);
        return head;
}

Student *insertRear(Student *head)
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
        scanf("%s",term->name);
        printf("USN:");
        scanf("%s",term->usn);
        printf("Branch:");
        scanf("%s",term->branch);
        printf("Semester:");
        scanf("%d",&term->sem);
        printf("Phone Number:");
        scanf("%ld",&term->phNo);
        return head;

}

Student *deleteFront(Student *head)
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
        return head;
}

Student *deleteRear(Student *head)
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
        temp->next=NULL;
        return head;
}

void display(Student *head)
{
        Student *temp;
        temp = head;
        while(temp!=NULL)
        {
                printf("Name:");
                fputs(temp->name,stdout);
                printf("\nUSN:");
                fputs(temp->usn,stdout);
                printf("\nBranch:");
                fputs(temp->branch,stdout);
                printf("\nSemester:");
                printf("%d",temp->sem);
                printf("\nPhone Number:");
                printf("%ld\n\n",temp->phNo);
                temp = temp->next;
        }
}

int main()
{
        Student *head;
        head = NULL;
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
                                head = create(head,num);
                                break;

                        case 2:
                                head = insertFront(head);
                                break;

                        case 3:
                                head = insertRear(head);
                                break;

                        case 4:
                                head =  deleteFront(head);
                                break;

                        case 5:
                                head = deleteRear(head);
                                break;

                        case 6:
                                display(head);
                                break;

                        case 7:
                                break;

                        default:
<<<<<<< HEAD
                                fprintf(stderr,"\n\nINVALID CHOICE\n\n");
=======
                                printf(stderr,"\n\nINVALID CHOICE\n\n");
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
                                break;
                }
        }
        return 0;
}
