#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

const int numIterations = 1000;
const int minArrayLength = 1000;
const int maxArrayLength = 10000000;

template <typename T>
void processArray(T* A, T* B, T* C, T* D, int length) {
    for (int i = 0; i < length; ++i) {
        A[i] = B[i] + C[i] * D[i];
    }
}

template <typename T>
void cargarArray(T* array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = rand()/float(RAND_MAX)  ;
    }
}

int main() {
    for (int arrayLength = minArrayLength; arrayLength <= maxArrayLength; arrayLength *= 10) {
        float* A = new float[arrayLength];
        float* B = new float[arrayLength];
        float* C = new float[arrayLength];
        float* D = new float[arrayLength];

        cargarArray (A,arrayLength);
        cargarArray (B,arrayLength);
        cargarArray (C,arrayLength);
        cargarArray (D,arrayLength);
        
        auto start = high_resolution_clock::now();

        for (int iteration = 0; iteration < numIterations; ++iteration) {
            processArray(A, B, C, D, arrayLength);
        }

        auto end = high_resolution_clock::now();
        duration<double, std::milli> duration = end - start;

        cout << "Tamanio array: "    ;
        cout << setw(10)  << arrayLength << " - ";
        cout << "Tiempo: ";             
        cout << setw(10)  << fixed << setprecision(2) << duration.count() << " ms";
        cout << endl;

        delete[] A;
        delete[] B;
        delete[] C;
        delete[] D;
    }

    return 0;
}
