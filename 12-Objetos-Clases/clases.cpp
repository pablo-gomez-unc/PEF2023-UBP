#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    Persona() : edad(18), nombre("Natalia"), apellido("Natalia"), altura(0.0f) {}
    Persona(int e, const string& n, const string& a, float h) : edad(e), nombre(n), apellido(a), altura(h) {}
    explicit Persona(const string& apellidos) : edad(18), nombre("nombre"), apellido(apellidos), altura(1.8f) {}
    Persona(const Persona& otra) : edad(otra.edad), nombre(otra.nombre), apellido(otra.apellido), altura(otra.altura) {
        cout << "Constructor de copia" << endl;
    }
    Persona(Persona&& otra) noexcept : edad(otra.edad), nombre(move(otra.nombre)), apellido(move(otra.apellido)), altura(otra.altura) {
        cout << "Constructor de movimiento" << endl;
    }

    int obtenerEdad() const {
        return edad;
    }
    const string& obtenerNombre() const {
        return nombre;
    }
    const string& obtenerApellido() const {
        return apellido;
    }
    float obtenerAltura() const {
        return altura;
    }

private:
    int edad;
    string nombre;
    string apellido;
    float altura;
};

int main() {
    Persona personaPorDefecto;
    Persona personaConParametros(25, "Juan", "Perez", 1.75);
    Persona personaConApellido = Persona("Lopez");

    cout << "Edad: " << personaPorDefecto.obtenerEdad() << endl;
    cout << "Nombre: " << personaPorDefecto.obtenerNombre() << endl;
    cout << "Apellido: " << personaPorDefecto.obtenerApellido() << endl;
    cout << "Altura: " << personaPorDefecto.obtenerAltura() << endl;

    return 0;
}
