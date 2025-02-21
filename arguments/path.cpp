#include "path.h"
#include <cstring>
#include <string>
#include "arg_exception.h"

path get_path(int argc, const char **argv)
{
    if (argc == 1)
    {
        return path::MAIN;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--print_help") == 0)
    {
        return path::HELP;
    }

    std::string args;

    for (int i = 1; i < argc; ++i)
    {
        args += std::string(argv[i]);
        if (i != argc - 1)
        {
            args += ' ';
        }
    }

    throw arg_exception(args.c_str());

}