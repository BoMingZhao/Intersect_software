#include "Exception_OFB.h"

const char* Exception_OFB::what(int type)const throw() 
{
	if (type == 0) {
		return "Out Of Bounds!The maximum value of the coordinates is 100000\n";
	}
	else if (type == 1) {
		return "Out Of Bounds!The minimum value of the coordinates is -100000\n";
	}
	else if (type == 2) {
		return "Out Of Bounds!The maximum value of the parameter is 100000\n";
	}
	else if (type == 3) {
		return "Out Of Bounds!The minimum value of the parameter is -100000\n";
	}
	else if (type == 4) {
		return "Out Of Bounds!The radius of the circle must be greater than 0\n";
	}
	else {
		return "";
	}
}
