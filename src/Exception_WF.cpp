#include "Exception_WF.h"
using namespace std;

const char* Exception_WF::what(int n, int type)const throw() 
{
	if (type == 0 && n == 1) {//ÕûÐÎ´íÎó
		return "Wrong Format!This possition need a INT type\n";
	}
	else if (type == 0 && n == 3) {
		return "Wrong Format!This possition need three INT type\n";
	}
	else if (type == 0 && n == 4) {
		return "Wrong Format!This possition need four INT type\n";
	}
	else if (type == 1) {
		return "Wrong Format!This possition need a CHAR type\n";
	}
	else {
		return "Wrong Format!Type must be 'S','R','L','C'\n";
	}
}
