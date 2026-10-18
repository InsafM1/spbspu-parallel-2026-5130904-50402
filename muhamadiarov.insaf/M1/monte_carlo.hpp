#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP
#include "shapes.hpp"
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

namespace muhamadiarov
{
  using circle_t = std::vector<std::unique_ptr<Circle>>;
  std::pair<double, double> getAreas(const circle_t &shapes, const size_t threads,
                                    const size_t tries, const size_t seed);
}
#endif
