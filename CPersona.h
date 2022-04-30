#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class CPersona {
protected:
    string nombre, apellido, contrasenia;
    short edad;
    int numero_de_celular;
public:
    CPersona() {}
    CPersona(string n, string a, short e, int ndc, string c) {
        nombre = n;
        apellido = a;
        edad = e;
        numero_de_celular = ndc;
        contrasenia = c;
    }
};
