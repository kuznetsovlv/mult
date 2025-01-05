#include "input.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#endif

#ifndef _WIN32
struct termios oldSettings, newSettings;
#endif

void switchOffBuffer()
{
#ifndef _WIN32
  tcgetattr( fileno( stdin ), &oldSettings );
  newSettings = oldSettings;
  newSettings.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr( fileno( stdin ), TCSANOW, &newSettings );
#endif
}

void switchOnBuffer() {
#ifndef _WIN32
  tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
#endif
}

char getPressedChar() {
#ifdef _WIN32
  return _getch();
#else
return static_cast<char>(getchar());
#endif
}
