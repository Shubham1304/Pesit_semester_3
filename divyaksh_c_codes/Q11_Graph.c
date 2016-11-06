#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Graph
{
	int value;
	struct Graph *link[MAX];
}GRAPH;

typedef struct AdjList
{
	GRAPH *node;
	struct AdjList *link;
}ADJLIST;

GRAPH *makeGraph(int[][],int size);
ADJLIST *makeAdjList(GRAPH *);
ADJLIST *adjacent(GRAPH *,int val);

void main()
{
	int mat[MAX][MAX],size = MAX;

}
