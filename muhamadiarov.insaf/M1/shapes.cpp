#include "shapes.hpp"
#include "cmath"

namespace muh = muhamadiarov;

muh::Circle::Circle(double r, Point p):
  r_(r),
  p_(p)
{}

bool muh::Circle::isInside(Point p) const noexcept
{
  return std::sqrt((p_.x - p.x) * (p_.x - p.x) + (p_.y - p.y) * (p_.y - p.y)) <= r_;
}

double muh::Circle::getMaxX() const noexcept
{
  return p_.x + r_;
}

double muh::Circle::getMinX() const noexcept
{
  return p_.x - r_;
}

double muh::Circle::getMaxY() const noexcept
{
  return p_.y + r_;
}

double muh::Circle::getMinY() const noexcept
{
  return p_.y - r_;
}
