#include "test.h"
#include <cstdint>
#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
#include "../input_reader/input_reader.h"

void test(std::vector<std::pair<uint16_t, uint16_t>> &arr)
{
    size_t total = 0;
    size_t correct = 0;

    try
    {
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
            ++total;
        }
    }
    catch([[maybe_unused]] const std::exception &e)
    {
        std::cout << std::endl;
    }

    const size_t wrong = total - correct;

    std::cout << "Total tests: " << total << std::endl;
    std::cout << "You gave " << correct << " correct " << (correct == 1 ? "answer" : "answers") <<
        " and " << wrong << " " << (wrong == 1 ? "answer" : "answers") << " from " << total << std::endl;
    std::cout << "Your result is " << std::fixed << std::setprecision(1) <<
        (100.0 * static_cast<double>(correct) / static_cast<double>(total)) << "%" << std::endl;
}
