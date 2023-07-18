#include <iostream>

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
  public:
  double x;
  double y;

  double distance_to_origin(){
    return y-x;
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
  std::cout <<"y/z = " << divide(y,z) <<std::endl;
  
  Point p;
  p.x = 3.5;
  p.y = 6.4;
  std::cout << "The distance is " << p.distance_to_origin() <<std::endl;
  std::cout << "a" <<std::endl;
  return 0;
}