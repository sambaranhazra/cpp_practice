#include<stdio.h>
void go_south_east(int * lat, int * lon)
{
	(*lat)--;
	(*lon)++;
}

int main()
{
	int latitude=31;
	int longitude=35;

	go_south_east(&latitude,&longitude);
	printf("The location is : %d,%d\n",latitude,longitude);
	char name[]="Sambaran";
	puts(name);
	
	name[3]='k';
	puts(name);
	return 0;
}
