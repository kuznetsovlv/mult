#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstdint>
#include "random.h"

uint16_t random(uint16_t from, uint16_t to)
{
	static bool init = false;

	if(!init)
	{
		srand(time(nullptr));
		init = true;
	}

	return rand() % (to - from) + from;
}
