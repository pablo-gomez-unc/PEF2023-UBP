#include <iostream>
#include <chrono>

const double SMALL = 1.0e-20;
const int N = 100000; 

void todosMenores () {
    double A[N];
    double B[N];
    double C = 2.0;
    for (int i = 0; i < N; i++) {
        A[i] = SMALL / 2.0;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int k=0; k<10000; k++)
        for (int i = 0; i < N; i++) {
            //if (std::abs(A[i]) >= SMALL)
                B[i] = B[i] + A[i] * C;
        }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;
    std::cout << "Tiempo (caso 1): " << duration.count() << " milliseconds\n";
}


void todosMayores () {
    double A[N];
    double B[N];
    double C = 2.0;
    for (int i = 0; i < N; i++) {
        A[i] = SMALL * 2.0;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int k=0; k<10000; k++)
        for (int i = 0; i < N; i++) {
            //if (std::abs(A[i]) >= SMALL) 
                B[i] = B[i] + A[i] * C;
        }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;
    std::cout << "Tiempo (caso 2): " << duration.count() << " milliseconds\n";
}

void mitadYMitad () {
    double A[N];
    double B[N];
    double C = 2.0;
    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            A[i] = SMALL / 2.0;
        } else {
            A[i] = SMALL * 2.0;
        }
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int k=0; k<10000; k++)
        for (int i = 0; i < N; i++) {
            //if (std::abs(A[i]) >= SMALL) 
                B[i] = B[i] + A[i] * C;
        }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;
    std::cout << "Tiempo  (caso 3): " << duration.count() << " milliseconds\n";
}

int main() {
    // Caso 1: Todos los A(I)s son menores que SMALL
    todosMenores();
    // Caso 2: Todos los A(I)s son mayores que SMALL
    //todosMayores();
    // Caso 3: Mitad de los A(I)s son menores que SMALL, mitad mayores que SMALL
    //mitadYMitad();
    return 0;
}
