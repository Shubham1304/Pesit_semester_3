#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void push(char *stack,int *top,char element)
{
        stack[(*top)+1] = element;
        (*top)++;
}

char pop(char *stack,int *top)
{
        (*top)--;
        return stack[(*top)+1];
}

char stackTop(char *stack,int top)
{
        return stack[top];
}

int isOperand(char val)
{
        if((val>='A' && val<='Z')||(val>='a' && val<='z'))
                return 1;
        else
                return 0;
}

int isEmpty(char *stack,int top)
{
        if(top==-1)
                return 1;
        else
                return 0;
}

int precedence(char val)
{
        int val_rank = 0;

        switch(val)
        {
                case '+':
                        val_rank = 1;
                        break;

                case '-':
                        val_rank = 1;
                        break;

                case '*':
                        val_rank = 2;
                        break;

                case '/':
                        val_rank = 2;
                        break;

                case '%':
                        val_rank = 2;
                        break;
                case '^':
                        val_rank = 3;
                        break;
        }

        return val_rank;
}

int main()
{
        char *stack;
        stack = (char *)(malloc(sizeof(char)*MAX));
        char *expr,*ans;
        expr = (char *)(malloc(sizeof(char)*MAX));
        ans = (char *)(malloc(sizeof(char)*MAX));
        int i = 0,k = 0,top=-1;

        printf("\t\tINFIX TO POSTFIX\n\n");
        scanf("%s",expr);

        i = 0;
        k = 0;
        //push(stack,&top,'(');
        while(expr[i]!='\0')
        {
                if(isOperand(expr[i]))
                {
                        ans[k++] = expr[i];
                }

                else
                {
                        if(expr[i]=='(')
                        {
                                push(stack,&top,'(');
                        }
                        else if(expr[i]==')')
                        {
                                while(stackTop(stack,top)!='(')
                                {
                                        ans[k++] = pop(stack,&top);
                                }
                                char ch = pop(stack,&top);
                        }
                        else if(precedence(expr[i])-precedence(stackTop(stack,top))>0)
                        {
                                push(stack,&top,expr[i]);
                        }

                        else if(precedence(expr[i])-precedence(stackTop(stack,top))<=0)
                        {
                                ans[k++] = pop(stack,&top);
                                push(stack,&top,expr[i]);
                        }
                }
                i++;
        }

        while(!isEmpty(stack,top))
        {
                ans[k++] = pop(stack,&top);
        }

        printf("\nPostfix Expression:\n%s\n",ans);
        return 0;
}
