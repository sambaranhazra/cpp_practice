#include<stdio.h>

int calculate_time(char *);
char *pattern[]={".,?!1","abc2","def3","ghi4","jkl5","mno6","pqrs7","tuv8","wxyz9","_0"};
int main(int argc,char *argv[])
{
	char data[1002];
	int no_of_input;
//	printf("Enter the input\n");
	scanf("%d",&no_of_input);
	getchar();
	int i=0;
	for(i=0;i<no_of_input;i++)
	{
		fgets(data,1002,stdin);
		int time=calculate_time(data);
//		puts(data);
		printf("%d\n",time);
	}
	return 0;
}

int calculate_time(char * input)
{
	int time=0;
	int i;
	int previous=0;
	while(*input!='\0')
	{
		for(i=0;i<10;i++)
		{
			int flag=0;
			char *string=pattern[i];
			int internal_count=0;
			while(*string!='\0')
			{
			//	int internal_count=1;
				if(*string==*input)
				{
//					printf("Charater Matched: %c\n",*string);
//					printf("Previous: %d\n",previous);
					time+=internal_count;
					time++;
					if(i!=previous)
						time++;
					previous=i;
					flag=1;
					break;
				}
				string++;
				internal_count++;
			//	printf("Internal Count:%d\n",internal_count);	
			}
			if(flag)
				break;
		}
		input++;
	}
	return time;
}
