#include "Intersect.h"
#include <iostream>
using namespace std;
#define ll long long
const int MAX_XY = 100000;
const int MIN_XY = -100000;
double arg(double x, double y) 
{
    return atan2(y, x);
}
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
    if ((l1.A * l2.B == l1.B * l2.A) && (l1.A * l2.C != l2.A * l1.C)) {//平行但不重合
        return 0;
    }
    else if ((l1.A * l2.B == l1.B * l2.A) && (l1.A * l2.C == l2.A * l1.C)) {
        if (l1.type == 1) {
            if (l2.type == 1) {
                if (l1.x1 == l2.x1 && l1.y1 == l2.y1) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
            }
            else {
                if (l1.x1 == l2.x1 && l1.y1 == l2.y1) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
                else if (l1.x1 == l2.x2 && l1.y1 == l2.y2) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
            }
        }
        else {
            if (l2.type == 1) {
                if (l1.x1 == l2.x1 && l1.y1 == l2.y1) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
                else if (l1.x2 == l2.x1 && l1.y2 == l2.y1) {
                    point.x = l1.x2;
                    point.y = l1.y2;
                    Setpoint.insert(point);
                    return 1;
                }
            }
            else {
                if (l1.x1 == l2.x2 && l1.y1 == l2.y2) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
                else if (l1.x2 == l2.x1 && l1.y2 == l2.y1) {
                    point.x = l1.x2;
                    point.y = l1.y2;
                    Setpoint.insert(point);
                    return 1;
                }
            }
        }
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
            if (l.type == 0) {
                Setpoint.insert(point1);
                return 1;
            }
            else if (l.type == 1) {
                if (is_on_ray(l, point1)) {
                    Setpoint.insert(point1);
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if (is_on_segment(l, point1)) {
                    Setpoint.insert(point1);
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else {//two result
            point1.y = sqrt(left) + c.n;
            point2.y = c.n - sqrt(left);
            if (l.type == 0) {
                Setpoint.insert(point1);
                Setpoint.insert(point2);
                return 2;
            }
            else if (l.type == 1) {
                int num = 0;
                if (is_on_ray(l, point1)) {
                    Setpoint.insert(point1);
                    num++;
                }
                if (is_on_ray(l, point2)) {
                    Setpoint.insert(point2);
                    num++;
                }
                return num;
            }
            else {
                int num = 0;
                if (is_on_segment(l, point1)) {
                    Setpoint.insert(point1);
                    num++;
                }
                if (is_on_segment(l, point2)) {
                    Setpoint.insert(point2);
                    num++;
                }
                return num;
            }
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
            if (l.type == 0) {
                Setpoint.insert(point1);
                Setpoint.insert(point2);
                return 2;
            }
            else if (l.type == 1) {
                int num = 0;
                if (is_on_ray(l, point1)) {
                    Setpoint.insert(point1);
                    num++;
                }
                if (is_on_ray(l, point2)) {
                    Setpoint.insert(point2);
                    num++;
                }
                return num;
            }
            else {
                int num = 0;
                if (is_on_segment(l, point1)) {
                    Setpoint.insert(point1);
                    num++;
                }
                if (is_on_segment(l, point2)) {
                    Setpoint.insert(point2);
                    num++;
                }
                return num;
            }
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = l.a * point1.x + l.b;
            if (l.type == 0) {
                Setpoint.insert(point1);
                return 1;
            }
            else if (l.type == 1) {
                if (is_on_ray(l, point1)) {
                    Setpoint.insert(point1);
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if (is_on_segment(l, point1)) {
                    Setpoint.insert(point1);
                    return 1;
                }
                else {
                    return 0;
                }
            }
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
    double norm = ((double)c1.m - c2.m) * ((double)c1.m - c2.m) + ((double)c1.n - c2.n) * ((double)c1.n - c2.n);
    double d = sqrt(norm);
    if (d > ((double)c1.r + c2.r)) {
        return 0;
    }
    if (d < (fabs((double)c1.r - c2.r))) {
        return 0;
    }
    double a = acos(((double)c1.r * c1.r + d * d - (double)c2.r * c2.r) / ((double)2 * c1.r * d));
    double t = arg((double)c2.m - c1.m, (double)c2.n - c1.n);
    point1.x = c1.m + cos(t + a) * c1.r;
    point1.y = c1.n + sin(t + a) * c1.r;
    if (a == 0) {
        Setpoint.insert(point1);
        return 1;
    }
    else {
        point2.x = c1.m + cos(t - a) * c1.r;
        point2.y = c1.n + sin(t - a) * c1.r;
        Setpoint.insert(point1);
        Setpoint.insert(point2);
        return 2;
    }
}

void Intersect::readdata(const char* name)
{
    FILE* stream;
    freopen_s(&stream, name, "r", stdin);
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

void Intersect::insertLine(int x1, int y1, int x2, int y2, char type) {
    Line l(x1, y1, x2, y2, type);
    //检查异常
    lineset.push_back(l);
}

void Intersect::insertLine(Line l) {
    //检查异常
    lineset.push_back(l);
}

int Intersect::deleteLine(int x1, int y1, int x2, int y2, char type) {
    vector<Line>::iterator it;
    Line l1(x1, y1, x2, y2, type);
    for (it = lineset.begin(); it != lineset.end(); it++) {
        Line l2 = *it;
        if (l1.equal(l2)) {
            lineset.erase(it);
            return 0;
        }
    }
    return 1;
}

int Intersect::deleteLine(Line l) {
    vector<Line>::iterator it;
    for (it = lineset.begin(); it != lineset.end(); it++) {
        Line l2 = *it;
        if (l.equal(l2)) {
            lineset.erase(it);
            return 0;
        }
    }
    return 1;
}

void Intersect::insertCircle(int x, int y, int r) {
    Circle c(x, y, r);
    //检查异常
    circleset.push_back(c);
}

void Intersect::insertCircle(Circle c) {
    //检查异常
    circleset.push_back(c);
}

int Intersect::deleteCircle(int x, int y, int r) {
    vector<Circle>::iterator it;
    Circle c1(x, y, r);
    for (it = circleset.begin(); it != circleset.end(); it++) {
        Circle c2 = *it;
        if (c1.equal(c2)) {
            circleset.erase(it);
            return 0;
        }
    }
    return 1;
}

int Intersect::deleteCircle(Circle c) {
    vector<Circle>::iterator it;
    for (it = circleset.begin(); it != circleset.end(); it++) {
        Circle c2 = *it;
        if (c.equal(c2)) {
            circleset.erase(it);
            return 0;
        }
    }
    return 1;
}

vector<Line> Intersect::pullLine() {
    return lineset;
}

vector<Circle> Intersect::pullCircle() {
    return circleset;
}

vector<pair<double, double>> Intersect::pullIntersect() {
    set<crosspoint, cmp>::iterator it;
    vector<pair<double, double>> point;
    double x, y;
    for (it = Setpoint.begin(); it != Setpoint.end(); it++) {
        crosspoint p = *it;
        x = p.x;
        y = p.y;
        pair<double, double> pp(x, y);
        point.push_back(pp);
    }
    return point;
}