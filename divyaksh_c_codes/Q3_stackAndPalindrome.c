#include<stdio.h>
#include<stdlib.h>

int push(int *stack,int top,int element)
{
        if(stack+top+1 == NULL);
        else
        {
                *(stack+top+1) = element;
                top++;
        }

        return top;
}

int pop(int *stack, int *top)
{
        if((*top) == -1)
        {
                fprintf(stderr,"\n\nSTACK UNDERFLOW\n\n");
                return 0;
        }
        else
        {
                (*top)--;
                return *(stack+(*top)+1);
        }
        
}

void display(int *stack,int top)
{
        int i = 0;
        if(top == -1)
                printf("\n\nSTACK EMPTY\n\n");
        else
        {
                for(i = top;i>=0;i--)
                {
                        printf("%d\n",*(stack+i));
                }
        }

        return;
}

void palindrome()
{
        int *stack,*stackcopy,*revstack;
        stack = (int *)(malloc(sizeof(int)));
        stackcopy = (int *)(malloc(sizeof(int)));
        revstack = (int *)(malloc(sizeof(int)));
        int number = 0,i = 0,stack_top = -1,revstack_top = -1,stackcopy_top = -1,flag = 0;

        printf("\n\n\t\tPALINDROME\n\n");
        printf("Enter a number to be checked:");
        scanf("%d",&number);

        while(number!=0)
        {
                stack_top = push(stack,stack_top,number%10);
                stackcopy_top = push(stackcopy,stackcopy_top,number%10);
                number /= 10;
        }

        for(i = stackcopy_top;i>=0;i--)
        {
                revstack_top = push(revstack,revstack_top,pop(stackcopy,&stackcopy_top));
        }

        flag = 0;

        for(i = 0;i<=stack_top;i++)
        {
                if(*(stack+i)==*(revstack+i));
                else
                {
                        flag = 1;
                        break;
                }
        }

        if(flag == 0)
                printf("The number is a palindrome\n\n");
        else
                printf("The number is not a palindrome\n\n");

        
        free(stack);
        free(stackcopy);
        free(revstack);
        return;
}

int main()
{
        int *stack;
        int choice = 0,elem = 0,top = -1;
        stack = (int*)(malloc(sizeof(int)));

        while(choice!=5)
        {

                printf("\t\tSTACK OPERATIONS\n\n");
                printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.EXIT\n");
                printf("Enter your choice:");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                printf("Enter the element to be pushed:");
                                scanf("%d",&elem);
                                top = push(stack,top,elem);
                                break;

                        case 2:
                                printf("Element popped:%d\n",pop(stack,&top));
                                break;

                        case 3:
                                display(stack,top);
                                break;

                        case 4:
                                palindrome();
                                break;

                        case 5:
                                break;

                        default:
                                printf("\n\nINVALID INPUT\n\n");
                }
        }

        return 0;
}
