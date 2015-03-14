#include<stdio.h>
#include<stdlib.h>

#define MAXLENGTH 2000000
int pairs( int data[],int length)
{
	long *counter_array;
	counter_array=malloc(MAXLENGTH*sizeof(int));
	//int count=0;
	int i=0;
	for(i=0;i<MAXLENGTH;i++)
		counter_array[i]=0;
	for(i=0;i<length;i++)
	{
		if(data[i]<0)
		{
//			printf("data[%d]",i);
//			printf("%d",data[i]);
			int num=MAXLENGTH+data[i]-1;
//			printf("%d\n",num);
			counter_array[num]++;
		}
		else
			counter_array[data[i]]++;
	}
	int count=0;
	for(i=0;i<MAXLENGTH;i++)
	{
		if(counter_array[i]>0)
		{
//			puts("calculating...");
			long  value=counter_array[i]+(counter_array[i]*(counter_array[i]-1))/2;

			count+=value;
		}

	}

	free(counter_array);
	return count;
}

int main()
{
	int no_of_tc,i;
	scanf("%d",&no_of_tc);
	for(i=0;i<no_of_tc;i++)
	{
		int no_of_elements;
		scanf("%d",&no_of_elements);
		int *data;
		data = malloc(no_of_elements*sizeof(int));
		int j;
		for(j=0;j<no_of_elements;j++)
		{
			scanf("%d",(data+j));
//			printf("%d",*(data+j));
		}

		/*	printf("%d\n",no_of_elements);
			
			long min=0;
			for(j=0;j<no_of_elements;j++)
			{
				printf("%d-> ",data[j]);
			}*/
			
			int pair=pairs(data,no_of_elements);
			printf("%d\n",pair);
		free(data);
	}
	return 0;
}
