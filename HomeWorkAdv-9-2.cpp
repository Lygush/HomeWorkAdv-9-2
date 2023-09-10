#include <iostream>
#include <string>
#include <vector>
#include "Big_int.h"

int main(){
    try {
        auto number1 = Big_int("114575");
        auto number2 = Big_int("78524");
        auto result = number1 + number2;
        std::cout << result << "\n";
        result = result * 100;
        std::cout << result; // 193099
    }
    catch(std::exception ex) {
        std::cout << ex.what();
    }
}