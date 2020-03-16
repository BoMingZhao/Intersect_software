#pragma once
#include<exception>  
#include<iostream>
#include<string>
using namespace std;

class Exception_WF :public exception
{
public:
    const char* what(int n,int type)const throw();
};

