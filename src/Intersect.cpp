#include "Intersect.h"
#include <iostream>
using namespace std;
const int MAX_XY = 100000;
const int MIN_XY = -100000;
typedef struct {
    double x;
    double y;
}crosspoint;
bool operator< (const crosspoint& a, const crosspoint& b) {
    if (a.x == b.x && a.y == b.y) {
        return false;
    }
    else if (a.x != b.x) {
        return a.x < b.x;
    }
    else {
        return a.y < b.y;
    }

}
struct cmp {
    bool operator() (const crosspoint& a, const crosspoint& b) const {
        if (a.x == b.x) {
            if (a.y == b.y) {
                return false;
            }
            else if (a.y > b.y) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return a.x > b.x;
        }
    }
};

vector<Line> lineset;
vector<Circle> circleset;
set<crosspoint, cmp> Setpoint;

bool is_on_ray(Line l, crosspoint point)
{//直线和射线的交点问题
    if (l.dirct == 0) {
        if (point.x >= l.x1) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (l.dirct == 1) {
        if (point.x <= l.x1) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (l.dirct == 2) {
        if (point.y >= l.y1) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (point.y <= l.y1) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool is_on_segment(Line l, crosspoint point)
{//直线和线段的交点问题
    if (l.x1 == l.x2) {
        if (point.y >= l.y1 && point.y <= l.y2) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (point.x >= l.x1 && point.x <= l.x2) {
            return true;
        }
        else {
            return false;
        }
    }
}


int Intersect::calculate_line_line(Line l1, Line l2) 
{//caculate the crosspoint of the two lines 
    //int is eazy to test
    crosspoint point;
    if (l1.A * l2.B == l1.B * l2.A) {
        return 0;
    }
    else {
        point.y = (l1.A * l2.C - l1.C * l2.A) / (l1.B * l2.A - l1.A * l2.B);
        if (l1.A == 0) {
            point.x = (-l2.C - point.y * l2.B) / l2.A;
        }
        else {
            point.x = (-l1.C - point.y * l1.B) / l1.A;
        }
        //线段，射线特判
        if (l1.type == 0 && l2.type == 0) {
            Setpoint.insert(point);
            return 1;
        }
        else if (l1.type == 0 && l2.type == 1) {
            if (is_on_ray(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 0 && l2.type == 2) {
            if (is_on_segment(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 1 && l2.type == 0) {
            if (is_on_ray(l1, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 1 && l2.type == 1) {
            if (is_on_ray(l1, point) && is_on_ray(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 1 && l2.type == 2) {
            if (is_on_ray(l1, point) && is_on_segment(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 2 && l2.type == 0) {
            if (is_on_segment(l1, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (l1.type == 2 && l2.type == 1) {
            if (is_on_segment(l1, point) && is_on_ray(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            if (is_on_segment(l1, point) && is_on_segment(l2, point)) {
                Setpoint.insert(point);
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int Intersect::calculate_line_circle(Line l, Circle c)
{

}

int Intersect::calculate_circle_circle(Circle c1, Circle c2)
{


}

void Intersect::readdata()
{
    int n;
    char type;
    int x1, x2, y1, y2;
    int x, y, r;
    if (scanf_s("%d", &n) != 1) {
        //异常
    }
    for (int i = 1; i <= n; i++) {
        if (scanf_s("%c", &type, 1) != 1) {
            //异常
        }
        if (type == 'L' || type == 'R' || type == 'S') {
            if (scanf_s("%d%d%d%d", &x1, &x2, &y1, &y2) != 4) {
                //异常
            }
            if (x1 == x2 && y1 == y2) {
                //异常
            }
            if (x1 >= MAX_XY || x2 >= MAX_XY || y1 >= MAX_XY || y2 >= MAX_XY || x1 <= MIN_XY || x2 <= MIN_XY || y1 <= MIN_XY || y2 <= MIN_XY) {
                //异常
            }
            Line l(x1, y1, x2, y2, type);
            //检查是否有无数点问题
            lineset.push_back(l);
        }
        else if (type == 'C') {
            if (scanf_s("%d%d%d", &x, &y, &r) != 3) {
                //异常
            }
            if (x >= MAX_XY || y >= MAX_XY || x <= MIN_XY || y <= MIN_XY) {
                //异常
            }
            Circle c(x, y, r);
            //检查是否有无数点问题
            circleset.push_back(c);
        }
        else {
            //异常
        }
    }
}

void Intersect::calculate() 
{
    for (unsigned int i = 1; i < lineset.size(); i++) {
        for (unsigned int j = i + 1; j <= lineset.size(); j++) {
            Line l1 = lineset[i - 1];
            Line l2 = lineset[j - 1];
            calculate_line_line(l1, l2);
        }
    }
    for (unsigned int i = 1; i <= lineset.size(); i++) {
        for (unsigned int j = 1; j <= circleset.size(); j++) {
            Line l = lineset[i - 1];
            Circle c = circleset[j - 1];
            calculate_line_circle(l, c);
        }
    }
    for (unsigned int i = 1; i < circleset.size(); i++) {
        for (unsigned int j = i + 1; j <= circleset.size(); j++) {
            Circle c1 = circleset[i - 1];
            Circle c2 = circleset[j - 1];
            calculate_circle_circle(c1, c2);
        }
    }
}

int Intersect::result() 
{
    return Setpoint.size();
}