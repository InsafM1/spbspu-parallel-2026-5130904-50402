#include "shapes.hpp"

namespace muh = muhamadiarov;

muh::Circle::Circle(size_t r, Point p):
  r_(r),
  p_(p)
{}

bool muh::Circle::isInside() const noexcept
{
  return std::sqrt((p_.x - p.x) * (p_.x - p.x) + (p_.y - p.y) * (p_.y - p.y)) <= r_;
}
