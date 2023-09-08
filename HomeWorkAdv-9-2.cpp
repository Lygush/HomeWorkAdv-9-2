#include <iostream>
#include <string>
#include <vector>

class Big_int {
public:
    std::vector<char> value{};
    char sign {'+'};
public:  
    Big_int(char* input) {
        std::string in {input};
        int counter{};
        if (in[0] == '-') {
            sign = '-';
            counter++;
        }
        for (counter; counter < in.size(); ++counter) {
            if (in[counter] < 48 || in[counter] > 57) {
                throw std::exception("Invalid symbol");
            }
            else value.push_back(in[counter]);
        }
    }

    ~Big_int() = default;
    Big_int(const Big_int&) = delete;
    Big_int& operator=(const Big_int&) = delete;

    Big_int(Big_int&& dying) {
        value = std::move(dying.value);
        sign = dying.sign;
    }

    Big_int& operator=(Big_int&& rhs) {
        if (&rhs == this) {
            return *this;
        }
        else {
        value = std::move(rhs.value);
        sign = rhs.sign;
        return *this;
        }
    }

    Big_int&& operator+(Big_int& summand) {
        value.insert(value.begin(), '3');
        return std::move(*this);
    }
};

int main(){
    Big_int A("222");
    Big_int B("111");
    Big_int C = A + B;
    for(auto i: C.value) {
        std::cout << i;
    }
}
