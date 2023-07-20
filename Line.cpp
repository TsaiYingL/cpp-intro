#include "Line.hpp"
#include "Point.hpp"
#include <cmath>

Line::Line(Point point1, Point point2): p1(point1), p2(point2) {}

double Line::length() {
    return p1.distance_to_point(p2);
}

double Line::distance_to_point(Point p) {
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();
    double numerator = std::abs(dy*p.x() - dx*p.y() + p2.x()*p1.y() - p2.y()*p1.x());
    double denominator = std::sqrt(std::pow(dx,2)+std::pow(dy,2));
    return numerator/denominator;
}