//============================================================================
// Name        : SampleCPP.cpp
// Author      : Sambaran Hazra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string name;
	cout<<"Enter your name:"<<endl;
	getline(cin,name);
	cout<<"Hello "<<name<<endl;
	cout<<"Length of name is "<<name.length();
	return 0;
}
