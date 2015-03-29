#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string data;
	int count=0;
	ifstream in("CalculateArea.cpp");
	while(in>>data)
		count++;

	cout<<"The no of words is: "<<count<<endl;
}
