#include "Big_int.h"
  
Big_int::Big_int(const char* input) {
    std::string in {input};
    std::string pushed{};
    for (int counter{}; counter < in.size(); ++counter) {
        if (in[counter] < 48 || in[counter] > 57) {
             throw std::exception("Invalid symbol");
        }
        else
            pushed = in[counter];
        value.push_back(std::stoi(pushed));
    }
    if (value[0] == 0) {
        remove_zero(value);
    }
}

Big_int::Big_int(Big_int&& dying) noexcept{
    value = std::move(dying.value);
}

Big_int& Big_int::operator=(Big_int&& rhs) noexcept{
    if (&rhs == this) {
        return *this;
    }
    else {
    value = std::move(rhs.value);
    return *this;
    }
}

void Big_int::add_zero(std::vector<short>& vec_first, std::vector<short>& vec_second, int& size) {
    int size_first_sum{ static_cast<int>(vec_first.size()) }, size_second_sum{ static_cast<int>(vec_second.size()) };
    if (size_second_sum == size_first_sum) {
        size = size_first_sum - 1;
    }
    else {
        if (size_second_sum > size_first_sum) {
            for (int i{}; i < size_second_sum - size_first_sum; ++i) {
                vec_first.insert(vec_first.begin(), 0);
            }
            size = size_second_sum - 1;
        }
        else {
            for (int i{}; i < size_first_sum - size_second_sum; ++i) {
                vec_second.insert(vec_second.begin(), 0);
            }
            size = size_first_sum - 1;
        }
    }
}

void Big_int::remove_zero(std::vector<short>& vec) {
    int counter{};
    std::vector<short> removed;

    if (vec.at(0) != 0) {
        return;
    }
    while (vec[counter] == 0) {
        if (vec.size() - 1 == counter) {
            removed.push_back(0);
            vec = std::move(removed);
            return;
        }
        counter++;
    }
    for (counter; counter < vec.size(); ++counter) {
        removed.push_back(vec[counter]);
    }
    vec = std::move(removed);
}

Big_int Big_int::operator+(Big_int& summand) {
    std::vector<short> sum{};
    short temp{};
    bool dozen{};
    int size{};
    add_zero(this->value, summand.value, size);
    for (size ; size >= 0 ; --size) {
        temp = this->value[size] + summand.value[size];
        if (dozen) {
            temp++;
        }
        dozen = false;
        if (temp > 9) {
            sum.insert(sum.begin(), temp - 10);
            dozen = true;
        }
        else {
            sum.insert(sum.begin(), temp);
        }
    }
    if (dozen) {
        sum.insert(sum.begin(), 1);
    }
    remove_zero(this->value);
    remove_zero(summand.value);
    Big_int result;
    result.value = std::move(sum);
    return result;
}

Big_int Big_int::operator*(int multiplier) {
    Big_int multe;
    for (int i{}; i < multiplier; ++i) {
        multe = multe + *this;
    }
    return multe;
}

std::ostream& operator<<(std::ostream& out, Big_int& printed) {
    for (const auto& i: printed.value) {
        out << i;
    }
    return out;
}