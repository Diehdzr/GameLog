#include <string>

class usuario {
private:
    std::string nombre;
    int edad;

public:
    usuario() : nombre(""), edad(0) {};
    usuario(std::string n, int e) :
        nombre(n), edad(e) {};

    std::string getNombre();
    int getEdad();

    void setNombre(std::string n);
    void setEdad(int e);
};

std::string usuario::getNombre() {
    return nombre;
}

int usuario::getEdad() {
    return edad;
}

void usuario::setNombre(std::string n) {
    nombre = n;
}

void usuario::setEdad(int e) {
    edad = e;
}
