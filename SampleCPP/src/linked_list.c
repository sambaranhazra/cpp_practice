#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void add(struct node **,int );
void display(struct node *);
void remove_node(struct node**);
int main()
{
	struct node *head=NULL;
	//printf("Enter no of elements:");
	add(&head,5);
	display(head);
	add(&head,100);
	display(head);
	remove_node(&head);
	display(head);
	remove_node(&head);
	display(head);
}

void add(struct node **head,int data)
{
	struct node *pointer;
	struct node *new_node=malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=*head;
	*head=new_node;
}

void display(struct node *head)
{
	struct node *pointer=head;
	while(pointer!=NULL)
	{
		printf("%d->",pointer->data);
		pointer=pointer->next;
	}
	printf("NULL\n");
}

void remove_node(struct node **head)
{
	if(*head!=NULL){
	struct node *pointer=*head;
	*head=(*head)->next;
	free(pointer);
	}
}
