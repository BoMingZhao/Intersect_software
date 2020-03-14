#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include "count number of point.h"
const double MAXN = 5000000000;
#define TEMP ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r) / ((double)2 * ((double)c2.m - c1.m))
using namespace std;

typedef struct{
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

/*struct cmp1 {
    bool operator() (Point a, Point b) {
        return a.x > b.x;
    }
};*/

struct cmp2 {
    bool operator() (const Line& a, const Line& b) const {
        if (a.y == b.y) {
            if (a.x == b.x) {
                double t1 = -a.A / a.B;
                double t2 = -b.A / b.B;
                return t1 > t2;
            }
            else {
                return a.x > b.x;
            }
        }
        else {
            return a.y > b.y;
        }
    }
};

/*struct cmp3 {
    bool operator() (const Point& a, const Point& b) const {
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
};*/

struct cmp4 {
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

typedef std::map<crosspoint, int> Map;
Map pointmap;
vector<Line> lineset;
vector<Circle> circleset;
//priority_queue <Point, vector<Point>, cmp1> q;//顶点的优先队列
//set<Line,cmp2> s;
//set<Point,cmp3> pointset;
set<crosspoint, cmp4> Setpoint;

int Calculate::calculate_line_line(Line l1,Line l2) {//caculate the crosspoint of the two lines 
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
        //pointmap.insert(pair<crosspoint, int>(point, 1));
        Setpoint.insert(point);
        return 1;
    }
}

int Calculate::calculate_line_circle(Line l, Circle c) {//caculate the crosspoint of the one line and one circle
    /*crosspoint point1;
    crosspoint point2;
    double a = l.A * l.A + l.B * l.B;
    double b = 2 * (l.B * l.A * c.n - l.B * l.B * c.m + l.A * l.C);
    double k = l.B * l.B * ((double)c.m * c.m + (double)c.n * c.n - (double)c.r * c.r) + l.C * l.C + 2 * l.B * l.C * c.n;
    double deta = b * b - 4 * a * k;
    if (deta > 0) {
        point1.x = (sqrt(deta) - b) / (2 * a);
        point2.x = (-1 * sqrt(deta) - b) / (2 * a);
        point1.y = (-l.C - l.A * point1.x) / l.B;
        point2.y = (-l.C - l.A * point2.x) / l.B;
        //pointmap.insert(pair<crosspoint, int>(point1, 1));
        //pointmap.insert(pair<crosspoint, int>(point2, 1));
        Setpoint.insert(point1);
        Setpoint.insert(point2);
        return 2;
    }
    else if (deta == 0) {
        point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
        point1.y = (-l.C - l.A * point1.x) / l.B;
        //pointmap.insert(pair<crosspoint, int>(point1, 1));
        Setpoint.insert(point1);
        return 1;
    }
    else {
        return 0;
    }*/
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

int Calculate::calculate_circle_circle(Circle c1, Circle c2) {//caculate the crosspoint of the two circles
    crosspoint point1;
    crosspoint point2;
    if (c2.n == c1.n && c2.m == c1.m) {
        return 0;
    }
    else if (c2.n == c1.n) {
        double temp = ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r)
            / ((double)2 * ((double)c2.m - c1.m));
        point1.x = TEMP;
        point2.x = TEMP;
        double left = (double)c1.r * c1.r - (TEMP - c1.m) * (TEMP - c1.m);
        if (left > 0) {
            point1.y = sqrt(left) + c1.n;
            point2.y = c1.n - sqrt(left);
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            //pointmap.insert(pair<crosspoint, int>(point2, 1));
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
        else if (left == 0) {
            point1.y = c1.n;
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
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
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            //pointmap.insert(pair<crosspoint, int>(point2, 1));
            Setpoint.insert(point1);
            Setpoint.insert(point2);
            return 2;
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = point1.x * k + temp;
            //pointmap.insert(pair<crosspoint, int>(point1, 1));
            Setpoint.insert(point1);
            return 1;
        }
        else {
            return 0;
        }
    }
}

/*Point Calculate::calculate_leftpoint(Line l) {
    double x, y;
    if (l.B == 0) {
        x = -l.C / l.A;
        y = -1 * MAXN;
    }
    else {
        double k = -l.A / l.B;
        if (k >= 1) {
            y = -1 * MAXN;
            x = (-l.B * y - l.C) / l.A;
        }
        else if (k <= -1) {
            y = MAXN;
            x = (-l.B * y - l.C) / l.A;
        }
        else {
            x = -1 * MAXN;
            y = (-l.A * x - l.C) / l.B;
        }
    }
    Point p(x, y, 1, l);
    return p;
}

Point Calculate::calculate_rightpoint(Line l) {
    double x, y;
    if (l.B == 0) {
        x = -l.C / l.A;
        y = MAXN;
    }
    else {
        double k = -l.A / l.B;
        if (k >= 1) {
            y = MAXN;
            x = (-l.B * y - l.C) / l.A;
        }
        else if (k <= -1) {
            y = -1 * MAXN;
            x = (-l.B * y - l.C) / l.A;
        }
        else {
            x = MAXN;
            y = (-l.A * x - l.C) / l.B;
        }
    }
    Point p(x, y, 2, l);
    return p;
}*/

/*void Calculate::calculate_line_line_allinsert(Line l1, Line l2) {
    //caculate the crosspoint of the two lines and insert the Intersect into the map 
    crosspoint point;
    if (l1.A * l2.B == l1.B * l2.A) {
        return;
    }
    else {
        point.y = (l1.A * l2.C - l1.C * l2.A) / (l1.B * l2.A - l1.A * l2.B);
        if (l1.A == 0) {
            point.x = (-l2.C - point.y * l2.B) / l2.A;
        }
        else {
            point.x = (-l1.C - point.y * l1.B) / l1.A;
        }
        Point p(point.x, point.y, 3, l1, l2);
        q.push(p);
        return;
    }
}*/

int main(int argc, char* argv[])
{
    FILE* stream;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'o') {
            freopen_s(&stream, argv[i + 1], "w", stdout);
        }
        if (argv[i][0] == '-' && argv[i][1] == 'i') {
            freopen_s(&stream, argv[i + 1], "r", stdin);
        }
    }
    int n;
    int x1, x2, y1, y2;
    int x, y, r;
    char type;
    cin >> n;
    Calculate calculate;
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 'L') { 
            scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
            Line l(x1, y1, x2, y2);
            /*Point pl = calculate.calculate_leftpoint(l);
            l.makesort(pl.x, pl.y);
            pl.belong.makesort(pl.x, pl.y);
            Point pr = calculate.calculate_rightpoint(l);
            q.push(pl);
            q.push(pr);*/
            lineset.push_back(l);
        }
        else if (type == 'C') {
            scanf_s("%d%d%d", &x, &y, &r);
            Circle c(x, y, r);
            circleset.push_back(c);
        }
        else {
            cout << "wrong format！" << endl;
            exit(0);
        }
    }
    /*while (!q.empty()) {
        Point p = q.top();
        q.pop();
        cout << "(" << p.x << "," << p.y << ")" <<endl;
    }*/
    if (n <= 10000000) {//暴力
        for (unsigned int i = 1; i < lineset.size(); i++) {
            for (unsigned int j = i + 1; j <= lineset.size(); j++) {
                Line l1 = lineset[i - 1];
                Line l2 = lineset[j - 1];
                calculate.calculate_line_line(l1, l2);
            }
        }
        for (unsigned int i = 1; i <= lineset.size(); i++) {
            for (unsigned int j = 1; j <= circleset.size(); j++) {
                Line l = lineset[i - 1];
                Circle c = circleset[j - 1];
                calculate.calculate_line_circle(l, c);
            }
        }

        for (unsigned int i = 1; i < circleset.size(); i++) {
            for (unsigned int j = i + 1; j <= circleset.size(); j++) {
                Circle c1 = circleset[i - 1];
                Circle c2 = circleset[j - 1];
                calculate.calculate_circle_circle(c1, c2);
            }
        }
        //cout << pointmap.size() << endl;
        cout << Setpoint.size() << endl;
        /*Map::iterator p = pointmap.begin();
        while (p != pointmap.end()) {
            cout << "(" << p->first.x << "," << p->first.y << ")\n";
            p++;
        }*/
    }
    else {//扫描线
        /*while (!q.empty()) {
            Point p = q.top();
            q.pop();
            if (p.type == 1) {//是左端点
                s.insert(p.belong);
                set<Line,cmp2>::iterator iter;
                iter = s.find(p.belong);
                Line l = *iter;
                if (iter != s.begin()) {
                    iter--;
                    Line l1 = *iter;
                    iter++;
                    calculate.calculate_line_line_allinsert(l, l1);
                }
                iter++;
                if (iter != s.end()) {
                    Line l1 = *iter;
                    calculate.calculate_line_line_allinsert(l1, l);
                } 
            }
            else if (p.type == 2) {//是右端点
                set<Line, cmp2>::iterator iter,iter1,del;
                iter = s.find(p.belong);
                iter1 = iter;
                del = iter;
                iter1++;
                if (iter != s.begin() && iter1 != s.end()) {
                    iter--;
                    Line l1 = *iter;
                    Line l2 = *iter1;
                    calculate.calculate_line_line_allinsert(l2, l1);
                }
                s.erase(del);
            }
            else {//是交点
                pointset.insert(p);
                set<Line, cmp2>::iterator iter1, iter2, it1, it2;
                iter1 = s.find(p.father1);
                iter2 = s.find(p.father2);
                it1 = iter1;
                it2 = iter2;
                it1++;
                if (it1 != s.end()) {
                    Line l1 = *it1;
                    Line l2 = *iter2;
                    calculate.calculate_line_line_allinsert(l1, l2);
                }
                if (iter2 != s.begin()) {
                    it2--;
                    Line l1 = *iter1;
                    Line l2 = *it2;
                    calculate.calculate_line_line_allinsert(l1, l2);
                }
            }
        }
        cout << pointset.size() << endl;*/
    }
    fclose(stdin);
    fclose(stdout);
}

