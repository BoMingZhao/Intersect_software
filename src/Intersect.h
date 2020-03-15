#pragma once
#include <set>
#include <vector>
#include <math.h>
#include "line.h"
#include "circle.h"
using namespace std;

class Intersect
{
public:
	void readdata();
	int result();
	void calculate();
//private:
	int calculate_line_line(Line l1, Line l2);
	int calculate_line_circle(Line l, Circle c);
	int calculate_circle_circle(Circle c1, Circle c2);
};

