#include <iostream>
#include <chrono>
#include <vector>
#include <cstdint>


__uint128_t fibonacci(int n, std::vector<__uint128_t>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    std::vector<__uint128_t> memo(n + 1, -1);

    auto start = std::chrono::high_resolution_clock::now();

    __uint128_t result = fibonacci(n, memo);
    std::cout << (long long)(result>>64) << (long long)(result) << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;

    return 0;
}
