#include "monte_carlo.hpp"

namespace muhamadiarov
{

}

namespace muh = muhamadiarov;

std::pair< double, double > muh::getAreas(
  const muh::circle_t& shapes,
  size_t threads,
  size_t tries,
  size_t seed
)
{
  std::pair< double, double > results = {0.0, 0.0};

  const size_t countOfTriesForThread = tries / thread;
  const size_t remainingOnes = tries % thread;

  return results;
}
