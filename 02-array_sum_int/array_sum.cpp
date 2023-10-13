#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const int numIterations = 1000;
const int minArrayLength = 16;
const int maxArrayLength = 16000000;

template <typename T>
void processArray(T* array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = array[i] + 3;
    }
}

int main() {
    for (int arrayLength = minArrayLength; arrayLength <= maxArrayLength; arrayLength *= 10) {
        float* testedArray = new float[arrayLength];
        //double* testedArray = new double[arrayLength];
        //int* testedArray = new int[arrayLength];
        //long* testedArray = new long[arrayLength];

        auto start = high_resolution_clock::now();

        for (int iteration = 0; iteration < numIterations; ++iteration) {
            processArray(testedArray, arrayLength);
        }

        auto end = high_resolution_clock::now();
        duration<double, std::milli> duration = end - start;

        cout << "Tamanio array: "    ;
        cout << setw(10)  << arrayLength << " - ";
        cout << "Tiempo: ";             
        cout << setw(10)  << fixed << setprecision(2) << duration.count() << " ms";
        cout << endl;

        delete[] testedArray;
    }

    return 0;
}
