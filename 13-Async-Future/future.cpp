#include <iostream>
#include <future>
#include <vector>
#include <mutex>
using namespace std;

std::mutex mutexCout;

inline int generarEnteroAleatorio(int i) {
    int delay = rand()%5000;
    int numero = rand() % 100;
    this_thread::sleep_for(chrono::milliseconds(delay));
    unique_lock<mutex> m (mutexCout);
    cout << "hilo: " << i << " delay: " << delay << " numero: " << numero << endl;
    m.unlock();
    return numero;
}

future<int> generarPromesaEnteroAleatorio(int i) {
    packaged_task<int(int)> task(generarEnteroAleatorio);
    future<int> future = task.get_future();
    thread(move(task),i).detach();
    return future;
}

int main() {
    auto currentTime = chrono::system_clock::now();
    auto durationSinceEpoch = currentTime.time_since_epoch();
    auto secondsSinceEpoch = chrono::duration_cast<chrono::seconds>(durationSinceEpoch);
    auto secondsAsInt = secondsSinceEpoch.count();
    srand(secondsAsInt);

    const int numPromesas = 100;
    vector<future<int>> promesas;

    for (int i = 0; i < numPromesas; ++i) {
        promesas.push_back(generarPromesaEnteroAleatorio(i+1));
    }

    for (int i = 0; i < numPromesas; ++i) {
        int resultado = promesas[i].get();
        cout << "Promesa " << i + 1 << ": " << resultado << endl;
    }

    return 0;
}
