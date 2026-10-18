#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP
#include "shape.hpp"
#include <memory>
#include <vector>
#include <utility>

namespace muhamadiarov
{
  using circles_t = std::vector< std::unique_ptr< Circle > >; 
  std::pair< double, double > getAreas(
    const circle_t& shapes,
    size_t threads,
    size_t tries,
    size_t seed
  );
}
#endif
