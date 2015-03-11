#include<stdio.h>
void check_size(char msg[])
{
	int i=0;
	
	while(*(msg+i)!='\0')
		i++;
	printf("The size of %s is %i",msg,i);		
}
int main()
{
	char name[20];
	printf("Enter your name:\n");
	fgets(name,20,stdin);
	printf("Hello ");
	puts(name);
/*	char p[]="ABCF";
	p[2]='D';
	puts(p);
	printf("Size of %s in main is %d",p,sizeof(p));
//	printf("%d",sizeof("ABDF"));*/
	check_size("XYZABC");
	return 0;
}
