#pragma once
#include <set>
#include <vector>
#include "line.h"
#include "circle.h"
class Intersect
{
private:
	int calculate_line_line(Line l1, Line l2);
	int calculate_line_circle(Line l, Circle c);
	int calculate_circle_circle(Circle c1, Circle c2);
public:
	void readdata();
	int result();
	void calculate();
};

