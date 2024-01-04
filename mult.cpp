#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstdint>

#include "env.h"

uint16_t random(uint16_t, uint16_t);

int main(int argc, char **argv)
{

	std::cout << *argv << " version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

	while(true)
	{
		std::cout << random(2, 10) << " * " << random(2, 10) << std::endl;
		getchar();
	}
	return 0;
}

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
