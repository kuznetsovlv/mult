#include "test.h"
#include <vector>
#include <utility>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <ios>

void test(std::vector<std::pair<uint16_t, uint16_t>> &arr)
{
    const size_t total = arr.size();
    size_t correct = 0;

    for(auto &p : arr)
    {
        const uint16_t expected = p.first * p.second;
        uint16_t answer;

        std::cout << p.first << " * " << p.second << " = ";
        std::cin >> answer;

        if(answer == expected)
        {
            ++correct;
            std::cout << "CORRECT" << std::endl;
        }
        else
        {
          std::cout << "FAIL: " << expected << std::endl;
        }
    }

    std::cout << "You gave " << correct << " " << (correct == 1 ? "answer" : "answers") << " from " << total << std::endl;
    std::cout << "Your result is " << std::fixed << std::setprecision(1) << (100.0 * correct / total) << "%" << std::endl;
}