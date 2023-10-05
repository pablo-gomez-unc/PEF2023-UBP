#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void initIndices (int **M , int f , int c){ 
    srand(time(0));

    for (int i = 0; i < f; i++) {
        M[i] = new int[c];
        for (int j = 0; j < c; j++) {
            M[i][j] = rand() % 10;
        }
    }
}

void imprimir (int **M , int f , int c){ 
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(7) << M[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}

int main (int argc, char* argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int p = atoi(argv[3]);
    
    //int n = 2; int m = 2; int p = 2;

    int **A = new int*[n]; initIndices(A, n, m);
    int **B = new int*[m]; initIndices(B, m, p);
    int **R = new int*[n]; initIndices(R, n, p);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int suma = 0;
            for (int k = 0; k < p; k++) {
                suma += A[i][k] * B[k][j];
            }
            R [i][j] = suma;
        }   
    }

    //imprimir (R, n, m) ;
}
