#pragma once
#include <vector>
#include <iostream>
#include <string> 
#include "line.h"
using namespace std;

class Point {
public:
	double x, y;//本点的坐标
	int type;//1 左端点；2 右端点；3 交点
	Line belong;//所属直线
	Line father1, father2;//交点的两条直线 1是上面那条，2是下面那条
	Point(double a, double b, int c, Line l1, Line l2);//用于定义交点
	Point(double a, double b, int c, Line l);//用于定义左右端点
	bool operator< (const Point& a);
	bool operator> (const Point& a);
	bool operator== (const Point& a);
	bool operator!= (const Point& a);
};