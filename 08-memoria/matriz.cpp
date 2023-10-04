#include <iostream>
#include <cstdint>
#define SIZE 10

uint32_t** reserve_matrix() {
    uint32_t **m = new uint32_t*[SIZE];
    for (uint32_t i=0; i < SIZE; i++)
        m[i] = new uint32_t[SIZE];
    return m;   
}

void release_matrix(uint32_t** m) {
    for (uint32_t i=0; i < SIZE; i++)
        delete [] m[i];
    delete [] m;
}

void populate_matrix(uint32_t** m) {
    for (uint32_t i=0; i < SIZE; i++)
        for (uint32_t j=0; j < SIZE; j++)
            m[i][j] = j + (i*SIZE);
}

void print_matrix(uint32_t** m) {
    for (uint32_t i=0; i < SIZE; i++) {
        for (uint32_t j=0; j < SIZE; j++)
            std::cout << m[i][j] << " ";
        std::cout << "\n";
    }
}

void print_matrix_dirs(uint32_t** m) {
    std::cout << &m << std::endl;
    for (uint32_t i=0; i < SIZE; i++) {
            std::cout << &m[i] << std::endl;
    }
}

int main(void) {
    uint32_t **m;
    m = reserve_matrix();
    populate_matrix(m);
    print_matrix(m);
    print_matrix_dirs(m);
    release_matrix(m);
    return 0;
}