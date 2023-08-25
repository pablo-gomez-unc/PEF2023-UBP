#include <iostream>
using namespace std;

int main() {
    float floatNum = 1.0f;
    double doubleNum = 1.0;

    int floatPrecision = 0;
    int doublePrecision = 0;

    while (1.0f + floatNum != 1.0f) {
        floatNum /= 10.f;
        floatPrecision++;
    }

    while (1.0 + doubleNum != 1.0) {
        doubleNum /= 10;
        doublePrecision++;
    }

    std::cout << "Precisión de float: " << floatPrecision << " dígitos" << std::endl;
    std::cout << "Precisión de double: " << doublePrecision << " dígitos" << std::endl;

    return 0;
}