#include<stdio.h>

enum Months {JAN=1,FEB,MAR,APRIL,MAY,JUNE,JULY,SEP,OCT,NOV,DEC};
typedef enum Months MONTHS;

void main()
{
	MONTHS month;
	int i = 0;
	for(i = 0;i<12;i++)
	{
		printf("%d\n",month+i);
	}
}
