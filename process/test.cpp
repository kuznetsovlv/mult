#include "test.h"
#include <vector>
#include <utility>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <ios>
#include "../input_reader/input_reader.h"

void test(std::vector<std::pair<uint16_t, uint16_t>> &arr)
{
    const size_t total = arr.size();
    size_t correct = 0;

    for(auto &p : arr)
    {
        const uint16_t expected = p.first * p.second;


        std::cout << p.first << " * " << p.second << " = ";

        if(input_reader::instance().get_uint16() == expected)
        {
            ++correct;
            std::cout << " CORRECT" << std::endl;
        }
        else
        {
          std::cout << " FAIL: " << expected << std::endl;
        }
    }

    std::cout << "You gave " << correct << " " << (correct == 1 ? "answer" : "answers") << " from " << total << std::endl;
    std::cout << "Your result is " << std::fixed << std::setprecision(1) << (100.0 * static_cast<double>(correct) / static_cast<double>(total)) << "%" << std::endl;
}