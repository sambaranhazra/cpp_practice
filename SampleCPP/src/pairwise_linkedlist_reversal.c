#include<stdio.h>
#include<stdlib.h>



typedef struct link
{
	int data;
	struct link* next;
}link;

link *head;
link *new_list;

typedef struct pair
{
	int data[2];
	int tos;	
}stack;

stack *s;
void add(link **,int);
void display(link *);
void push(stack *s,int data)
{
	if(s->tos>1)
		return;
	s->data[++(s->tos)]=data;
//	printf("%d---%d",s->tos,data);
}

int pop(stack *s)
{
	if(s->tos<0)
		return -1;
//	printf("%d",s->tos);
	return s->data[(s->tos)--];
}

void reverse_pairwise(link **head,stack *s,link **new_list)
{
	s=malloc(sizeof(stack));
	s->tos=-1;
	link *current=*head;
	int first,second;
	int secondPresent=0;	
	while((*head)!=NULL)
	{
		if(*head!=NULL)	
			first=remove_from_linked_list(head);
		if(*head!=NULL)
		{
			second=remove_from_linked_list(head);
			secondPresent=1;
		}
//		printf("first: %d,Second: %d\n",first,second);
		push(s,first);
		push(s,second);
		if(!secondPresent)
			pop(s);
		else
			add(new_list,pop(s));
		add(new_list,pop(s));
		secondPresent=0;
		//*head=(*head)->next;
	}
}

void add(link** head,int data)
{
	if(*head==NULL)
	{
		*head=malloc(sizeof(link));
		(*head)->data=data;
		(*head)->next=NULL;
	}
	else
	{
		
		link *new=malloc(sizeof(link));
		new->data=data;
		new->next=NULL;
		link *current;
		current=*head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=new;
	}
	
}

void display(link *head)
{
	link *current;
	current=head;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	printf("NULL\n");
}

int remove_from_linked_list(link **head)
{
	if((*head)->next==NULL)
	{
		int value=(*head)->data;
		(*head)=NULL;
		return value;
	}
	link *removed_node=*head;
	int data=removed_node->data;
	if((*head)->next!=NULL)
		(*head)=(*head)->next;
	removed_node->next=NULL;
	return data;
}

int main()
{
	int data[]={1,4,3,5,2,6,7,4,2,100};
	int i;
	for(i=0;i<sizeof(data)/sizeof(int);i++)
		add(&head,data[i]);
	puts("Original List: ");
	display(head);
	puts("New list: ");
	reverse_pairwise(&head,s,&new_list);
	display(new_list);
}
