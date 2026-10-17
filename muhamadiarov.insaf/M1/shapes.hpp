#ifndef SHAPES_HPP
#define SHAPES_HPP

namespace muhamadiarov
{
  struct Point
  {
    double x, y;
  };

  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual bool isInside(Point p) const noexcept = 0;
  };

  class Circle final: public Shape
  {
  public:
    Circle(double r, Point p);
    bool isInside(Point p) const noexcept override;  
  private:
    double r_;
    Point p_;
  };
}
#endif
