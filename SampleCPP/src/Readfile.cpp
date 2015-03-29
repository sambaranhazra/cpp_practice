#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	vector<string> v;
	string line;
	string file_name;
/*	cout<<"Enter the filename"<<endl;
	cin>>file_name;*/
	ifstream in("Readfile.cpp");
	if(in){	
	while(getline(in,line))
	{
		v.push_back(line);	
	}

	for(int i=v.size()-1;i>0;i--)
	{
		cout<<i<<": "<<v[i]<<endl;
	}
	}
}
