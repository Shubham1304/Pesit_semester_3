#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

#define MAX 1000
#define DIFF 1
#define DIGIT 210000

int chartoi(char num)
{
        if(num>='0'&&num<='9')
                return num-48;  //value of the number

        fprintf(stderr,"\n\nError in number\n\n");              //error
        exit(1);
}

char itochar(int num)
{
        return num+48;
}

void initialize(char *num)
{
        int i;
        i = 0;
        while(i<DIGIT)
        {
                num[i] = '0';
                i++;
        }

        num[DIGIT-1] = '\0';
}

char *add(char *num1,char *num2)
{
        int i,sum;
        char *ans;
        ans = (char *)(malloc(sizeof(char)*DIGIT));

        initialize(ans);

        i = DIGIT-2;
        while(i>0)
        {
                sum = chartoi(num1[i])+chartoi(num2[i])+chartoi(ans[i]);
                ans[i] = itochar(sum%10); //sum
                i--;
                ans[i] = itochar(sum/10); //carry
        }

        ans[DIGIT-1]='\0';
        return ans;
}

void Fib_mem(long size)
{
        FILE *fout;
        fout = fopen("FIB_MEM","w");
        double start,finish;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        start = tv.tv_sec+tv.tv_usec/1000000.0;

        unsigned long long i = 0,j = 0;
        char *num1,*num2,*num3;
        num1 = (char *)(malloc(sizeof(char)*DIGIT));
        num2 = (char *)(malloc(sizeof(char)*DIGIT));
        num3 = (char *)(malloc(sizeof(char)*DIGIT));

        initialize(num1);
        initialize(num2);
        initialize(num3);

        num1[DIGIT-2] = '0';
        num2[DIGIT-2] = '1';

        for(i = 2;i<=MAX;i++)
        {
                num3 = add(num1,num2);
                strcpy(num1,num2);
                strcpy(num2,num3);

                if(i%DIFF==0)
                {
                        gettimeofday(&tv,NULL);
                        finish = tv.tv_sec+tv.tv_usec/1000000.0;
                        fprintf(fout,"%llu\t%lf\n",i,(finish-start));
                        fflush(fout);
                        // start = finish;
                }
        }
        //        fprintf(fout,"%s",num3);
        fclose(fout);
}

void Fib_mem_1(long size)
{
        double start,finish;
        struct timeval tv;

        unsigned long long i = 0;
        char *num1,*num2,*num3;
        num1 = (char *)(malloc(sizeof(char)*DIGIT));
        num2 = (char *)(malloc(sizeof(char)*DIGIT));
        num3 = (char *)(malloc(sizeof(char)*DIGIT));

        initialize(num1);
        initialize(num2);
        initialize(num3);

        num1[DIGIT-2] = '0';
        num2[DIGIT-2] = '1';

        gettimeofday(&tv,NULL);
        start = tv.tv_sec+tv.tv_usec/1000000.0;
        for(i = 2;i<=size;i++)
        {
                num3 = add(num1,num2);
                strcpy(num1,num2);
                strcpy(num2,num3);
        }
        
        gettimeofday(&tv,NULL);
        finish = tv.tv_sec+tv.tv_usec/1000000.0;

        printf("%lf",(finish-start));
}

char *Fib_rec(unsigned long long num)
{
        char *num1; 
        num1 = (char *)(malloc(sizeof(char)*DIGIT));
        initialize(num1);

        if(num==0)
        {
                num1[DIGIT-2]='0';
                return num1;
        }
        else if(num==1)
        {
                num1[DIGIT-2]='1';
                return num1;
        }

        return add(Fib_rec(num-1),Fib_rec(num-2));
}

char *fibonacci(long num)
{

        unsigned long long i = 0,j = 0;
        char *num1,*num2,*num3;
        num1 = (char *)(malloc(sizeof(char)*DIGIT));
        num2 = (char *)(malloc(sizeof(char)*DIGIT));
        num3 = (char *)(malloc(sizeof(char)*DIGIT));

        initialize(num1);
        initialize(num2);
        initialize(num3);

        num1[DIGIT-2] = '0';
        num2[DIGIT-2] = '1';

        for(i = 2;i<=num;i++)
        {
                num3 = add(num1,num2);
                strcpy(num1,num2);
                strcpy(num2,num3);
        }

        return num3;
}

int main(int argc,char *argv[])
{
        unsigned long long i = 0;
        char *ans; 
        ans = (char *)(malloc(sizeof(char)*DIGIT));
        initialize(ans);

        /*Memoization*/
        //        start = time(NULL);
//        Fib_mem();
        Fib_mem_1(atol(argv[1]));

        //        printf("%s\n",fibonacci(atol(argv[1])));

        /*Recursive*/
        /*FILE *fp;
        double start,finish;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        start = tv.tv_sec+tv.tv_usec/1000000.0;
        fp = fopen("FIB_REC","w");
        start = time(NULL);
        for(i = DIFF;i<=MAX;i+=DIFF)
        {
                Fib_rec(i);
                gettimeofday(&tv,NULL);
                finish = tv.tv_sec+tv.tv_usec/1000000.0;
                fprintf(fp,"%llu\t%lf\n",i,(finish-start));
                fflush(fp);
               // start = finish;
        }
        fclose(fp);
*/
        return 0;
}
