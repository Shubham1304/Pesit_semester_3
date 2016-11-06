/*
 * Bubble Sort of Random long integers
 * To test time complexity of bubble sort
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

void bubbleSort(int numbers[],int size)
{
	int i,j,temp;

	for(i = 0;i<size;i++)
	{
		for(j = 0;j<size-i-1;j++)
		{
			if(numbers[j]>numbers[j+1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}
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

	FILE *fp = fopen("BUBBLE_SORT","w");

	for(i = LOWER;i<UPPER;i+=INC)
	{
		gettimeofday(&tv,NULL);
		start = tv.tv_sec+tv.tv_usec/1000000.0;
		generate(numbers,i);
		bubbleSort(numbers,i);
		gettimeofday(&tv,NULL);
		finish = tv.tv_sec+tv.tv_usec/1000000.0;
		fprintf(fp,"%d\t%lf\n",i,(finish-start));

		fflush(fp);
	}

	fclose(fp);
	return 0;
}
