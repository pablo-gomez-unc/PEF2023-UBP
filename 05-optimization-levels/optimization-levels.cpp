#include <iostream>
#include <cmath> 
using namespace std;

int main () {
    const int N = 1000000;
    double A[N];

    for (int i=0; i<N ; ++i) {
        A[i] = 3.1415927;
    }

    for (int i = 0; i < N; ++i) {
        A[i] = A[i] * sin(A[i]) + cos(A[i]);
    } 

    cout << "Done" << endl;
    return 0;
}