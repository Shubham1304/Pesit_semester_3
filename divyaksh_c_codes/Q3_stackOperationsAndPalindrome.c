#include<stdio.h>
#include<stdlib.h>

int push(int *stack,int top)
{
        int element;
        printf("\nEnter the element to be pushed:");
        scanf("%d",&element);

        top++;
        *(stack+top) = element;
        return top;
}

int pop(int *stack,int top)
{
        if(top>=0)
        {
                printf("Element poped:%d",*(stack+top));
                return (top-1);
        }

        printf("\nSTACK OVERFLOW\n");
        return top;
}

void display(int *stack,int top)
{
        printf("\nSTACK CONTENTS\n\n");
        printf("%d\t<--top\n",*(stack+top));
        int counter = top-1;
        while(counter>=0)
        {
                printf("%d\n",*(stack+top));
                counter--;
        }
}

void palindrome()
{
        int *stack,top=-1,expr=0;
        stack = (int *)(realloc((void *)stack,sizeof(int)));

        printf("\nEnter any positive number:");
        scanf("%d",&expr);

        int exp1=expr,exp2 = 0;

        while(exp1!=0)
        {
                top++;
                *(stack+top)=exp1%10;
                exp1 /= 10;
        }

        int counter = 1;

        while(top>=0)
        {
                exp2 = (*(stack+top)*counter)+exp2;
                top--;
                counter *= 10;
        }

        if(expr == exp2)
        {
                printf("\nThe number %d is a palindrome\n",expr);
        }
        else
        {
                printf("\nThe number %d is not a palindrome\n",expr);
        }

        //free((void *)stack);
}

main()
{
        int choice=0;
        int top=-1;
        int *stack_opr;
        stack_opr = (int *)(malloc(sizeof(int)));
        while(choice!=5)
        {
                printf("\n\tStack Operations\n\n");
                printf("1.Push\n2.Pop\n3.Display\n4.Check palindrome\n5.EXIT\n\n");
                printf("Enter your choice:");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                top = push(stack_opr,top);
                                break;

                        case 2:
                                top = pop(stack_opr,top);
                                break;

                        case 3:
                                display(stack_opr,top);
                                break;

                        case 4:
                                palindrome();
                                break;

                        case 5:
                                break;

                        default:
                                printf("\n\nINVALID CHOICE\n\n");
                }

        }
}
