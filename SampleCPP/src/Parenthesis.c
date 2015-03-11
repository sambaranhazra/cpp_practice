#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
} node;

void push(node **,int data,int *noOfElements);
int pop(node **,int *noOfElements);

int main()
{
	node *link=NULL;
	int noOfElements=0;
	int c=getchar();
	while(c!=EOF)
	{
		
//		printf("Entered Char %d\n",c);
		if((c<40 || c>41))
		{
		//	printf("Undefined");
		//	return -1;
		}
		else if(c=='(')
			push(&link,c,&noOfElements);
		else
			pop(&link,&noOfElements);
//		putchar(c);
		c=getchar();
	}
	printf("No Of Elements %d",noOfElements);
	if(noOfElements>0)
	{
		printf("The String is not valid");
	}	
}

void push(node **link,int data,int *noOfElements)
{
	printf("\nIn push()");
	node *newNode=(node *) malloc(sizeof(node));	
	if (newNode==NULL)
	{
		printf("StackOverflow");
		return;
	}
	newNode->value=data;
	newNode->next=NULL;
	(*noOfElements)++;
	if(*link==NULL)
	{
		*link=newNode;
	}
	else
	{
		newNode->next=*link;
		*link=newNode;
	}
	
}

int pop(node **link,int *noOfElements)
{
	printf("\nIn pop()");
	node *deletedNode;
	int poppedData;
	if(*noOfElements==0)
	{
		printf("Stack Underflow");
		return;
	}
	deletedNode=*link;
	poppedData=deletedNode->value;
	*link=(*link)->next;
	free(deletedNode);
	(*noOfElements)--;
	return poppedData;
}
