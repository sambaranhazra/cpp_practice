#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
int main()
{
	string input;
	vector<string> v;
	ifstream in("Readfile.cpp");
	while(in>>input)
	{
		v.push_back(input);
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
}
