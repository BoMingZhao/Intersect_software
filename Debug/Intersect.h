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
	void readdata();
	void readdata_File(const char* name);
	int result();
	void calculate();
	int insertLine(int x1, int y1, int x2, int y2, char type);//0插入，非0出错
	int deleteLine(int x1, int y1, int x2, int y2, char type);//0删除 1出错
	int insertCircle(int x, int y, int r);
	int deleteCircle(int x, int y, int r);
	vector<pair<double, double>> pullIntersect();
	vector<vector<int>> pullgraph();
	//private:
	bool checkCircle(Circle c);
	bool checkLine(Line l);
	int calculate_line_line(Line l1, Line l2);
	int calculate_line_circle(Line l, Circle c);
	int calculate_circle_circle(Circle c1, Circle c2);
};

