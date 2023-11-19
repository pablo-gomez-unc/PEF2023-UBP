#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

const int n_hilos = 100;
atomic <int> valor (0);

void funcion_atomic (int i) {
    valor.fetch_add(1);
    cout << "i :" << i << " valor:" << valor.load() << endl;
}

int main () {
    thread threads [n_hilos];
    for (int i = 0; i<n_hilos; i++) {
        threads[i] = thread(funcion_atomic, i+1);
    }
    cout << "Todos los threads lanzados ... " << endl;

    for (int i = 0; i<n_hilos; i++) {
        threads[i].join();
    }
    cout << "Todos los threads finalizados ... " << valor.load() << endl;
    return 0;
}