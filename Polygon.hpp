#pragma once
#include "Point.hpp"
#include <vector>

class Polygon {
private:
    std::vector<Point> p;

public:
    Polygon(std::vector<Point> points);

    double area();
    double perimeter();
};