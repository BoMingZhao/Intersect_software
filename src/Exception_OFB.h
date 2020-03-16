#pragma once
#include<exception>  
#include<iostream>
#include<string>
using namespace std;

class Exception_OFB :public exception
{
public:
	const char* what(int type)const throw();
};

