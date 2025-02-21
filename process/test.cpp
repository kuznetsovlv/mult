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
                std::cout << "\033[1;34m CORRECT\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[1;31m FAIL: " << expected << "\033[0m" << std::endl;
            }
            ++total;
        }
    }
    catch([[maybe_unused]] const std::exception &e)
    {
        std::cout << std::endl;
    }

    if (total)
    {
        const size_t wrong = total - correct;
        const double percentage = (100.0 * static_cast<double>(correct) / static_cast<double>(total));

        std::cout << "\033[1;1mTotal tests: " << total << "\033[0m" << std::endl;
        std::cout << "You gave \033[1;34m" << correct << "\033[0m correct " << (correct == 1 ? "answer" : "answers") <<
            " and \033[1;31m" << wrong << "\033[0m " << (wrong == 1 ? "answer" : "answers") << " from " << total << std::endl;
        std::cout << "Your result is " << std::fixed << std::setprecision(1) <<
           (percentage < 35 ? "\033[1;31m" : percentage > 65 ? "\033[1;34m" : "\033[1;33m") << percentage << "%\033[0m" << std::endl;
    }
    else
    {
        std::cout << "No tests were performed." << std::endl;
    }
}
