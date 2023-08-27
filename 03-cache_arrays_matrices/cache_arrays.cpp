#include <iostream>
#include <chrono>

const long N = 100000000;
const int R = 1000;

int main() {
    
    unsigned long long* array = new unsigned long long [N];
    for (long i = 0; i < N; i++) {
        array[i] = 1;    
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int k= 0; k < R; k++) {
        for (long i = 0; i < N; i = i + 1000 ) {
            array[i] += 1;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;

    delete[] array;
    return 0;
}
