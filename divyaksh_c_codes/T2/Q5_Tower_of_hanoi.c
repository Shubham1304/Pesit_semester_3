#include<stdio.h>
#include<stdlib.h>

void TowerOfHanoi(unsigned long n,char fromPeg,char toPeg,char auxPeg)
{
        if(n==1)
                printf("Move Disk %lu from %c to %c\n",n,fromPeg,toPeg);
        else
        {
                TowerOfHanoi(n-1,fromPeg,auxPeg,toPeg);
                printf("Move Disk %lu from %c to %c\n",n,fromPeg,toPeg);
                TowerOfHanoi(n-1,auxPeg,toPeg,fromPeg);
        }
}

int main(int argc,char *argv[])
{
        char fromPeg = 'A',toPeg = 'B',auxPeg = 'C';
        unsigned long disks = atol(argv[1]);
/*        printf("Enter the number of Disks:\n");
        scanf("%lu",&disks);
*/
        TowerOfHanoi(disks,fromPeg,toPeg,auxPeg);
}	
