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
#include<math.h>

<<<<<<< HEAD
#define MAX 10

struct BinarySearchTree
{
	long key;
	struct BinarySearchTree *left_child;
	struct BinarySearchTree *right_child;
=======
#define MAX 1000000

struct BinarySearchTree
{
        long key;
        struct BinarySearchTree *left_child;
        struct BinarySearchTree *right_child;
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
};

typedef struct BinarySearchTree BST;

void traverseInorder(BST *root,long);
void traversePreorder(BST *root);
void traversePostorder(BST *root);
BST *makeBST(long[],long);
BST *addNode(BST *,long);
<<<<<<< HEAD
BST *deleteNode(BST *,long);
BST *minValue(BST *);
=======
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
long *generateValues(long);

void traverseInorder(BST *root,long level)
{
<<<<<<< HEAD
	if(root == NULL)
		return;

	traverseInorder(root->left_child,level+1);
	printf("%d---->%ld\n",root->key,level);
	traverseInorder(root->right_child,level+1);
=======
        if(root == NULL)
                return;

        traverseInorder(root->left_child,level+1);
        printf("%d---->%ld\n",root->key,level);
        traverseInorder(root->right_child,level+1);
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

void traversePreorder(BST *root)
{
<<<<<<< HEAD
	if(root == NULL)
		return;

	traversePreorder(root->left_child);
	traversePreorder(root->right_child);
	printf("%ld\n",root->key);
=======
        if(root == NULL)
                return;

        traversePreorder(root->left_child);
        traversePreorder(root->right_child);
        printf("%ld\n",root->key);
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

void traversePostorder(BST *root)
{
<<<<<<< HEAD
	if(root == NULL)
		return;

	printf("%ld\n",root->key);
	traversePostorder(root->left_child);
	traversePostorder(root->right_child);
=======
        if(root == NULL)
                return;

        printf("%ld\n",root->key);
        traversePostorder(root->left_child);
        traversePostorder(root->right_child);
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

BST *makeBST(long numbers[],long size)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

BST *addNode(BST *root,long value)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

long *generateValues(long size)
{
<<<<<<< HEAD
	long *values = (long *)(calloc(size,sizeof(long)));
	long i;
	for(i = 0;i < size;i++)
	{
		values[i] = rand()%1000;
	}

	return values;
}

BST *deleteNode(BST *root,long deleteKey)
{
	if(root == NULL)
		return NULL;
	if(deleteKey < root->key)
		root->left_child = deleteNode(root->left_child,deleteKey);
	else if(deleteKey > root->key)
		root->right_child = deleteNode(root->right_child,deleteKey);
	else
	{
		BST *temp;
		if(root->left_child == NULL && root->right_child == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left_child == NULL)
		{
			temp = root->right_child;
			free(root);
			return temp;
		}
		else if(root->right_child == NULL)
		{
			temp = root->left_child;
			free(root);
			return temp;
		}
		temp = minValue(root->right_child);
		root->key = temp->key;
		root->right_child = deleteNode(root->right_child,temp->key);
	}
	return root;
}

BST *minValue(BST *root)
{
	if(root->left_child != NULL)
		return minValue(root->left_child);
	return root;
=======
        long *values = (long *)(calloc(size,sizeof(long)));
        long i;
        for(i = 0;i < size;i++)
        {
                values[i] = rand()%1000;
        }

        return values;
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}

int main(int argc,char *argv[])
{
<<<<<<< HEAD
	//printf("%ld\n",noOfLevelsBST(atol(argv[1])));

	srand(time(NULL));
	//long *values = generateValues(MAX);
	long values[12] = {6,9,5,2,8,15,24,14,7,8,5,2};
	BST *root = makeBST(values,12);
	printf("\nINORDER\n");
	traverseInorder(root,1);        //Parameters : root pointer, level of tree
	printf("\nPREORDER\n");
	traversePreorder(root);
	printf("\nPOSTORDER\n");
	traversePostorder(root);
	return 0;
=======
        //printf("%ld\n",noOfLevelsBST(atol(argv[1])));

        srand(time(NULL));
        long *values = generateValues(MAX);
        BST *root = makeBST(values,MAX);
        //traverseInorder(root,1);        //Parameters : root pointer, level of tree
        return 0;
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
}











