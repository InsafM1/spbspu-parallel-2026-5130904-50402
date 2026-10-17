#ifndef SHAPES_HPP
#define SHAPES_HPP
#include <cmath>

namespace muhamadiarov
{
  struct Point
  {
    double x, y;
  };

  class Circle
  {
  public:
    Circle(double r, Point p);
    bool isInside(Point p) const noexcept;  
  private:
    double r_;
    double p_;
  };
}
#endif
