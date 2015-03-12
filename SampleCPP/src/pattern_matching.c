#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int matcher(char *pattern, char *text)
{
//	char original_text_array[100001];
//	original_text_array=strdup(text);
	char *original_text=text;
	int pattern_data[26];
	int text_data[26];
	int original_text_data[26];
	int pattern_length=strlen(pattern);
	int i;
	for(i=0;i<26;i++)
	{
		pattern_data[i]=0;
		text_data[i]=0;
		original_text_data[i]=0;
	}
	while(*pattern!='\0')
	{
		if(*pattern>='a' && *pattern<='z')
		{
			pattern_data[*pattern-'a']++;
			pattern++;
		}
		else
			return -1;
	}
	while(*text!='\0')
	{
		if(*text>='a' && *text<='z')
		{
			text_data[*text-'a']++;
			text++;
		}
		else
			return -1;
	}

	for(i=0;i<26;i++)
	{
//		printf("text_data[%d]->%d\tpattern_data[%d]->%d\n",i,text_data[i],i,pattern_data[i]);
		if(text_data[i]<pattern_data[i])
		{
			return 0;
		}
	}
	
	i=0;
	int flag;
	int first_time=1;
	int count=0;
	while(*(original_text)!='\0')
	{
//		printf("\nloop executed");
//		printf("%d",count);
		char c;
		flag=1;
		if(count<pattern_length)
		{
			original_text_data[*(original_text)-'a']++;
			count++;
		}
			
		else
		{
//			printf("Original Text\t%c\t%c\n",*original_text,c);
			original_text_data[*(original_text)-'a']++;
			original_text_data[c-'a']--;
	//		count--;
		}

		
		if(count==pattern_length)
		{
			for(i=0;i<26;i++)
			{
//				printf("%d\t%d\n",original_text_data[i],pattern_data[i]);
				if(original_text_data[i]!=pattern_data[i])
					flag=0;
			}
		
			if(flag)
				return 1;
		}
//		printf("%d-----%d\n",count,pattern_length);
	//	count++;
		if(count==pattern_length)
		{
//			puts(original_text);
//			printf("%d\n",pattern_length);
			c=*(original_text-pattern_length+1);
//			printf("Removed Char: %c\n",c);
		}
		original_text++;
		

	/*	for(i=0;i<26;i++)
			original_text_data[i]=0;*/
		
	}
	return 0;
}

int main()
{
	char no_of_tc[4];
	fgets(no_of_tc,sizeof(no_of_tc),stdin);
	int j=0;
	int no_of_testcase=atoi(no_of_tc);
	for(j=0;j<no_of_testcase;j++)
	{
		char pattern[1001];
		scanf("%1001s",pattern);
		char text[100001];
		scanf("%100001s",text);	
		int i=matcher(pattern,text);
		if(i)
			puts("YES");
		else
			puts("NO");
	}
}
