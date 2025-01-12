#pragma once
#include <cstdint>
#ifndef _WIN32
#include <termios.h>
#endif

class input_reader final {
private:
#ifndef _WIN32
    struct termios* _default_termios = nullptr;
#endif
    explicit input_reader();

public:
    static input_reader& instance();

    ~input_reader();

    [[nodiscard]] char get_char() const;

    [[nodiscard]] uint16_t get_uint16() const;
};
