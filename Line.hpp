#pragma once
#include "Point.hpp"

class Line {
private:
    Point p1;
    Point p2;

public:
    Line(Point pa, Point pb);

    double length();
    double distance_to_point(Point &p);
};