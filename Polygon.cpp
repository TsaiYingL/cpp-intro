#include <cmath>
#include <vector>
#include "Point.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include "Line.hpp"

Polygon::Polygon(std::vector<Point> point) {
    this -> p = point;
  }

double Polygon::area() {
    double sum = 0;
    for (int i=0; i<(p.size()-2); i++) {
      Triangle t(p[i], p[i+1], p[i+2]);
      double x = t.area();
      sum += x;
    }
      return sum;
}

double Polygon::perimeter() {
    double sum = 0;
    for (int i=0; i<(p.size()-1); i++) {
      Line l(p[1],p[i+1]);
      double x = l.length();
      sum += x;
    }
    return sum;
  }