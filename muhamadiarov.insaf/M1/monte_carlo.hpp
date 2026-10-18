#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP
#include "shapes.hpp"
#include <memory>
#include <vector>
#include <utility>
#include <random>
#include <cstddef>
#include <future>
#include <algorithm>

namespace muhamadiarov
{
  using circle_t = std::vector< std::unique_ptr< Circle > >; 
  std::pair< double, double > getAreas(
    const circle_t& shapes,
    size_t threads,
    size_t tries,
    size_t seed
  );
}
#endif
