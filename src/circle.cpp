#include "circle.h"
using namespace std;

Circle::Circle(int a, int b, int c) {
	m = a;
	n = b;
	r = c;
}

bool Circle::equal(Circle c) {
	if (this->m == c.m && this->n == c.n && this->r == c.r) {
		return true;
	}
	else {
		return false;
	}
}