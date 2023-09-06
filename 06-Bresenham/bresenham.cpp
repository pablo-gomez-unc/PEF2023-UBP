#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x,y ;
    Point (int _x, int _y) : x(_x) , y(_y) {}
};

vector <Point> bresenhamLine (int x0, int y0, int x1, int y1) {
    vector <Point> points;

    int dx = abs(x1-x0);
    int dy = abs(y1-y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int error = dx-dy;

    points.push_back(Point(x0,y0));

    while (x0 != x1 || y0 != y1) {
        int error2 = error * 2;
        if (error2 > -dy) {
            error -= dy;
            x0 += sx;
        }
        if (error2 < dx) {
            error += dx;
            y0 += sy;
        }
        points.push_back(Point(x0,y0));    
    }

    return points;
}

int main () {
    int x0 = 0 , y0 = 0;
    int x1 = 6 , y1 = 4;

    vector<Point> linePoints = bresenhamLine (x0,y0,x1,y1);
    
    for (const Point&p : linePoints) {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    return 0;
}