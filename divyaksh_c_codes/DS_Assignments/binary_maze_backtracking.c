#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define RANDOMIZE 70

typedef struct Position
{
        int x;
        int y;
};

int zeroOrOne()
{

        int r = rand()%100;

        if(r<=RANDOMIZE)
        {
                return 1;
        }
        return 0;
}

void createMaze(int **maze,int n)
{
        int i,j;
        for(i = 0;i<n;i++)
        {
                for(j = 0;j<n;j++)
                {
                        maze[i][j] = zeroOrOne();
                }
        }

        maze[0][0] = 1;
        maze[n-1][n-1] = 1;
}

void displayMaze(int **maze,int n)
{
        int i,j;
        for(i = 0;i<n;i++)
        {
                for(j = 0;j<n;j++)
                {
                        printf("%d ",maze[i][j]);
                }
                printf("\n");
        }

}

void display1s(int **maze,int n)
{
        int i,j;
        for(i = 0;i<n;i++)
        {
                for(j = 0;j<n;j++)
                {
                        if(maze[i][j]==1)
                                printf("%d ",maze[i][j]);
                        else
                                printf("  ");
                }
                printf("\n");
        }

}

void push(Position *pos,int *top,int x,int y)
{
        (*top)++;
        pos[*top].x = x;
        pos[*top].y = y;
}

void pop(Position *pos,int *top)
{
        --(*top);
}

int isVisited(Position *pos,int *top,int x,int y)
{
        int temp = (*top);
        while(temp>=0)
        {
                if(pos[temp].x==x && pos[temp].y==y)
                        return 1;
                temp--;
        }

        return 0;
}

void printSolution(int **maze,int n,Position *pos,int top)
{
        int **sol,i,j;
        sol = (int **)(calloc(n,sizeof(int *)));
        for(i = 0;i<n;i++)
        {
                sol[i] = (int *)(calloc(n,sizeof(int)));
        }
        /*        printf("\nSOLUTION EMPTY\n");
                  displayMaze(sol,n);
         */
        for(i = top;i>=0;i--)
        {
                sol[pos[i].x][pos[i].y] = 1;
        }


        printf("\nSOLUTION\n");
        display1s(sol,n);

}

SolveMaze(int **maze,int n,Position *pos,int top)
{
        int x = pos[top].x;
        int y = pos[top].y;
        int r,c;

        if(x==n-1&&y==n-1)
        {
                printSolution(maze,n,pos,top);
                return true;
        }

        if(maze[x][y]==0)
                return false;

        else
        {
                push(pos,&top,
                for (r = 1;r<=-1;r--)
                {
                        for(c = 1;c<=-1;c--)
                        {
                                x = pos[top].x+r;
                                y = pos[top].y+c;
                                if(isValid(x,y))
                        }
                }
        }

}

int main(int argc,char *argv[])
{
        /*        if(argc>2)
                  {
                  fprintf(stderr,"%s : Too many arguments\n\n",argv[0]);
                  return 0;
                  }
                  else if(argc<2)
                  {
                  fprintf(stderr,"%s : Too few arguments\n\n",argv[0]);
                  return 0;
                  }
         */
        int **maze,n = 5,i;
        n = atoi(argv[1]);
        printf("%d\n\n",n);
        maze = (int **)(calloc(n,sizeof(int *)));
        for(i = 0;i<n;i++)
        {
                maze[i] = (int *)(calloc(n,sizeof(int)));
        }
        pos = (struct Position *)(calloc(n*n,sizeof(struct Position)));
        top = -1;

        srand(time(NULL));
        createMaze(maze,n);
        printf("\nMAZE\n");
        displayMaze(maze,n);
        //        display1s(maze,n);

        bool ans = SolveMaze(maze,n,0,0,"W");

        return 0;
}
