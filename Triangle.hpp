#pragma once
#include "Point.hpp"

class Triangle{
private:
    Point p1;
    Point p2;
    Point p3;

public:
    Triangle(Point pa, Point pb, Point pc);

    double area();
};

