#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string word,input;
	int count=0;
	cout<<"Enter the word:"<<endl;
	cin>>word;
	ifstream ip("order_pizza.c");
	while(ip>>input)
	{
		if(input==word)
			count++;
	}
	if(count==0)
	cout<<"The word is not present"<<endl;
	else
	cout<<"The word is present "<<count<<" time(s)"<<endl;
}
