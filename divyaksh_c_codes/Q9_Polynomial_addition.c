#include<stdio.h>
#include<stdlib.h>

struct Polynomial
{
	int coef;
	int power;
	struct Polynomial *link;
};

typedef struct Polynomial POLY;

POLY *insertPoly(POLY *,int,int);
POLY *add(POLY *,POLY *);

POLY *makePoly(int coef[],int power[],int size)
{
	POLY *head = NULL;

	int i;
	for(i = 0;i<size;i++)
	{
		head = insertPoly(head,coef[i],power[i]);
	}

	return head;
}

POLY *insertPoly(POLY *head,int coef,int power)
{

	if(head == NULL)
	{
		POLY *temp = (POLY *)(malloc(sizeof(POLY)));
		head = temp;
		temp->link = head;
		temp->coef = coef;
		temp->power = power;
	}
	else
	{
		POLY *temp1 = head;
		while(temp1->link != head)
		{
			temp1 = temp1->link;
		}
		POLY *temp2 = (POLY *)(malloc(sizeof(POLY)));
		temp1->link = temp2;
		temp2->link = head;
		temp2->coef = coef;
		temp2->power = power;
	}
	return head;
}

void displayPoly(POLY *head)
{
	POLY *temp = head;
	while(temp->link != head)
	{
		printf("%dx^%d\t",temp->coef,temp->power);
		temp = temp->link;
	}
	printf("%dx^%d\n",temp->coef,temp->power);

}

POLY *add(POLY *poly1,POLY *poly2)
{
	POLY *term1 = poly1;
	POLY *term2 = poly2;
	POLY *ans = NULL;

	do
	{
		if(term1->power > term2->power)
		{
			ans = insertPoly(ans,term1->coef,term1->power);
			term1 = term1->link;
		}
		else if(term1->power < term2->power)
		{
			ans = insertPoly(ans,term2->coef,term2->power);
			term2 = term2->link;
		}

		else
		{
			ans = insertPoly(ans,(term1->coef + term2->coef),term1->power);
			term1 = term1->link;
			term2 = term2->link;
		}
	}while(term1!=poly1 && term2!=poly2);

	while(term1!=poly1)
	{
		ans = insertPoly(ans,term1->coef,term1->power);
		term1 = term1->link;
	}

	while(term2!=poly2)
	{
		ans = insertPoly(ans,term2->coef,term2->power);
		term2 = term2->link;
	}

	return ans;
}

void main()
{
<<<<<<< HEAD
	/*int coeff1[5] = {1,3,5,34,6};
=======
	int coeff1[5] = {1,3,5,34,6};
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306
	int power1[5] = {8,7,6,5,4};
	int coeff2[6] = {2,6,10,68,12,11};
	int power2[6] = {8,7,6,4,3,1};

	POLY *poly1 = makePoly(coeff1,power1,5);
	POLY *poly2 = makePoly(coeff2,power2,6);
<<<<<<< HEAD
	POLY *ans = NULL;*/
	int i,coef,power;
	POLY *poly1 = NULL;
	POLY *poly2 = NULL;
	int poly1_size;
	int poly2_size;

	printf("Enter the number of terms for the first Polynimial:");
	scanf("%d",&poly1_size);
	for(i = 0;i<poly1_size;i++)
	{
		printf("Coeff = ");
		scanf("%d",&coef);
		printf("Exponent = ");
		scanf("%d",&power);
		poly1 = insertPoly(poly1,coef,power);
	}

	printf("Enter the number of terms for the second Polynimial:");
	scanf("%d",&poly2_size);
	for(i = 0;i<poly2_size;i++)
	{
		printf("Coeff = ");
		scanf("%d",&coef);
		printf("Exponent = ");
		scanf("%d",&power);
		poly2 = insertPoly(poly2,coef,power);
	}
=======
	POLY *ans = NULL;
>>>>>>> 5fd598622f84ab39d1cbe9a1220289518033d306

	ans = add(poly1,poly2);
	printf("Poly 1:");
	displayPoly(poly1);
	printf("Poly 2:");
	displayPoly(poly2);
	printf("Answer:");
	displayPoly(ans);

}
