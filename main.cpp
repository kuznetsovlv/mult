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

		std::cout << "\033[1;37m\033[1;1mTEST OF KNOWLEDGE OF THE MULTIPLICATION TABLE\033[0m" << std::endl;

		std::cout << "Press \033[1;31mQ\033[0m to quit or \033[1;36many other key\033[0m to start test:";


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
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown error." << std::endl;
		return 1;
	}


	return 0;
}
