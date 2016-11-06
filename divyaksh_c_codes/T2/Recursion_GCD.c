#include<stdio.h>

long GCD(long num1,long num2)
{
        if(num1==0)
                return num2;
        if(num2==0)
                return num1;
        return GCD(num2,num1%num2);
}

int main()
{
        long num1,num2;
        num1 = num2 = 0;

        printf("Enter two numbers whose GCD is to be taken:\n");
        scanf("%ld%ld",&num1,&num2);

        printf("GCD=%ld\n\n",GCD(num1,num2));
}
