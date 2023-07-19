#include <iostream>
#include <cmath>
#include <vector>

int subtract(int x, int y) {
  return x-y;
}

int multiply(int x, int y){
  return x*y;
}

int divide(int x, int y){
  return x/y;
}

// a class that returns the distance between the origin and the point
class Point {
  private:
  double x;
  double y;

  public:
  Point(double x_val, double y_val){
  this -> x=x_val;
  this -> y=y_val;
  }

  //Problem 1
  double distance_to_origin() const{
    return sqrt(pow(x,2)+pow(y,2));
  }

  //Problem 2
  double distance_to_point(Point p) const{
    double x_2 = x - p.x;
    double y_2 = y - p.y;
    return sqrt(pow(x_2,2)+pow(y_2,2));
  }

  friend class Line;
  friend class Triangle;
  friend class Polygon;

};

class Line {
  private:
  Point p1;
  Point p2;

  public:
  Line(const Point &point1, const Point &point2): p1(point1), p2(point2) {
    p1 = point1;
    p2 = point2;
  }
 
  //Problem 3
  double length() const{
    return p1.distance_to_point(p2);
  }

  //Problem 4
  double distance_to_point(const Point &p) const{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double numerator = abs(dy*p.x - dx*p.y + p2.x*p1.y - p2.y*p1.x);
    double denominator = sqrt(pow(dx,2)+pow(dy,2));
    return numerator/denominator;
  }
};

class Triangle {
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
  double area() const{
    double side_1 = p1.distance_to_point(p2);
    double side_2 = p2.distance_to_point(p3);
    double side_3 = p3.distance_to_point(p1);
    double s = (side_1+side_2+side_3)/2;
    double area = sqrt(s*(s-side_1)*(s-side_2)*(s-side_3));
    return area;
  }
};

class Polygon {
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