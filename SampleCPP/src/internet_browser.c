
#include <stdio.h>
#include<string.h>

int jhool_browser(char *);
int main()
{
	int i=0;
    	int no_of_tc;
	char input[200];
	scanf("%d",&no_of_tc);
	getchar();
	for(i=0;i<no_of_tc;i++)
	{
		
		scanf("%199s",input);
		
		int no_of_modified_chars=jhool_browser(input);
		int original_chars=strlen(input);
		printf("%d/%d\n",no_of_modified_chars,original_chars);
	}
    	return 0;
}

int jhool_browser(char *input_url)
{
	char *original_url=input_url;
	int count_original=0;
	while(*input_url!='\0'){
		count_original++;
		input_url++;
	}
	int www_location=0;
	int com_location=0;
	int last_com_location;
	input_url=original_url;
	while(*input_url!='\0'){
		++www_location;
		if(*input_url=='.')
			break;
		input_url++;
	}
	
	input_url=original_url;
	while(*input_url!='\0'){
		++com_location;
		if(*input_url=='.')
			last_com_location=com_location;
			
		input_url++;
	}
	
	int chars_after_last_point=count_original-last_com_location;	
	input_url=original_url;
	char modified_url[200];
	int i=www_location;
	int j=0;
	for(i=www_location;i<last_com_location;i++,j++)
	{
		*(modified_url+j)=*(input_url+i);
//		printf("%c",*(modified_url+j));
	}
	*(modified_url+j)='\0';
	
	int count_modified=0;

	char *modified_url_ptr=modified_url;
	while(*modified_url_ptr!='\0')
	{
//		printf("%c",*modified_url_ptr);
		if((*modified_url_ptr != 'a') && (*modified_url_ptr != 'e') && (*modified_url_ptr != 'i') && (*modified_url_ptr != 'o') && (*modified_url_ptr != 'u')){
//		printf("%c",*modified_url_ptr);	
		count_modified++;
		}
		modified_url_ptr++;
	}
	count_modified+=chars_after_last_point;
	return count_modified;
}
