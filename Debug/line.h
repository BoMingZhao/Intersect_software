#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Line {
public:
	double A, B, C;//ax+by+c = 0：
	int type;//0 直线 1 射线 2 线段
	int dirct = 0;//0 射线向右 1 射线向左 2 垂直向上 3垂直向下
	double x1, x2, y1, y2;//x1 左端点(射线的端点) x2 右端点 y1y2防止垂直直线情况
	double a, b, t;
	bool aNotExist;
	Line(int X1, int Y1, int X2, int Y2,char Type);
	bool equal(Line l);
};