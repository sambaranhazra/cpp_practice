#ifndef STACK_H
#define STACK_H

struct Stack
{
	struct Link
	{
		void *data;
		Link *next;
		void initialize(void *data,Link* next);
	}*head;
	
	void initialize();
	void push(void *data);
	void* pop();
	void* peek();
	void cleanup();
};

#endif
