#include <iostream>
#include "input.h"
#include "env.h"

int main(int, char **argv)
{

	std::cout << *argv << " version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

	std::cout << "TEST OF KNOWLEDGE OF THE MULTIPLICATION TABLE" << std::endl;

	switchOffBuffer();

	std::cout << "Press Q to quit or any other key to start test:";

	char ch = getPressedChar();

	std::cout << std::endl;

	if (ch != 'q' && ch != 'Q') {

		std::cout << "Starting test..." << std::endl;

	}

	switchOnBuffer();

	return 0;
}
