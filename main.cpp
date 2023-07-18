#include <iostream>
#include <cmath>

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
  Point(double x, double y){
  this ->x=x;
  this ->y=y;
  }

  double distance_to_origin(){
    return sqrt(pow(x,2)+pow(y,2));
  }

  double distance_to_point(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};


class Line {
  private:
  array x;
  array y;

  public:

  

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
  std::cout <<"y/z = " << divide(y,z) <<std::endl;
  
  Point p(3.5,4.5);
  std::cout << p.distance_to_origin()<<std::endl;
  std::cout << "a" <<std::endl;
  return 0;
}