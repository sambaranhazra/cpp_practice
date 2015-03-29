#include"Stack.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		cout<<"Enter File Name"<<endl;
		return 1;
	}
	ifstream in(argv[1]);
	Stack textlines;
	textlines.initialize();
	string line;
	while(getline(in,line))
	{
		textlines.push(new string(line));
	}

	string *s;
	while((s=(string *)textlines.pop())!=0)
	{
		cout<<*s<<endl;
		delete s;
	}
	textlines.cleanup();
}

