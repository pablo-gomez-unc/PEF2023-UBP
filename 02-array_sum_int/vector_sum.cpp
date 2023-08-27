#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;
using namespace std::chrono;

const int numIterations = 1000;  
const int minVectorLength = 16;
const int maxVectorLength = 16000000;

template <typename T>
void processVector(vector<T>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = vector[i] + 3;
    }
}

int main() {
    for (int vectorLength = minVectorLength; vectorLength <= maxVectorLength; vectorLength *= 10) {
        //vector<float> testedVector(vectorLength);
        vector<double> testedVector(vectorLength);
        //vector<int> testedVector(vectorLength);
        //vector<long> testedVector(vectorLength);

        auto start = high_resolution_clock::now();

        for (int iteration = 0; iteration < numIterations; ++iteration) {
            processVector(testedVector);
        }

        auto end = high_resolution_clock::now();
        duration<double, std::milli> duration = end - start;

        cout << "Tamanio vector: "    ;
        cout << setw(10)  << vectorLength << " - ";
        cout << "Tiempo: ";             
        cout << setw(10)  << fixed << setprecision(2) << duration.count() << " ms";
        cout << endl;
    }

    return 0;
}
