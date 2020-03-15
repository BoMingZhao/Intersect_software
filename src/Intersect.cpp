#include "Intersect.h"
#include <iostream>
using namespace std;
#define ll long long
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
    crosspoint point1;
    crosspoint point2;
    if (l.aNotExist) {
        point1.x = l.t;
        point2.x = l.t;
        double k = ((double)l.t - c.m) * ((double)l.t - c.m);
        double r2 = (double)c.r * c.r;
        double left = r2 - k;
        if (left < 0) {//no result
            return 0;
        }
        else if (left == 0) {//one result
            point1.y = c.n;
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            Setpoint.insert(point1);
            return 1;
        }
        else {//two result
            point1.y = sqrt(left) + c.n;
            point2.y = c.n - sqrt(left);
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            //pointmap.insert(pair<crosspoint, int>(point2, 1));
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
    }
    else {//ax^2+bx+t=0
        double a = l.a * l.a + 1;
        double b = 2 * ((l.b - c.n) * l.a - c.m);
        double t = (double)c.m * c.m + (l.b - c.n) * (l.b - c.n) - (double)c.r * c.r;
        double deta = b * b - 4 * a * t;
        if (deta > 0) {
            point1.x = (sqrt(deta) - b) / (2 * a);
            point2.x = (-1 * sqrt(deta) - b) / (2 * a);
            point1.y = l.a * point1.x + l.b;
            point2.y = l.a * point2.x + l.b;
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            //pointmap.insert(pair<crosspoint, int>(point2, 1));
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = l.a * point1.x + l.b;
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            Setpoint.insert(point1);
            return 1;
        }
        else {
            return 0;
        }
    }
}

int Intersect::calculate_circle_circle(Circle c1, Circle c2)
{
    crosspoint point1;
    crosspoint point2;
    if (c2.n == c1.n && c2.m == c1.m) {
        return 0;
    }
    else if (c2.n == c1.n) {
        double temp = ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r)
            / ((double)2 * ((double)c2.m - c1.m));
        point1.x = temp;
        point2.x = temp;
        double left = (double)c1.r * c1.r - (temp - c1.m) * (temp - c1.m);
        if (left > 0) {
            point1.y = sqrt(left) + c1.n;
            point2.y = c1.n - sqrt(left);
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
        else if (left == 0) {
            point1.y = c1.n;
            Setpoint.insert(point1);
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        double k = ((double)c1.m - c2.m) / ((double)c2.n - c1.n);
        double temp = ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r)
            / ((double)2 * ((double)c2.n - c1.n));
        double a = 1 + k * k;
        double b = 2 * (k * temp - c1.n * k - c1.m);
        double c = (double)c1.m * c1.m + (double)c1.n * c1.n - (double)c1.r * c1.r + temp * temp - 2 * temp * c1.n;
        double deta = b * b - 4 * a * c;
        if (deta > 0) {
            point1.x = (sqrt(deta) - b) / (2 * a);
            point2.x = (-1 * sqrt(deta) - b) / (2 * a);
            point1.y = point1.x * k + temp;
            point2.y = point2.x * k + temp;
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = point1.x * k + temp;
            Setpoint.insert(point1);
            return 1;
        }
        else {
            return 0;
        }
    }
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
        /*if (scanf_s("%c", &type, 1) != 1) {
            //异常
        }*/
        cin >> type;
        if (type == 'L' || type == 'R' || type == 'S') {
            if (scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2) != 4) {
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