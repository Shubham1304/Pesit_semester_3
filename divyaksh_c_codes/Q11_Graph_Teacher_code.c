#include<stdio.h>
#include<stdlib.h>
int vis[10];
void bfs(int src,int a[10][10],int n)
{
	int u,i;
	int f=-1,r=- 1;
	int q[10];
	vis[src]=1;
	q[++r]=src;
	while(f<r)
	{
		u=q[++f];
		for(i=0;i<n;i++)
		{
			if(a[u][i]==1 && vis[i]==0)
			{
				vis[i]=1;
				q[++r]=i;
			}

		}

	}
}

void dfs(int src,int a[10][10],int n)
{
	int i;
	vis[src]=1;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0 && a[src][i]==1)
		{
			dfs(i,a,n);
		}
	}

}

int main()
{
	int n,i,j,a[10][10],src,flag,ch;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("1.BFS\n 2.DFS\n 3.Exit\n");
	scanf("%d",&ch); 
	switch(ch)
		while(1)
		{
			case 1:
				printf("\n Enter the Source:");
				scanf("%d",&src);
				for(i=0;i<n;i++)
					vis[i]=0;
				if((src<1)||(src>n))
				{
					printf("\nBfs is not possible");
				}
				else
				{
					bfs(src,a,n);
					for(i=0;i<n;i++)
					{

						if(vis[i]==1)
						{
							printf("%d is reachable\n",i);
						}
						else
						{
							printf("%d is not reachable\n",i);
						}
					}
				}
				break;

			case 2:
				flag=1;
				for(src=0;src<n;src++)
				{
					for(i=0;i<n;i++)
						vis[i]=0;
					dfs(src,a,n);
					for(i=0;i<n;i++)
					{
						if(vis[i]==0)
						{
							printf("graph is not connected\n");
							flag=0 ;
							return ;
						}
					}
				}
				if(flag==1)
				{
					printf("graph is connected\n");
				}

				break;

			case 3: 
				exit(0);
		}
}
