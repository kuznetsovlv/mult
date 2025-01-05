
#include <cstdint>
#include <rndgen.h>
#include "random.h"

uint16_t random(uint16_t from, uint16_t to)
{
		return rndgen::random<uint16_t>() % (to - from) + from;
}
