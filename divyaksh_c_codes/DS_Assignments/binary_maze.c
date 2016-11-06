/**
 * BINARY MAZE-BACKTRACKING
 * Author : Divyaksh Shukla
 * Date : 28-09-2016
 * Version : 0.2
 * Description :
 * A backtracking algorithm to solve a binary maze of 0s and 1s.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define RANDOMIZE 70

struct Position
{
        int x;
        int y;
};

struct Position *pos;
int top;

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

void push(int x,int y)
{
        top++;
        pos[top].x = x;
        pos[top].y = y;
}

void pop()
{
        --top;
}

void printSolution(int n)
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

bool SolveMaze(int **maze,int n,int x,int y,char *dir)
{
        if(pos[top].x==n-1 && pos[top].y==n-1)
        {
                printSolution(n);
                return true;
        }

        if(maze[x][y] == 0)
        {
                return false;
        }

        push(x,y); //Push the current location onto the stack
        maze[x][y] = 0;

        if(top>=0)
        {
                if((x!=n-1 && y!=n-1) && dir!="NE" && SolveMaze(maze,n,x+1,y+1,"SW"))      //South-West
                        return true;

                else if(x!=n-1 && dir!="N" && SolveMaze(maze,n,x+1,y,"S"))                     //South
                        return true;

                else if(y!=n-1 && dir!="E" && SolveMaze(maze,n,x,y+1,"W"))                       //West
                        return true;

                else if((x!=n-1 && y!=0) && dir!="NW" && SolveMaze(maze,n,x+1,y-1,"SE"))        //South-East
                        return true;

                else if((x!=0 && y!=n-1) && dir!="SE" && SolveMaze(maze,n,x-1,y+1,"NW"))        //North-West
                        return true;

                else if(x!=0 && dir!="S" && SolveMaze(maze,n,x-1,y,"N"))                       //North
                        return true;

                else if((x!=0 && y!=0) && dir!="SW" && SolveMaze(maze,n,x-1,y-1,"NE"))            //North-East
                        return true;

                else if(y!=0 && dir!="W" && SolveMaze(maze,n,x,y-1,"E"))                       //East
                        return true;
        }

        pop();
        return false;
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
