#pragma once
#include <set>
#include <vector>
#include <math.h>
#include <string>
#include "line.h"
#include "circle.h"
using namespace std;

class Intersect
{
public:
	void readdata(const char* name);
	int result();
	void calculate();
	void insertLine(int x1, int y1, int x2, int y2, char type);
	void insertLine(Line l);
	int deleteLine(int x1, int y1, int x2, int y2, char type);//0É¾³ý 1³ö´í
	int deleteLine(Line l);
	void insertCircle(int x, int y, int r);
	void insertCircle(Circle c);
	int deleteCircle(int x, int y, int r);
	int deleteCircle(Circle c);
	vector<Line> pullLine();
	vector<Circle> pullCircle();
	vector<pair<double, double>> pullIntersect();
//private:
	int calculate_line_line(Line l1, Line l2);
	int calculate_line_circle(Line l, Circle c);
	int calculate_circle_circle(Circle c1, Circle c2);
};

