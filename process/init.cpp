#include "init.h"
#include <vector>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <random>

void init(std::vector<std::pair<uint16_t, uint16_t>> &arr)
{
      for(uint16_t a = 2; a < 10; ++a)
      {
            for(uint16_t b = a; b < 10; ++b)
            {
                  arr.push_back(std::make_pair(a, b));
            }
      }

      auto rd = std::random_device {};
      auto rng = std::default_random_engine {rd()};
      std::ranges::shuffle(arr, rng);
}