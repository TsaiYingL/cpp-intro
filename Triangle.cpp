#include "Triangle.hpp"
#include "Point.hpp"
#include <cmath>

Triangle::Triangle(Point point1, Point point2, Point point3): p1(point1), p2(point2), p3(point3) {}

double Triangle::area(){
    double side_1 = p1.distance_to_point(p2);
    double side_2 = p2.distance_to_point(p3);
    double side_3 = p3.distance_to_point(p1);
    double s = (side_1+side_2+side_3)/2;
    double area = sqrt(s*(s-side_1)*(s-side_2)*(s-side_3));
    return area;
}