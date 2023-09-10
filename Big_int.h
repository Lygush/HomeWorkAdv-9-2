#pragma once
#include <string>
#include <vector>
#include <ostream>

class Big_int {
    std::vector<short> value{0};
public:  
    Big_int() = default;

    Big_int(const char* input);

    ~Big_int() = default;

    Big_int(const Big_int&) = delete;

    Big_int& operator=(const Big_int&) = delete;

    Big_int(Big_int&& dying) noexcept;

    Big_int& operator=(Big_int&& rhs) noexcept;

    void add_zero(std::vector<short>& vec_first, std::vector<short>& vec_second, int& size);

    void remove_zero(std::vector<short>& vec);

    Big_int operator+(Big_int& summand);

    Big_int operator*(int multiplier);

    friend std::ostream& operator<<(std::ostream& out, Big_int& printed);
};