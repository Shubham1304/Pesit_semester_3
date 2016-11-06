#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int create(int);
void linear_prob(int [],int,int);
void display(int []);

void main()
{

	int a[MAX],empno, key,i;
	int ch;
	printf("\n Collision Handling By Linaer Probing");
	for(i=0;i<MAX;i++)
		a[i]=-1;

	FILE *fp;
	fp = fopen("Employee.txt","r");
	if(fp==NULL)
	{
		printf("File can not be opened");
		return;
	}
	while(fscanf(fp,"%d",&empno) != EOF)
	{
		key=create(empno);
		linear_prob(a,key,empno);
	}
	fclose(fp);
	display(a);
	return;

}

int create(int empno)
{
	int key;
	key=empno%10;
	return key;
}

void linear_prob(int a[MAX],int key,int empno)
{
	int flag,i,count=0;
	flag=0;
	if(a[key]==-1)
		a[key]=empno;

	else
	{ 
		i=0; 
		while(i<MAX)
		{
			if(a[i]!=-1)
				count++;
			i++; 
		}

		if(count==MAX)
		{
			printf("\n\n Hash Table is Full");
			display(a);
			return;
			exit(1);
		}

		for(i=key+1;i<MAX;i++)
			if(a[i]==-1)
			{
				a[i]=empno;
				flag=1;
				break;
			}

		for(i=0;i<key && flag==0;i++) if(a[i]==-1)
		{
			a[i]=empno; flag=1;
			break;
		}
	}
}

void display(int a[MAX])
{
	int i;
	printf("\n\n The HAsh Table is....\n");
	for(i=0;i<MAX;i++)
		printf("\n %d %d",i,a[i]);

}
