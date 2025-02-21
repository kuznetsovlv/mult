#include "print_help.h"
#include <iostream>

void print_help(const char* name) noexcept
{
    std::cout << "Usage: " << name << std::endl;
    std::cout << "For help use flags   -h, --help" << std::endl;
    std::cout << "For test start program without flags than press any key to start test or Q to quit." << std::endl;
    std::cout << "If you want to stop test press ^D." << std::endl;
}