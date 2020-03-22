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

void Intersect::clear()
{
    lineset.clear();
    circleset.clear();
    Setpoint.clear();
}

bool is_on_ray(Line l, crosspoint point)
{//射线的交点问题
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

bool Intersect::checkLine(Line l) {
    vector<Line>::iterator it;
    for (it = lineset.begin(); it != lineset.end(); it++) {
        Line l2 = *it;
        if (l.type == 0) {
            if ((l2.A * l.B == l2.B * l.A) && (l2.A * l.C == l.A * l2.C) && l2.A != 0 && l.A != 0) {
                return false;
            }
            else if ((l2.A * l.B == l2.B * l.A) && (l2.B * l.C == l.B * l2.C) && l2.B != 0 && l.B != 0) {
                return false;
            }
        }
        else if (l.type == 1) {//l是射线
            if ((l2.A * l.B == l2.B * l.A) && (l2.A * l.C == l.A * l2.C) && l2.A != 0 && l.A != 0) {//重合
                if (l2.type == 0) {//l2是直线
                    return false;
                }
                else if (l2.type == 1) {//l2是射线
                    if (l2.dirct == l.dirct) {
                        return false;
                    }
                    else if (l2.dirct==0) {
                        if (l2.x1 < l.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 1) {
                        if (l2.x1 > l.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 2) {
                        if (l2.y1 < l.y1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 3) {
                        if (l2.y1 > l.y1) {
                            return false;
                        }
                    }
                }
                else {
                    if (l.dirct == 0) {
                        if (l2.x2 > l.x1) {
                            return false;
                        }
                    }
                    else if (l.dirct == 1) {
                        if (l2.x1 < l.x1) {
                            return false;
                        }
                    }
                    else if (l.dirct == 2) {
                        if (l2.y2 > l.y1) {
                            return false;
                        }
                    }
                    else {
                        if (l2.y1 < l.y1) {
                            return false;
                        }
                    }
                }
            }
            else if ((l2.A * l.B == l2.B * l.A) && (l2.B * l.C == l.B * l2.C) && l2.B != 0 && l.B != 0) {
                if (l2.type == 0) {//l2是直线
                    return false;
                }
                else if (l2.type == 1) {//l2是射线
                    if (l2.dirct == l.dirct) {
                        return false;
                    }
                    else if (l2.dirct == 0) {
                        if (l2.x1 < l.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 1) {
                        if (l2.x1 > l.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 2) {
                        if (l2.y1 < l.y1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 3) {
                        if (l2.y1 > l.y1) {
                            return false;
                        }
                    }
                }
                else {
                    if (l.dirct == 0) {
                        if (l2.x2 > l.x1) {
                            return false;
                        }
                    }
                    else if (l.dirct == 1) {
                        if (l2.x1 < l.x1) {
                            return false;
                        }
                    }
                    else if (l.dirct == 2) {
                        if (l2.y2 > l.y1) {
                            return false;
                        }
                    }
                    else {
                        if (l2.y1 < l.y1) {
                            return false;
                        }
                    }
                }
            }
        }
        else {
            if ((l2.A * l.B == l2.B * l.A) && (l2.A * l.C == l.A * l2.C) && l2.A != 0 && l.A != 0) {
                if (l2.type == 0) {//l2是直线
                    return false;
                }
                else if (l2.type == 1) {
                    if (l2.dirct == 0) {
                        if (l.x2 > l2.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 1) {
                        if (l.x1 < l2.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 2) {
                        if (l.y2 > l2.y1) {
                            return false;
                        }
                    }
                    else {
                        if (l.y1 < l2.y1) {
                            return false;
                        }
                    }
                }
                else {
                    if (l.x1 != l.x2) {
                        if (l.x1 >= l2.x2 || l.x2 <= l2.x1) {
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        if (l.y1 >= l2.y2 || l.y2 <= l2.y1) {
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
            else if ((l2.A * l.B == l2.B * l.A) && (l2.B * l.C == l.B * l2.C) && l2.B != 0 && l.B != 0) {
                if (l2.type == 0) {//l2是直线
                    return false;
                }
                else if (l2.type == 1) {
                    if (l2.dirct == 0) {
                        if (l.x2 > l2.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 1) {
                        if (l.x1 < l2.x1) {
                            return false;
                        }
                    }
                    else if (l2.dirct == 2) {
                        if (l.y2 > l2.y1) {
                            return false;
                        }
                    }
                    else {
                        if (l.y1 < l2.y1) {
                            return false;
                        }
                    }
                }
                else {
                    if (l.x1 != l.x2) {
                        if (l.x1 >= l2.x2 || l.x2 <= l2.x1) {
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        if (l.y1 >= l2.y2 || l.y2 <= l2.y1) {
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Intersect::checkCircle(Circle c) {
    vector<Circle>::iterator it;
    for (it = circleset.begin(); it != circleset.end(); it++) {
        Circle c2 = *it;
        if (c.equal(c2)) {
            return false;
        }
    }
    return true;
}

int Intersect::calculate_line_line(Line l1, Line l2) 
{//caculate the crosspoint of the two lines 
    //int is eazy to test
    crosspoint point;
    if ((l1.A * l2.B == l1.B * l2.A) && (l1.A * l2.C != l2.A * l1.C) && l1.A != 0 && l2.A != 0) {//平行但不重合
        return 0;
    }
    else if ((l1.A * l2.B == l1.B * l2.A) && (l1.B * l2.C != l2.B * l1.C) && l1.B != 0 && l2.B != 0) {
        return 0;
    }
    else if ((l1.A * l2.B == l1.B * l2.A) && (l1.A * l2.C == l2.A * l1.C) && l1.A != 0 && l2.A != 0) {
        if (l1.type == 1) {
            if (l2.type == 1) {
                if (l1.x1 == l2.x1 && l1.y1 == l2.y1) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
                else {
                    return 0;
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
                else {
                    return 0;
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
                else {
                    return 0;
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
                else {
                    return 0;
                }
            }
        }
    }
    else if ((l1.A * l2.B == l1.B * l2.A) && (l1.B * l2.C != l2.B * l1.C) && l1.B != 0 && l2.B != 0) {
        if (l1.type == 1) {
            if (l2.type == 1) {
                if (l1.x1 == l2.x1 && l1.y1 == l2.y1) {
                    point.x = l1.x1;
                    point.y = l1.y1;
                    Setpoint.insert(point);
                    return 1;
                }
                else {
                    return 0;
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
                else {
                    return 0;
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
                else {
                    return 0;
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
                else {
                    return 0;
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

void Intersect::readdata()
{
    int n;
    char type;
    int x1, x2, y1, y2;
    int x, y, r;
    try {
        if (scanf_s("%d", &n) != 1) {
            throw Exception_WF();
        }
    }
    catch (Exception_WF & me)
    {
        cout << me.what(0, 1);
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 'L' || type == 'R' || type == 'S') {
            try {
                if (scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2) != 4) {
                    throw Exception_WF();
                }
            }
            catch (Exception_WF & me)
            {
                cout << me.what(0, 4);
                exit(0);
            }
            try {
                if (x1 == x2 && y1 == y2) {
                    throw Exception_MD();
                }
            }
            catch (Exception_MD & me)
            {
                cout << me.what();
                exit(0);
            }
            try {
                if (x1 >= MAX_XY || x2 >= MAX_XY || y1 >= MAX_XY || y2 >= MAX_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB & me)
            {
                cout << me.what(0);
                exit(0);
            }
            try {
                if (x1 <= MIN_XY || x2 <= MIN_XY || y1 <= MIN_XY || y2 <= MIN_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB & me)
            {
                cout << me.what(1);
                exit(0);
            }
            Line l(x1, y1, x2, y2, type);
            try {
                if (checkLine(l) == false) {
                    throw Exception_IP();
                }
            }
            catch (Exception_IP & me) 
            {
                cout << me.what(0);
                exit(0);
            }
            lineset.push_back(l);
        }
        else if (type == 'C') {
            try {
                if (scanf_s("%d%d%d", &x, &y, &r) != 3) {
                    throw Exception_WF();
                }
            }
            catch (Exception_WF & me)
            {
                cout << me.what(0, 3);
                exit(0);
            }
            try {
                if (x >= MAX_XY || y >= MAX_XY || r >= MAX_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB & me)
            {
                cout << me.what(2);
                exit(0);
            }
            try {
                if (x <= MIN_XY || y <= MIN_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB & me)
            {
                cout << me.what(3);
                exit(0);
            }
            try {
                if (r <= 0) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB & me)
            {
                cout << me.what(4);
                exit(0);
            }
            Circle c(x, y, r);
            try {
                if (checkCircle(c) == false) {
                    throw Exception_IP();
                }
            }
            catch (Exception_IP & me) 
            {
                cout << me.what(1);
                exit(0);
            }
            circleset.push_back(c);
        }
        else {
            try {
                throw Exception_WF();
            }
            catch (Exception_WF & me)
            {
                cout << me.what(2, 0);
                exit(0);
            }
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

int Intersect::insertgraph(string s)
{
    char type = 'a';
    unsigned int i = 0;
    int x1, y1, x2, y2, r;
    bool flag = false;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == '\n') {
            continue;
        }
        else if (s[i] == 'L' || s[i] == 'S' || s[i] == 'R' || s[i] == 'C') {
            type = s[i];
            break;
        }
        else {
            cout << "Wrong Format!Type must be 'S','R','L','C'" << endl;
            return 1;
        }
    }
    if (type == 'C') {
        int which = 1;
        int num = 0;
        int sub = 0;
        int error = 0;
        for (i = i + 1; i < s.size(); i++) {//第一个参数
            if (s[i] == ' ' || s[i] == '\n') {
                continue;
            }
            else if (s[i] == '-' && error == 0) {
                sub = 1;
                error = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                error = 1;
                int p = s[i] - '0';
                num += p;
                if (num >= MAX_XY) {//越界
                    cout << "Out Of Bounds!The maximum and minimum value of the coordinates is 100000 and -100000 and the radius must more than 0" << endl;
                    return 2;
                }
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num *= 10;
                }
                else {
                    if (sub == 1) {
                        num = (num == 0) ? 0 : -1 * num;
                    }
                    if (which == 1) {
                        x1 = num;
                        which++;
                    }
                    else if (which == 2) {
                        y1 = num;
                        which++;
                    }
                    else if (which == 3) {
                        r = num;
                        return insertCircle(x1, y1, r);
                    }
                    error = 0;
                    sub = 0;
                    num = 0;
                }
            }
            else {
                cout << "Wrong Format!This possition need three INT type" << endl;
                return 3;
            }
        }
    }
    else if (type == 'R' || type == 'L' || type == 'S') {
        int which = 1;
        int num = 0;
        int sub = 0;
        int error = 0;
        for (i = i + 1; i < s.size(); i++) {//第一个参数
            if (s[i] == ' ' || s[i] == '\n') {
                continue;
            }
            else if (s[i] == '-' && error == 0) {
                sub = 1;
                error = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                error = 1;
                int p = s[i] - '0';
                num += p;
                if (num >= MAX_XY) {//越界
                    cout << "Out Of Bounds!The maximum value of the coordinates is 100000 and The minimum value of the coordinates is -100000" << endl;
                    return 2;
                }
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num *= 10;
                }
                else {
                    if (sub == 1) {
                        num = (num == 0) ? 0 : -1 * num;
                    }
                    if (which == 1) {
                        x1 = num;
                        which++;
                    }
                    else if (which == 2) {
                        y1 = num;
                        which++;
                    }
                    else if (which == 3) {
                        x2 = num;
                        which++;
                    }
                    else if (which == 4) {
                        y2 = num;
                        return insertLine(x1, y1, x2, y2, type);
                    }
                    error = 0;
                    sub = 0;
                    num = 0;
                }
            }
            else {
                cout << "Wrong Format!This possition need four INT type" << endl;
                return 3;
            }
        }
    }
    else {
        cout << "Wrong Format!Type must be 'S','R','L','C'" << endl;
        return 1;
    }
    cout << "Wrong Format!Can't find enough parameter " << endl;
    return 5;
}

int Intersect::deletegraph(string s) {
    char type = 'a';
    unsigned int i = 0;
    int x1, y1, x2, y2, r;
    bool flag = false;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == '\n') {
            continue;
        }
        else if (s[i] == 'L' || s[i] == 'S' || s[i] == 'R' || s[i] == 'C') {
            type = s[i];
            break;
        }
        else {
            cout << "Wrong Format!Type must be 'S','R','L','C'" << endl;
            return 1;
        }
    }
    if (type == 'C') {
        int which = 1;
        int num = 0;
        int sub = 0;
        int error = 0;
        for (i = i + 1; i < s.size(); i++) {//第一个参数
            if (s[i] == ' ' || s[i] == '\n') {
                continue;
            }
            else if (s[i] == '-' && error == 0) {
                sub = 1;
                error = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                error = 1;
                int p = s[i] - '0';
                num += p;
                if (num >= MAX_XY) {//越界
                    cout << "Out Of Bounds!The maximum and minimum value of the coordinates is 100000 and -100000 and the radius must more than 0" << endl;
                    return 2;
                }
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num *= 10;
                }
                else {
                    if (sub == 1) {
                        num = (num == 0) ? 0 : -1 * num;
                    }
                    if (which == 1) {
                        x1 = num;
                        which++;
                    }
                    else if (which == 2) {
                        y1 = num;
                        which++;
                    }
                    else if (which == 3) {
                        r = num;
                        return deleteCircle(x1, y1, r);
                    }
                    error = 0;
                    sub = 0;
                    num = 0;
                }
            }
            else {
                cout << "Wrong Format!This possition need three INT type" << endl;
                return 3;
            }
        }
    }
    else if (type == 'R' || type == 'L' || type == 'S') {
        int which = 1;
        int num = 0;
        int sub = 0;
        int error = 0;
        for (i = i + 1; i < s.size(); i++) {//第一个参数
            if (s[i] == ' ' || s[i] == '\n') {
                continue;
            }
            else if (s[i] == '-' && error == 0) {
                sub = 1;
                error = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                error = 1;
                int p = s[i] - '0';
                num += p;
                if (num >= MAX_XY) {//越界
                    cout << "Out Of Bounds!The maximum value of the coordinates is 100000 and The minimum value of the coordinates is -100000" << endl;
                    return 2;
                }
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num *= 10;
                }
                else {
                    if (sub == 1) {
                        num = (num == 0) ? 0 : -1 * num;
                    }
                    if (which == 1) {
                        x1 = num;
                        which++;
                    }
                    else if (which == 2) {
                        y1 = num;
                        which++;
                    }
                    else if (which == 3) {
                        x2 = num;
                        which++;
                    }
                    else if (which == 4) {
                        y2 = num;
                        return deleteLine(x1, y1, x2, y2, type);
                    }
                    error = 0;
                    sub = 0;
                    num = 0;
                }
            }
            else {
                cout << "Wrong Format!This possition need four INT type" << endl;
                return 3;
            }
        }
    }
    else {
        cout << "Wrong Format!Type must be 'S','R','L','C'" << endl;
        return 1;
    }
    cout << "Wrong Format!Can't find enough parameter " << endl;
    return 5;
}

int Intersect::insertLine(int x1, int y1, int x2, int y2, char type) {
    try {
        if (type != 'R' && type != 'L' && type != 'S') {
            throw Exception_WF();
        }
    }
    catch (Exception_WF & me)
    {
        me.what(1,2);
        cout << "Wrong Format!Type must be 'S','R','L'\n";
        return 5;
    }
    try {
        if (x1 == x2 && y1 == y2) {
            throw Exception_MD();
        }
    }
    catch (Exception_MD & me)
    {
        cout << me.what();
        return 1;
    }
    try {
        if (x1 >= MAX_XY || x2 >= MAX_XY || y1 >= MAX_XY || y2 >= MAX_XY) {
            throw Exception_OFB();
        }
    }
    catch (Exception_OFB & me)
    {
        cout << me.what(0);
        return 2;
    }
    try {
        if (x1 <= MIN_XY || x2 <= MIN_XY || y1 <= MIN_XY || y2 <= MIN_XY) {
            throw Exception_OFB();
        }
    }
    catch (Exception_OFB & me)
    {
        cout << me.what(1);
        return 3;
    }
    Line l(x1, y1, x2, y2, type);
    try {
        if (checkLine(l) == false) {
            throw Exception_IP();
        }
    }
    catch (Exception_IP & me) 
    {
        cout << me.what(0);
        return 4;
    }
    lineset.push_back(l);
    return 0;
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
    cout << "Can't find this graph!" << endl;
    return 6;
}

int Intersect::insertCircle(int x, int y, int r) {
    try {
        if (x >= MAX_XY || y >= MAX_XY || r >= MAX_XY) {
            throw Exception_OFB();
        }
    }
    catch (Exception_OFB & me)
    {
        cout << me.what(2);
        return 1;
    }
    try {
        if (x <= MIN_XY || y <= MIN_XY) {
            throw Exception_OFB();
        }
    }
    catch (Exception_OFB & me)
    {
        cout << me.what(3);
        return 2;
    }
    try {
        if (r <= 0) {
            throw Exception_OFB();
        }
    }
    catch (Exception_OFB & me)
    {
        cout << me.what(4);
        return 3;
    }
    Circle c(x, y, r);
    try {
        if (checkCircle(c) == false) {
            throw Exception_IP();
        }
    }
    catch (Exception_IP & me) {
        cout << me.what(1);
        return 4;
    }
    circleset.push_back(c);
    return 0;
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
    cout << "Can't find this graph!" << endl;
    return 6;
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

vector<vector<int>> Intersect::pullgraph() {
    vector<vector<int>> graph;
    for (unsigned int i = 0; i < lineset.size(); i++) {
        Line l = lineset.at(i);
        vector<int> t;
        t.push_back((int)l.x1);
        t.push_back((int)l.y1);
        t.push_back((int)l.x2);
        t.push_back((int)l.y2);
        t.push_back(l.type);
        graph.push_back(t);
    }
    for (unsigned int i = 0; i < circleset.size(); i++) {
        Circle c = circleset.at(i);
        vector<int> t;
        t.push_back(c.m);
        t.push_back(c.n);
        t.push_back(c.r);
        t.push_back(c.r);
        t.push_back((int)3);
        graph.push_back(t);
    }
    return graph;
}

void Intersect::readdata_File(const char* name)
{
    FILE* stream;
    freopen_s(&stream, name, "r", stdin);
    int n;
    char type;
    int x1, x2, y1, y2;
    int x, y, r;
    try {
        if (fscanf_s(stdin, "%d", &n) != 1) {
            throw Exception_WF();
        }
    }
    catch (Exception_WF& me)
    {
        cout << me.what(0, 1);
        cout << "请检查文件格式后重试" << endl;
        lineset.clear();
        circleset.clear();
        fclose(stdin);
        return;
    }
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 'L' || type == 'R' || type == 'S') {
            try {
                if (fscanf_s(stdin, "%d%d%d%d", &x1, &y1, &x2, &y2) != 4) {
                    throw Exception_WF();
                }
            }
            catch (Exception_WF& me)
            {
                cout << me.what(0, 4);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (x1 == x2 && y1 == y2) {
                    throw Exception_MD();
                }
            }
            catch (Exception_MD& me)
            {
                cout << me.what();
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (x1 >= MAX_XY || x2 >= MAX_XY || y1 >= MAX_XY || y2 >= MAX_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB& me)
            {
                cout << me.what(0);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (x1 <= MIN_XY || x2 <= MIN_XY || y1 <= MIN_XY || y2 <= MIN_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB& me)
            {
                cout << me.what(1);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            Line l(x1, y1, x2, y2, type);
            try {
                if (checkLine(l) == false) {
                    throw Exception_IP();
                }
            }
            catch (Exception_IP& me)
            {
                cout << me.what(0);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            lineset.push_back(l);
        }
        else if (type == 'C') {
            try {
                if (fscanf_s(stdin, "%d%d%d", &x, &y, &r) != 3) {
                    throw Exception_WF();
                }
            }
            catch (Exception_WF& me)
            {
                cout << me.what(0, 3);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (x >= MAX_XY || y >= MAX_XY || r >= MAX_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB& me)
            {
                cout << me.what(2);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (x <= MIN_XY || y <= MIN_XY) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB& me)
            {
                cout << me.what(3);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            try {
                if (r <= 0) {
                    throw Exception_OFB();
                }
            }
            catch (Exception_OFB& me)
            {
                cout << me.what(4);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            Circle c(x, y, r);
            try {
                if (checkCircle(c) == false) {
                    throw Exception_IP();
                }
            }
            catch (Exception_IP& me)
            {
                cout << me.what(1);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
            circleset.push_back(c);
        }
        else {
            try {
                throw Exception_WF();
            }
            catch (Exception_WF& me)
            {
                cout << me.what(2, 0);
                cout << "请检查文件格式后重试" << endl;
                lineset.clear();
                circleset.clear();
                fclose(stdin);
                return;
            }
        }
    }
    fclose(stdin);
}