#include <iostream>
#include <chrono>

const long N = 100000;
const int R = 10;

int main() {
    
    int** matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 1;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int k= 0; k < R; k++) {
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matriz[i][j] += 1;
            }
        }
        */
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                matriz[i][j] += 1;
            }
        }

    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;
   
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
