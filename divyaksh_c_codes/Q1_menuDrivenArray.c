#include<stdio.h>

int arr[5000],pos = 0,i = 0,n = 0,ele = 0,temp = 0;

void create();
void display();
void insert();
void delete();

main()
{
	int choice = 0;
	while(choice != 5)
	{
	printf("\n\t\tArray Commands\n\n");
	printf("1.Create\n2.Display\n3.Insert at a point\n4.Delete particular position\n5.EXIT\n\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		create();
		break;
	case 2:
		display();
		break;
	case 3:
		insert();
		break;
	case 4:
		delete();
		break;
	case 5:
        printf("\n\nEXIT\n\n");
		break;
	default:
		printf("\n\nINVALID INPUT\n\n");
	}
	}
}

void create()
{
        printf("\nEnter the number of elements:");
        scanf("%d",&n);

        printf("\nEnter the elements:\n"); 
        i = 0;
        while(i<n)
        {
                scanf("%d",&arr[i++]);
        }
        printf("\n\nCREATED\n\n");
}

void display()
{
        printf("\nThe array elements are:");
        i = 0;
        while(i<n)
        {
                printf("%d\n",arr[i++]);
        }
}

void insert()
{
        printf("\nEnter the value and the insertion index:");
        scanf("%d%d",&ele,&pos);
        
        if(pos<n && pos>=0)
        {
                i = n;
                while(i>pos)
                {
                        arr[i] = arr[i-1];
                        i--;
                }
                arr[pos] = ele;
                n++;
        }

        else
                printf("\n\nINVALID INSERTION INDEX\n\n");
}

void delete()
{
        printf("\nEnter the deletion index:");
        scanf("%d",&pos);

        if(pos<n && pos>=0)
        {
                i = pos;
                temp = arr[pos];
                while(i<n-1)
                {
                        arr[i] = arr[i+1];
                        i++;
                }

                printf("\nDeleted element:%d",temp);
                n--;
        }

        else
                printf("\n\nINVALID DELETION INDEX\n\n");
}
