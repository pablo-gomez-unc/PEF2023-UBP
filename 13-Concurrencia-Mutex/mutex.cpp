#include <iostream>
#include <thread>
using namespace std;

const int n_hilos = 100;
mutex mi_mutex;
int valor = 0;

void funcion_mutex (int i) {
    //mi_mutex.lock();
    valor++;
    cout << "i :" << i << " valor:" << valor << endl;
    //mi_mutex.unlock();
}

void funcion_lock_guard (int i) {
    lock_guard<mutex> lock(mi_mutex);
    valor++;
    cout << "i :" << i << " valor:" << valor << endl;
}

void funcion_unique_lock (int i) {
    unique_lock<mutex> lock(mi_mutex);
    valor++;
    cout << "i :" << i << " valor:" << valor << endl;
    lock.unlock();
    lock.lock();
    valor++;
    cout << "i :" << i << " valor:" << valor << endl;
    lock.unlock();
}


int main () {
    thread threads [n_hilos];
    for (int i = 0; i<n_hilos; i++) {
        //threads[i] = thread(funcion_mutex, i+1);
        //threads[i] = thread(funcion_lock_guard, i+1);
        threads[i] = thread(funcion_unique_lock, i+1);
    }
    cout << "Todos los threads lanzados ... " << endl;

    for (int i = 0; i<n_hilos; i++) {
        threads[i].join();
    }
    cout << "Todos los threads finalizados ... " << endl;

    return 0;
}