#pragma once
#include <iostream>
#include <string>
#include "CPersona.h"

using std::string;

class CUsuario : protected CPersona {

public:
    CUsuario() {}
    CUsuario(string n, string a, short e, int ndc, string c) : CPersona(n,a,e,ndc,c) {

    }

    string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(numero_de_celular) + "\nContrasenia: " + contrasenia + "\n\n";
    }

    int get_numero_celular() {
        return numero_de_celular;
    }
    string get_contrasenia() {
        return contrasenia;
    }
    string get_nombre() {
        return nombre;
    }
};
