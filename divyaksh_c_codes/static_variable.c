#include<stdio.h>

void Recursion(int value)
{
        static int level = 0;
        if(value == 5)
                return;

        level++;
        Recursion(value+1);
        printf("%d\t%d\n",value,level);
        level--;
}

void main()
{
        Recursion(1);
}
