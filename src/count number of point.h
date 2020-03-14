#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include "line.h"
#include "circle.h"
//#include "point.h"

using namespace std;

class Calculate {
public:
    int calculate_line_line(Line l1, Line l2);
    int calculate_line_circle(Line l, Circle c);
    int calculate_circle_circle(Circle c1, Circle c2);
    //Point calculate_leftpoint(Line l);
    //Point calculate_rightpoint(Line l);
    //void calculate_line_line_allinsert(Line l, Line l1);
};