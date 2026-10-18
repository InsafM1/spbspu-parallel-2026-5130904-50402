#include "monte_carlo.hpp"
#include <algorithm>
#include <future>
#include <random>

namespace muhamadiarov
{
  std::pair<size_t, size_t> getCountOfPoints(const circle_t &shapes, const size_t tries,
                                            const size_t seed, const double xMax,
                                            const double xMin, const double yMax,
                                            const double yMin)
  {
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> distX(xMin, xMax);
    std::uniform_real_distribution<double> distY(yMin, yMax);
    std::pair<size_t, size_t> results{0, 0};
    for (size_t i = 0; i < tries; ++i)
    {
      double x = distX(gen);
      double y = distY(gen);
      size_t countOfShapes = 0;
      for (size_t j = 0; j < shapes.size(); ++j)
      {
        if (shapes[j]->isInside({x, y}) && !countOfShapes)
        {
          results.first += 1;
          countOfShapes = 1;
        }
        else if (shapes[j]->isInside({x, y}))
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
  double getMaxYAmongShapes(const circle_t &shapes)
  {
    double result = shapes[0]->getMaxY();
    for (size_t i = 1; i < shapes.size(); ++i)
    {
      result = std::max(result, shapes[i]->getMaxY());
    }
    return result;
  }
  double getMinYAmongShapes(const circle_t &shapes)
  {
    double result = shapes[0]->getMinY();
    for (size_t i = 1; i < shapes.size(); ++i)
    {
      result = std::min(result, shapes[i]->getMinY());
    }
    return result;
  }
  double getMaxXAmongShapes(const circle_t &shapes)
  {
    double result = shapes[0]->getMaxX();
    for (size_t i = 1; i < shapes.size(); ++i)
    {
      result = std::max(result, shapes[i]->getMaxX());
    }
    return result;
  }
  double getMinXAmongShapes(const circle_t &shapes)
  {
    double result = shapes[0]->getMinX();
    for (size_t i = 1; i < shapes.size(); ++i)
    {
      result = std::min(result, shapes[i]->getMinX());
    }
    return result;
  }
}

namespace muh = muhamadiarov;

std::pair<double, double> muh::getAreas(const muh::circle_t &shapes,
                                        const size_t threads, const size_t tries,
                                        const size_t seed)
{
  std::pair<double, double> results = {0.0, 0.0};
  const size_t countOfTriesForThread = tries / (threads + 1);
  const size_t remainingOnes = tries % (threads + 1);
  std::vector<std::future<std::pair<size_t, size_t>>> futures;
  const double yMax = muh::getMaxYAmongShapes(shapes);
  const double yMin = muh::getMinYAmongShapes(shapes);
  double xMax = muh::getMaxXAmongShapes(shapes);
  double xMin = muh::getMinXAmongShapes(shapes);
  const double step = (xMax - xMin) / (threads + 1);
  xMax = xMin + step;
  for (size_t i = 1; i < threads + 1; ++i)
  {
    xMin = xMax;
    xMax += step;
    futures.push_back(std::async(std::launch::async, muh::getCountOfPoints,
                                 std::ref(shapes), countOfTriesForThread, seed,
                                 xMax, xMin, yMax, yMin));
  }
  xMin = muh::getMinXAmongShapes(shapes);
  xMax = xMin + step;
  std::pair<size_t, size_t> count =
      muh::getCountOfPoints(shapes, countOfTriesForThread + remainingOnes, seed,
                            xMax, xMin, yMax, yMin);
  for (size_t i = 0; i < threads; ++i)
  {
    std::pair<size_t, size_t> r = futures[i].get();
    count.first += r.first;
    count.second += r.second;
  }
  xMax = muh::getMaxXAmongShapes(shapes);
  const double boxArea = (yMax - yMin) * (xMax - xMin);
  results.first = boxArea * static_cast<double>(count.first) / tries;
  results.second = boxArea * static_cast<double>(count.second) / tries;
  return results;
}
