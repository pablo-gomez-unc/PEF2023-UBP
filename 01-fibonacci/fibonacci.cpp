#include <iostream>
#include <chrono>


unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << fibonacci(n) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;

    return 0;
}
