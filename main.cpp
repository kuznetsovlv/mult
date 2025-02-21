#include <iostream>
#include "env.h"
#include "input_reader.h"
#include "process.h"
#include "stop_exception.h"

int main(int, char **argv)
{
	try
	{
		std::cout << *argv << " version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

		std::cout << "TEST OF KNOWLEDGE OF THE MULTIPLICATION TABLE" << std::endl;

		std::cout << "Press Q to quit or any other key to start test:";


		const char ch = input_reader::instance().get_char();

		std::cout << std::endl;

		if (ch != 'q' && ch != 'Q')
		{

			std::cout << "Starting test..." << std::endl;

			start();
		}
	}
	catch ([[maybe_unused]] stop_exception &e)
	{
		std::cout << std::endl;
	}


	return 0;
}
