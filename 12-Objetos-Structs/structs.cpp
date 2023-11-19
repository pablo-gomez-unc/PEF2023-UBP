#include <string>
#include <iostream>
using namespace std;

struct Persona {
    int edad;
    string nombre;
    string apellido;
    float altura;

    //Persona () ;
    Persona () : edad(18), nombre("Natalia") , apellido("Natalia") , altura(0.0f) {}
    Persona(int e, const string& n, const string& a, double h) : edad(e), nombre(n), apellido(a), altura(h) {}
    explicit Persona (int edad){
        this->edad = edad;
        this->nombre = "nombre";
        this->apellido = "apellido";
        this->altura = 1.8f;
    }
    explicit Persona (const string& apellido) : edad(18), nombre("Natalia") , apellido(apellido) , altura(0.0f) {
        cout << "Explicito" << endl;
    }
    Persona(Persona& p) : edad(p.edad) , nombre(p.nombre) , apellido(p.apellido), altura(p.altura) {
        cout << "Copia" << endl;
    }
    Persona(Persona&& p) noexcept : edad(p.edad) , nombre(move(p.nombre)) , apellido(move(p.apellido)), altura(p.altura) {
        cout << "Movimiento" << endl;
    }
};

int main () {
    Persona p1 {37, "Pablo", "Gomez", 1.83f}; // Uniforme
    Persona p2 = {37, "Pablo", "Gomez", 1.83f};// Lista
    string apellido = "Richard";
    Persona p3 = Persona(apellido);
    Persona p4 = p3;
    Persona p5 = move(p3);
}

