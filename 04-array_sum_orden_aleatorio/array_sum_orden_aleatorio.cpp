#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

const long N = 1000000;

int partition(float* a, int start, int end)
{
    float pivot = a[end];
    int pIndex = start;
 
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex], a[end]);
    return pIndex;
}

void quicksort(float* a, int start, int end){
    if (start >= end) {
        return;
    } 
    float pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
}

void cargar (float array[]) {
    for (int i = 0; i < N; i++) {
        array[i] = 0.001f + (rand() % 10000000);    
    }
}

void sumar (float array[]) {
    auto start = chrono::high_resolution_clock::now();
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += array[i];
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;
    cout << "Resultado: " << sum << endl; 
}

int main() {
    float *array = new float[N];        
    cargar(array);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    sumar (array);
    quicksort (array, 0 , N);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    sumar (array);
    return 0;
}
