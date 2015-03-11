#include<stdio.h>
#include<ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp;		/* next free position in buf */
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */

int getint(int *pn)
{
	int c, sign;
	while(isspace(c=getch()))	/* skip white space*/
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);	/* it's not a number */
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c=getch();
	for(*pn = 0; isdigit(c); c=getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}


int getch(void) /* get a possible pushed back character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch; too many characters\n");
	else
		buf[bufp++]=c;
}
int main()
{
	int arr[]={1,2,3};
	int value=getint(arr);	
	printf("\n%d",value);
}
