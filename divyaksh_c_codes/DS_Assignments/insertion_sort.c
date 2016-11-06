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

void insertionSort(int numbers[],int size)
{
	int i,j,value;

	for(i = 1;i<size;i++)
	{
		j = i;
		value = numbers[i];
		while(j > 0 && numbers[j-1]>value)
		{
			numbers[j] = numbers[j-1];
			j--;
		}
		numbers[j] = value;
	}
}

void printArray(int numbers[],int size)
{
	int i;
	for(i = 0;i<size;i++)
	{
		printf("%d\n",numbers[i]);
	}
}

int main()
{
        int i;
	int numbers[UPPER];
        //int numbers[5] = {6,4,765,2,4};
        struct timeval tv;
        double start,finish;
        srand(time(NULL));

        FILE *fp = fopen("INSERTION_SORT","w");

        for(i = LOWER;i<=UPPER;i+=INC)
        {
                gettimeofday(&tv,NULL);
                start = tv.tv_sec+tv.tv_usec/1000000.0;
                generate(numbers,i);
                insertionSort(numbers,i);
                gettimeofday(&tv,NULL);
                finish = tv.tv_sec+tv.tv_usec/1000000.0;
                fprintf(fp,"%d\t%lf\n",i,(finish-start));

                fflush(fp);
        }


        fclose(fp);
        return 0;
}
