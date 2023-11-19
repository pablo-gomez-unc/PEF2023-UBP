#include <iostream>
#include <thread>
using namespace std;

const int n_hilos = 5;

void funcion_hilo (int i) {
    cout << i << endl;
}

int main () {
    thread threads [n_hilos];
    for (int i = 0; i<n_hilos; i++) {
        threads[i] = thread(funcion_hilo, i+1);
    }

    cout << "Todos los threads lanzados ... " << endl;

    for (int i = 0; i<n_hilos; i++) {
        threads[i].join();
    }

    return 0;
}