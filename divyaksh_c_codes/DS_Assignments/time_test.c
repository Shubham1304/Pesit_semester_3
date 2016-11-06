#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

struct timeval tv;

int main()
{
        gettimeofday(&tv,NULL);
        double exec_time = tv.tv_sec+tv.tv_usec/1000000.0;
        printf("%lf\n",exec_time);
        return 0;
}
