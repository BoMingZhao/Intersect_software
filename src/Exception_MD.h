#pragma once
#include<exception>  
#include<iostream>
#include<string>
using namespace std;

class Exception_MD :public exception
{
public:
	const char* what()const throw();
};

