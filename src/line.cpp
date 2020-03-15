#include <stack>
#include <vector>
#include <iostream>
#include "line.h"
#include <string>
using namespace std;

Line::Line(int X1, int Y1, int X2, int Y2,char Type) {
	A = (double)Y2 - Y1;
	B = (double)X1 - (double)X2;
	C = (double)X2 * Y1 - (double)X1 * Y2;
	if (Type == 'L') {
		type = 0;
	}
	else if (Type == 'R') {
		type = 1;
		x1 = X1;
		y1 = Y1;
		dirct = ((X1 == X2) && (Y1 > Y2)) ? 3 : ((X1 == X2) && (Y1 < Y2)) ? 2 : (X1 > X2) ? 1 : 0;
	}
	else {
		type = 2;
		if (X1 == X2) {
			if (Y1 > Y2) {
				x1 = X2;
				x2 = X1;
				y1 = Y2;
				y2 = Y1;
			}
			else {
				x1 = X1;
				x2 = X2;
				y1 = Y1;
				y2 = Y2;
			}
		}
		else if (X1 > X2) {
			x1 = X2;
			x2 = X1;
			y1 = Y2;
			y2 = Y1;
		}
		else {
			x1 = X1;
			x2 = X2;
			y1 = Y1;
			y2 = Y2;
		}
	}
	if (X1 == X2) {
		aNotExist = true;
		t = X1;
		a = 0;//delete warning
		b = 0;//delete warning
	}
	else {
		aNotExist = false;
		a = ((double)Y1 - (double)Y2) / ((double)X1 - (double)X2);
		b = Y1 - a * X1;
		t = 0;//delete warning
	}
}
