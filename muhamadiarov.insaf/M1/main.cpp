#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if (argc != 3 && argc != 4)
  {
    std::cerr << "insufficient number of arguments\n";
    return 1;
  }
  if (argv[1][0] == '-' || argv[2][0] == '-')
  {
    std::cerr << "arguments must be non-negative numbers\n";
    return 1;
  }
  size_t threads = 0;
  size_t tries = 0;
  size_t seed = 0;
  try
  {
    threads= std::stoull(argv[1]);
    tries = std::stoull(argv[2]);
    if (argc == 4)
    {    
      if (argv[3][0] == '-')
      {
        std::cerr << "arguments must be non-negative numbers\n";
        return 1;
      }
      seed = std::stoull(argv[3]);
      if (!seed)
      {
        std::cerr << "number of trials must be positive\n";
        return 1;
      }
    }
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "arguments aren't numbers\n";
    return 1;
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "numberical values of arguments exceed the permissible limit\n";
    return 1;
  }
  return 0;
}
