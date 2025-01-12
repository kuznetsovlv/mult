#include "input_reader.h"
#include <string>
#include <cstdint>
#include <iostream>
#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#endif

input_reader::input_reader()
{
#ifndef _WIN32
  _default_termios = new struct termios;
  tcgetattr(fileno(stdin), _default_termios);
  struct termios new_termios = *_default_termios;
  new_termios.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(fileno(stdin), TCSANOW, &new_termios);
#endif
}

input_reader::~input_reader()
{
#ifndef _WIN32
  tcsetattr(fileno(stdin), TCSANOW, _default_termios);
  delete _default_termios;
#endif
}


input_reader &input_reader::instance()
{
  static input_reader instance;
  return instance;
}

char input_reader::get_char() const
{
  char ch;
#ifdef _WIN32
  ch = _getch();
#else
  ch = static_cast<char>(getchar());
  // std::cin >> ch;
#endif

  // std::cout << "\b \b";

  // std::cout << std::hex << static_cast<int>(ch);

  return ch;
}

uint16_t input_reader::get_uint16() const
{
  std::string str;
  while (true)
  {
    char c = get_char();
    if (c >= '0' && c <= '9')
    {
      str += c;
      std::cout << c;
    }
    else if (c == 0x7f && !str.empty())
    {
      std::cout << "\b \b";
      str.pop_back();
    }
    else if ((c == EOF || c == 0xa) && !str.empty())
    {
      return static_cast<uint16_t>(std::stoul(str));
    }
  }

}



