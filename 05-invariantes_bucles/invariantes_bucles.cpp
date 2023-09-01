void compute(float A[], const float B[], float C, float D, float& E, float G[], int K, int N) {
    for (int I = 0; I < N; ++I) {
        A[I] = B[I] + C * D;
    }
    E = G[K];
}