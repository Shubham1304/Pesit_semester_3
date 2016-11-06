#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct Employee
{
	long id;
	char name[50];
	struct Employee *link;
}EMP;

long createKey(long id)
{
	return id % MAX;
}

EMP *addNode(EMP *head,long id,char name[])
{
	if(head == NULL)
	{
		head = (EMP *)(malloc(sizeof(EMP)));
		head->id = id;
		strcpy(head->name,name);
		head->link = NULL;
		return head;
	}
	if(!(strcmp(head->name,"")))
	{
		head->id = id;
		strcpy(head->name,name);
		head->link = NULL;
		return head;
	}

	head->link = addNode(head->link,id,name);
	return head;
}

void readEmployees(EMP *emp[])
{
	FILE *fp = fopen("Employee.txt","r");
	long id,key;
	char name[50];

	do
	{
		fscanf(fp,"%ld%s",&id,name);
		if(id!=0 && (strcmp(name,"")))
		{
			key = createKey(id);
			emp[key] = addNode(emp[key],id,name);
		}
		id = 0;
		strcpy(name,"");
	}while(!feof(fp));
	fclose(fp);

}

void displayEmployees(EMP *emp[])
{
	int i;
	for(i = 0;i<MAX;i++)
	{
		EMP *head = emp[i];
		printf("%d\n",i);
		while(head!=NULL)
		{
			printf("id:%ld,name:%s\n",head->id,head->name);
			head = head->link;
		}
		printf("\n");
	}
}

void main()
{
	//FILE *fp = fopen("Employee.txt","r");
	EMP *emp[MAX];
	int i;
	for(i = 0;i<MAX;i++)
	{
		emp[i] = (EMP *)(malloc(sizeof(EMP)));
		emp[i]->link = NULL;
	}
	readEmployees(emp);
	displayEmployees(emp);
}
