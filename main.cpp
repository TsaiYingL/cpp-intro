#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"

int subtract(int x, int y) {
  return x-y;
}

int multiply(int x, int y){
  return x*y;
}

int divide(int x, int y){
  return x/y;
}


/* class Line {
  private:
  Point p1;
  Point p2;

  public:
  Line(const Point &point1, const Point &point2): p1(point1), p2(point2) {
    p1 = point1;
    p2 = point2;
  }
 
  //Problem 3
  double length() {
    return p1.distance_to_point(p2);
  }

  //Problem 4
  double distance_to_point(Point &p) {
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();
    double numerator = abs(dy*p.x() - dx*p.y() + p2.x()*p1.y() - p2.y()*p1.x());
    double denominator = sqrt(pow(dx,2)+pow(dy,2));
    return numerator/denominator;
  }
};  */

/* class Triangle {
  private:
  Point p1;
  Point p2;
  Point p3;

  public:
  Triangle(const Point &point1, const Point &point2, const Point &point3): p1(point1), p2(point2), p3(point3) {
    p1 = point1;
    p2 = point2;
    p3 = point3;
  }

  //Problem 6
  double area() {
    double side_1 = p1.distance_to_point(p2);
    double side_2 = p2.distance_to_point(p3);
    double side_3 = p3.distance_to_point(p1);
    double s = (side_1+side_2+side_3)/2;
    double area = sqrt(s*(s-side_1)*(s-side_2)*(s-side_3));
    return area;
  }
}; */

/* class Polygon {
  private:
  std::vector<Point> p;

  public:
  Polygon(std::vector<Point> point) {
    this -> p = point;
  }

  //Problem 7
  double area() const{
    double sum = 0;
    for (int i=0; i<(p.size()-2); i++) {
      Triangle t(p[i], p[i+1], p[i+2]);
      double x = t.area();
      sum += x;
    }
      return sum;
  }

  //Problem 8
  double perimeter() const {
    double sum = 0;
    for (int i=0; i<(p.size()-1); i++) {
      Line l(p[1],p[i+1]);
      double x = l.length();
      sum += x;
    }
    return sum;
  }
}; */

class AUV {
  private:
  std::string name;
  Point position;
  double depth = 0;
  double heading = 0;
  std::array<double,3> speed;
  double angular_speed;

  public:
  AUV(const std::string& name, const Point& position, double depth, double heading, const std::array<double, 3>& speed, double angular_speed):
   name(name), position(position), depth(depth), heading(heading), speed(speed), angular_speed(angular_speed) {}
  
  void step(double dt) {
        position.x += speed[0] * dt; // Forward movement
        position.y += speed[1] * dt; // Lateral movement
        position.z += speed[2] * dt; // Vertical movement
    }
    
    void apply_acceleration(const std::array<double, 3>& acceleration, double dt) {
        speed[0] += acceleration[0] * dt; // Forward acceleration
        speed[1] += acceleration[1] * dt; // Lateral acceleration
        speed[2] += acceleration[2] * dt; // Vertical acceleration
    }

    
    void apply_angular_acceleration(double angular_acceleration, double dt) {
        angular_speed += angular_acceleration * dt;
    }
};



int main()
{
  std::cout << "Tsai, 115" << std::endl;

  int w = 6;
  int x = 5;
  int y = 7;
  int z = 4;
  std::cout << "The sum of " << x << " and " << y << " and " << z << " is " << x + y + z << std::endl;
  std::cout <<"The product of " << w << " and " << x << " and " <<y<< " and " << z << " is " << w*x*y*z << std::endl;
  std::cout <<"The answer for y/x is " << y/x << std::endl;
  std::cout <<"y - z = " << subtract(y,z) << std::endl;
  std::cout <<"y*z = " << multiply(y,z) <<std::endl;
  std::cout <<"y/z = " << divide(y,z) <<std::endl<<std::endl;


  Point p1(3, 1);
  Point p2(1,1);
  Point p3(1, 4);
  Point p4(3, 4);
  Point p5(2,6);

  std::cout <<"Problem 1 and 2"<<std::endl;

  // Problem 1
  std::cout << "distance_to_origin: " << p1.distance_to_origin() << std::endl;

  //Problem 2
  std::cout << "distance_to_point: " << p1.distance_to_point(p2) << std::endl<<std::endl;

  std::cout << "Problem 3 and 4" << std::endl;

  // Problem 3
  Line line(p1, p2);
  std::cout << "Line length: " << line.length() << std::endl;

  // Problem 4
  std::cout << "Distance to line: " << line.distance_to_point(p3) << std::endl << std::endl;

  std::cout << "Problem 6" <<std::endl;

  //Problem 6
  Triangle triangle(p1, p2, p3);
  std::cout << "Area: " << triangle.area() << std::endl << std::endl;

  //Problem 7
  std::vector<Point> poly = {p1, p2, p3, p4, p5};
  Polygon polygon(poly);
  std::cout << "Area of Polygon: " << polygon.area() << std::endl << std::endl;



  std::cout << "a" <<std::endl;
  return 0;
}