/*
 * Selection Sort of Random long integers
 * To test time complexity of selection sort
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

#define UPPER 1000000
#define LOWER 1000
#define INC 1000

void generate(int numbers[],int size)
{
        int i;
        for(i = 0;i<size;i++)
        {
                numbers[i] = rand()%100;
        }
}

void selectionSort(int numbers[],int size)
{
        int i,j,min,pos,temp,flag;

        for(i = 0;i<size;i++)
        {
                min = numbers[i];
                flag = 0;
                for(j = i;j<size;j++)
                {
                        if(numbers[j]<min)
                        {
                                flag = 1;
                                min = numbers[j];
                                pos = j;
                        }
                }

                if(flag == 1)
                {
                        temp = numbers[i];
                        numbers[i] = numbers[pos];
                        numbers[pos] = temp;
                }
        }
}

int main()
{
        int i;
        int numbers[UPPER];
        struct timeval tv;
        double start,finish;
        srand(time(NULL));

        FILE *fp = fopen("SELECTION_SORT","w");

        for(i = LOWER;i<UPPER;i+=INC)
        {
                gettimeofday(&tv,NULL);
                start = tv.tv_sec+tv.tv_usec/1000000.0;
                generate(numbers,i);
                selectionSort(numbers,i);
                gettimeofday(&tv,NULL);
                finish = tv.tv_sec+tv.tv_usec/1000000.0;
                fprintf(fp,"%d\t%lf\n",i,(finish-start));

                fflush(fp);
        }

        fclose(fp);
        return 0;
}
