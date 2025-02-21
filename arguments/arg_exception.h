#pragma once
#include <exception>




class arg_exception final: public std::exception {
private:
    const char* arguments;
public:
    arg_exception() noexcept;
    explicit arg_exception(const char* arguments) noexcept;

    [[nodiscard]] const char* what() const noexcept override;

    ~arg_exception() noexcept override;
};


