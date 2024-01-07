#include <iostream>
#include "random.h"
#include "env.h"

int main(int, char **argv)
{

	std::cout << *argv << " version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

	while(true)
	{
		std::cout << random(2, 10) << " * " << random(2, 10) << std::endl;
		getchar();
	}
	return 0;
}
