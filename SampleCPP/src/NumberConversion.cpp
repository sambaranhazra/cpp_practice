#include<iostream>

int main()
{
	std::cout<<"Enter a number"<<std::endl;
	int number;
	std::cin>>number;
	std::cout<<"The number in octal is 0"<<std::oct<<number<<std::endl;
	std::cout<<"The number in hexadecimal is 0x"<<std::hex<<number<<std::endl;

	return 0;
}
