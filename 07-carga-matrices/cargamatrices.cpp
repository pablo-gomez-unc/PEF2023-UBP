#include <iostream>
using namespace std;

void cargarPorFilas(double* matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
             matriz[i * columnas + j] = 0.0;
        }
    }
}

void cargarPorColumnas(double* matriz, int filas, int columnas) {
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            matriz[i * columnas + j] = 0.0;
        }
    }
}

void cargarLinealmente(double* matriz, int filas, int columnas) {
    for (int i = 0; i < filas * columnas; i++) {
        matriz[i] = 0.0;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <filas> <columnas>" << endl;
        return 1;
    }
    int filas = atoi(argv[1]);
    int columnas = atoi(argv[2]);

    if (filas <= 0 || columnas <= 0) {
        cout << "Las dimensiones de la matriz deben ser mayores que cero." << endl;
        return 1;
    }

    double* matriz = new double[filas * columnas];
 
    cargarPorFilas(matriz, filas, columnas);
    cargarPorColumnas(matriz, filas, columnas);
    cargarLinealmente(matriz, filas, columnas);

    delete[] matriz;

    return 0;
}
