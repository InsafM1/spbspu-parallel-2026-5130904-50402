#include "monte_carlo.hpp"

namespace muhamadiarov
{
  std::pair< size_t, size_t > getCountOfPoints(
    const circle_t& shapes,
    size_t tries,
    size_t seed,
    double xMax,
    double xMin,
    double yMax,
    double yMin
  )
  {
    std::default_random_engine gen(seed);
    std::uniform_real_distribution< double > distX(xMin, xMax);
    std::uniform_real_distribution< double > distY(yMin, yMax);
    std::pair< double, double > results{0.0, 0.0};
    for (size_t i = 0; i < tries; ++i)
    {
      double x = distX(gen);
      double y = distY(gen);
      size_t countOfShapes = 0;
      for (size_t j = 0; j < shapes.size(); ++j)
      {
        if ((*shapes[j]).isInside({x, y}) && !countOfShapes)
        {
          results.first += 1;
          countOfShapes = 1;
        }
        else if((*shapes[j]).isInside({x, y}))
        {
          countOfShapes += 1;
        }
      }
      if (countOfShapes == shapes.size())
      {
        results.second += 1;
      }
    }
    return results;
  }
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
  const size_t countOfTriesForThread = tries / threads;
  const size_t remainingOnes = tries % threads;
  return results;
}
