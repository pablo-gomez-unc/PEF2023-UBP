//
// Created by Roberto Pablo on 09/11/2023.
//
#include <iostream>

using namespace std;

const int N = 3;

int main() {
    int A[N][N] = {1,2,3,4,5,6,7,8,9};
    int B[N][N] = {1,2,3,4,5,6,7,8,9};
    int C[N][N] = {0};

    for (int i = 0; i < N-1 ; i++) {
        for (int j = 1; j < N; j++) {
            A [i][j] = A[i+1][j-1] * B[i][j];
            C [i][j] = B[j][i];
        }
    }

    for (int i = 0; i < N ; i++) {
        for (int j= 0; j< N ; j++) cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N ; i++) {
        for (int j= 0; j<N  ; j++) cout << B[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N ; i++) {
        for (int j= 0; j< N ; j++) cout << C[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}