#pragma once
#include <exception>


class stop_exception final : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};



