#include<stdio.h>
int main()
{
	char name[100];
	printf("Enter your name:\n");
	fgets(name,sizeof(name),stdin);
	printf("Hello ");
	puts(name);
	return 0;
}
