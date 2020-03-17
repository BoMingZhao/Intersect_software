#pragma once
#include <set>
#include <vector>
#include <math.h>
#include <string>
#include "line.h"
#include "circle.h"
#include "Exception_WF.h"
#include "Exception_OFB.h"
#include "Exception_IP.h"
#include "Exception_MD.h"
using namespace std;

class __declspec(dllimport) Intersect
{
public:
	void clear();
	void readdata_File(const char* name);
	void readdata();
	int result();
	void calculate();
	void insertLine(int x1, int y1, int x2, int y2, char type);
	void insertLine(Line l);
	int deleteLine(int x1, int y1, int x2, int y2, char type);//0ɾ�� 1����
	int deleteLine(Line l);
	void insertCircle(int x, int y, int r);
	void insertCircle(Circle c);
	int deleteCircle(int x, int y, int r);
	int deleteCircle(Circle c);
	vector<Line> pullLine();
	vector<Circle> pullCircle();
	vector<pair<double, double>> pullIntersect();
	//private:
	bool checkCircle(Circle c);
	bool checkLine(Line l);
	int calculate_line_line(Line l1, Line l2);
	int calculate_line_circle(Line l, Circle c);
	int calculate_circle_circle(Circle c1, Circle c2);
};

