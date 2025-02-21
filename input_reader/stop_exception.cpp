#include "stop_exception.h"

const char* stop_exception::what() const noexcept
{
    return "Found end of input.";
}