#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000

void push(float *stack,int *top,float element)
{
        stack[(*top)+1] = element;
        (*top)++;
}

float pop(float *stack,int *top)
{
        if((*top)!=-1)
        {
            (*top)--;
            return stack[(*top)+1];
        }

        else
        {
                fprintf(stderr,"\n\nERROR IN INPUT\n\n");
                exit(1);
        }
}

float chartof(char num)
{
        return (float)(num-48);
}

int isOperand(char val)
{
        if(val>='0'&&val<='9')
                return 1;

        return 0;
}

float postfixEval(char *expr)
{
        float *stack;
        stack = (float *)(malloc(sizeof(float)*MAX));
        float op1,op2,ans;
        int top = -1,i = 0;

        for(i = 0;expr[i]!='\0';i++)
        {
                if(isOperand(expr[i]))
                {
                        push(stack,&top,chartof(expr[i]));
                }
                else
                {
                        switch(expr[i])
                        {
                                case '+':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                ans = op1+op2;
                                push(stack,&top,ans);
                                break;

                                case '-':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                ans = op1-op2;
                                push(stack,&top,ans);
                                break;

                                case '*':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                ans = op1*op2;
                                push(stack,&top,ans);
                                break;

                                case '/':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                if(op2==0.0)
                                {
                                        fprintf(stderr,"\nDivision by zero\n");
                                        exit(1);
                                }
                                ans = op1/op2;
                                push(stack,&top,ans);
                                break;

                                case '%':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                if(op2==0.0)
                                {
                                        fprintf(stderr,"\nDivision by zero\n");
                                        exit(1);
                                }
                                ans = (int)(op1)%(int)(op2);
                                push(stack,&top,ans);
                                break;

                                case '^':
                                op2 = pop(stack,&top);
                                op1 = pop(stack,&top);
                                ans = pow(op1,op2);
                                push(stack,&top,ans);
                                break;

                        }
                }
        }

        return pop(stack,&top);
}

int main()
{
       char *expr;
       expr = (char *)(malloc(sizeof(char)*MAX));

       printf("\n\t\tPOSTFIX EVALUATION\n\n");
       printf("Enter postfix expression (only numerical):\n");
       scanf("%s",expr);

       float ans = postfixEval(expr);

       printf("\nThe postfix Evaluation is:%f\n\n",ans);
       return 0;
}
