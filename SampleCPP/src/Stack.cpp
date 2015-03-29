#include"Stack.h"
using namespace std;

void Stack::Link::initialize(void *data,Link *next)
{
	this->data=data;
	this->next=next;
}

void Stack::initialize()
{
	head=0;
}

void Stack::push(void *data)
{
	Link *newLink=new Link;
	newLink->initialize(data,head);
	head=newLink;
}

void *Stack::peek()
{
	if(head!=0)
		return head->data;
}

void *Stack::pop()
{
	if(head==0)
		return 0;
	void *result=head->data;
	Link *oldHead=head;
	head=head->next;
	delete oldHead;
	return result;
}

void Stack::cleanup()
{
	
}
