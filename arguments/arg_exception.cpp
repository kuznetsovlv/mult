#include "arg_exception.h"
#include <cstring>
#include <string>


const char* coppy_str(const char*) noexcept;

arg_exception::arg_exception() noexcept:arguments(coppy_str("Invalid arguments."))
{}

arg_exception::arg_exception(const char *args) noexcept:arguments(coppy_str(("Invalid arguments: \"" + std::string(args) + "\".").c_str()))
{}

arg_exception::~arg_exception() noexcept
{
    delete[] arguments;
}


const char *arg_exception::what() const noexcept
{
   return arguments;
}

const char* coppy_str(const char* str) noexcept
{
    const auto res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}