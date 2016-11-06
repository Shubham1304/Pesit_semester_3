#include<stdio.h>

typedef unsigned long long number;

number binary(number num)
{
        if(num == 0)
                return 0;
        return (num%2+10*binary(num/2));
}

int main()
{
        number dec;
        printf("Enter decimal value:\n");
        scanf("%llu",&dec);

        printf("BINARY = %llu\n\n",binary(dec));
}
