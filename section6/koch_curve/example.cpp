#include<bits/stdc++.h>
using namespace std;

//TODO: ベクトル演算16翔やってから

struct Point { double x, y; };

void koch(int n, Point a, Point b) {
    if (n == 0) return;

    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0:
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0:
    t.x = (2.0 * a.x + 1.0 * b.x) / 3.0:
    t.y = (2.0 * a.y + 1.0 * b.y) / 3.0:
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    
}