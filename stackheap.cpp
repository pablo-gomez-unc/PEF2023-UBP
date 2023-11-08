//
// Created by Roberto Pablo on 07/11/2023.
//
#include <cstdio>
#include <vector>
using namespace std;

struct Rectangulo {
    int ancho;
    int alto;
};

void funcion1 () {
    vector<Rectangulo*> *lista = new vector<Rectangulo*>();
    Rectangulo *a = new Rectangulo();
    a->ancho = 10;
    a->alto = 20;
    lista->push_back(a);
    a -> ancho = 1;

    delete a;
    delete lista;
}

int main()
{
    funcion1();

}