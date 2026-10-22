#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP
#include "shapes.hpp"
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

namespace muhamadiarov
{
  using circle_t = std::vector< std::unique_ptr< Circle > >;
  std::pair< double, double > getAreas(const circle_t &shapes, size_t threads, size_t tries, size_t seed);
}
#endif
