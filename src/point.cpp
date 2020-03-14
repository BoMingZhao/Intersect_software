#include <vector>
#include <iostream>
#include <string> 
#include "point.h"

using namespace std;

Point::Point(double a, double b, int c, Line l1, Line l2) {
	father1 = l1;
	father2 = l2;
	type = c;
	x = a;
	y = b;
}

Point::Point(double a, double b, int c, Line l) {
	type = c;
	x = a;
	y = b;
	belong = l;
}

bool Point::operator< (const Point& a) {
	if (this->x < a.x) {
		return true;
	}
	return false;
}

bool Point::operator> (const Point& a) {
	if (this->x > a.x) {
		return true;
	}
	return false;
}

bool Point::operator== (const Point& a) {
	if ((this->x == a.x) && (this->y == a.y)) {
		return true;
	}
	return false;
}

bool Point::operator!= (const Point& a) {
	if ((this->x != a.x) || (this->y != a.y)) {
		return true;
	}
	return false;
}