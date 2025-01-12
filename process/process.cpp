#include "process.h"
#include <vector>
#include <utility>
#include <cstdint>
#include "init.h"
#include "test.h"

void start()
{
    std::vector<std::pair<uint16_t, uint16_t>> pairs;

    init(pairs);
    test(pairs);
}
