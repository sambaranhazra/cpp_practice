#include"CLib.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int main()
{
	Stash intStash,stringStash;
	int i;
	char *cp;
	ifstream in;
	string line;
	const int bufsize=80;
	intStash.initialize(sizeof(int));
	for(i=0;i<100;i++)
		intStash.add(&i);
	for(i=0;i<intStash.count();i++)
		cout<<"intStash.fetch( "<<i<<")="
		<< *(int*)intStash.fetch(i)
		<<endl;

	stringStash.initialize(sizeof(char)*bufsize);
	in.open("CLibTest.cpp");
	assert(in);
	while(getline(in,line))
		stringStash.add(line.c_str());
	i=0;
	while((cp=(char*)stringStash.fetch(i++))!=0)
		cout<<"stringStashfetch("<<i<<")="
		<<cp<<endl;
	intStash.cleanup();
	stringStash.cleanup();
}


