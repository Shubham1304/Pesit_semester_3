/*
 * A Binary Search tree is a special case of the Binary tree. In BST the key of the left child is less than that of the parent and
 * the key of the right child is greater than that of the parent.
 *  (leftKey <= parentKey <= rightKey)
 * Created on : 12/10/2016
 * Author : Divyaksh Shukla
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>

#define UPPER 1000000
#define LOWER 1000
#define INC 1000

struct BinarySearchTree
{
        long key;
        struct BinarySearchTree *left_child;
        struct BinarySearchTree *right_child;
};

typedef struct BinarySearchTree BST;

BST *makeBST(long[],long);
BST *addNode(BST *,long);
long *generateValues(long);

BST *makeBST(long numbers[],long size)
{
        BST *root = (BST *)(malloc(sizeof(BST)));
        long i;
        root->key = numbers[0];
        root->left_child = NULL;
        root->right_child = NULL;

        for(i = 1;i<size;i++)
        {
                root = addNode(root,numbers[i]);
        }
        return root;
}

BST *addNode(BST *root,long value)
{
        if(root == NULL)
        {
                BST *root = (BST *)(malloc(sizeof(BST)));
                root->key = value;
                root->left_child = NULL;
                root->right_child = NULL;
                return root;
        }

        if(value<=root->key)
                root->left_child = addNode(root->left_child,value);
        else
                root->right_child = addNode(root->right_child,value);
        return root;
}

long *generateValues(long size)
{
        long *values = (long *)(calloc(size,sizeof(long)));
        long i;
        for(i = 0;i < size;i++)
        {
                values[i] = rand()%1000;
        }

        return values;
}

int main(int argc,char *argv[])
{
        //printf("%ld\n",noOfLevelsBST(atol(argv[1])));

        srand(time(NULL));
        struct timeval tv;
        double start,finish;
        long i = 0;
        long *values;
        BST *root;

        FILE *fp = fopen("BST_SORT","w");

        for(i = LOWER;i<UPPER;i+=INC)
        {
                gettimeofday(&tv,NULL);
                start = tv.tv_sec+tv.tv_usec/1000000.0;
                values = generateValues(i);
                root = makeBST(values,i);
                gettimeofday(&tv,NULL);
                finish = tv.tv_sec+tv.tv_usec/1000000.0;
                fprintf(fp,"%ld\t%lf\n",i,(finish-start));
                fflush(fp);
        }

        fclose(fp);
        //traverseInorder(root,1);        //Parameters : root pointer, level of tree
        return 0;
}











