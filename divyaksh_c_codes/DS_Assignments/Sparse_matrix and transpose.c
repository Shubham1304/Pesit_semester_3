#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ORDER 10

struct SparseMatrix
{
    int row;
    int col;
    int value;
};

int **makeMatrix(int order)
{
    int i,j,**matrix;
    matrix = (int **)(malloc(order*sizeof(int *)));
    for(i = 0; i<order; i++)
    {
        matrix[i] = (int *)(malloc(order*sizeof(int)));
    }
    return matrix;
}

int isZero()
{
    if(rand()%1000 >333)
        return 1;
    return 0;
}

struct SparseMatrix *sparseMatrix(int **matrix,int order,int zeros)
{
    int i,j,elements = (order*order)-zeros,k;
    struct SparseMatrix *spMatrix;
    spMatrix = (struct SparseMatrix *)(malloc((elements+1)*sizeof(struct SparseMatrix)));
    spMatrix[0].row = order;
    spMatrix[0].col = order;
    spMatrix[0].value = zeros;
    k = 1;
    for(i = 0; i<order; i++)
    {
        for(j = 0; j<order; j++)
        {
            if(matrix[i][j] != 0)
            {
                spMatrix[k].value = matrix[i][j];
                spMatrix[k].row = i;
                spMatrix[k].col = j;
                k++;
            }
        }
    }

    return spMatrix;
}

struct SparseMatrix *transpose(struct SparseMatrix *spMatrix,int order)
{
    int i,j,k,elements = (order*order)-spMatrix[0].value;
    struct SparseMatrix *newSpMatrix;
    newSpMatrix = (struct SparseMatrix *)(malloc(((elements+1)*sizeof(struct SparseMatrix))));
    newSpMatrix[0].col = spMatrix[0].row;
    newSpMatrix[0].row = spMatrix[0].col;
    newSpMatrix[0].value = spMatrix[0].value;
    k = 1;
    for(i = 0; i<spMatrix[0].row; i++)
    {
        for(j = 1; j<elements; j++)
        {
            if(spMatrix[j].col == i)
            {
                newSpMatrix[k].col = spMatrix[j].row;
                newSpMatrix[k].row = spMatrix[j].col;
                newSpMatrix[k].value = spMatrix[j].value;
                k++;
            }
        }
    }
    return newSpMatrix;
}

int main()
{
    srand(time(NULL));
    int i,j,zeros,order = ORDER,**matrix;
    struct SparseMatrix *spMatrix,*newSpMatrix;
    /*printf("Enter the order:");
    scanf("%d",&order);*/

    matrix = makeMatrix(order);
    zeros = 0;
    for(i = 0; i<order; i++)
    {
        for(j = 0; j<order; j++)
        {
            if(isZero())
            {
                matrix[i][j] = (rand()%1000);
            }
            else
            {
                matrix[i][j] = 0;
                zeros++;
            }
        }
    }

    printf("\n\nMATRIX\n");
    for(i = 0;i<order;i++)
    {
        for(j = 0;j<order;j++)
            printf("%d\t",matrix[i][j]);
        printf("\n");
    }

    spMatrix = sparseMatrix(matrix,order,zeros);
    printf("\n\nPARSE MATRIX\n");
    for(i = 0;i<((order*order)-zeros);i++)
    {
        printf("%d,%d\t%d\n",spMatrix[i].row,spMatrix[i].col,spMatrix[i].value);
    }

    newSpMatrix = transpose(spMatrix,order);
    printf("\n\nTRANSPOSE SPARSE MATRIX\n");
    for(i = 0;i<((order*order)-zeros);i++)
    {
        printf("%d,%d\t%d\n",newSpMatrix[i].row,newSpMatrix[i].col,newSpMatrix[i].value);
    }

    return 0;
}
