#ifndef SHAPES_HPP
#define SHAPES_HPP
#include <cmath>

namespace muhamadiarov
{
  struct Point
  {
    double x;
    double y;
  };

  class Circle
  {
  public:
    Circle(double r, Point p);
    bool isInside(Point p) const noexcept;
    double getMaxX() const noexcept;
    double getMinX() const noexcept;
    double getMaxY() const noexcept;
    double getMinY() const noexcept;

  private:
    double r_;
    Point p_;
  };
}
#endif
