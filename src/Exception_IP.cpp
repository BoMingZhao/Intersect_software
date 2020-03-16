#include "Exception_IP.h"
using namespace std;

const char* Exception_IP::what(int type)const throw() 
{
	if (type == 0) {
		return "Infinity Point!The addition of this line will create an infinite number of intersections\n";
	}
	else if (type == 1) {
		return "Infinity Point!The addition of this circle will create an infinite number of intersections\n";
	}
	else {
		return "";
	}
}