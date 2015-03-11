#include<stdio.h>

int sum(int, int);
int multiply(int,int);
void print(int (*p)(int,int),int ,int);

int main()
{
	int a=2;
	int b=5;
	print(sum,a,b);
	print(multiply,a,b);
}

void print(int (*p)(int a,int b),int a,int b)
{
	
	printf("%d\n",p(a,b));
	
}

int multiply(int a, int b)
{
	return a*b;
}

int sum(int a, int b)
{
	return a+b;
}
