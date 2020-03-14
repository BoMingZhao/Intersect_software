#pragma once
#include <vector>
#include <iostream>
#include <string> 
#include "line.h"
using namespace std;

class Point {
public:
	double x, y;//���������
	int type;//1 ��˵㣻2 �Ҷ˵㣻3 ����
	Line belong;//����ֱ��
	Line father1, father2;//���������ֱ�� 1������������2����������
	Point(double a, double b, int c, Line l1, Line l2);//���ڶ��彻��
	Point(double a, double b, int c, Line l);//���ڶ������Ҷ˵�
	bool operator< (const Point& a);
	bool operator> (const Point& a);
	bool operator== (const Point& a);
	bool operator!= (const Point& a);
};