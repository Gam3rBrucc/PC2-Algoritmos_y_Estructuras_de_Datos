#pragma once
#include <iostream>
#include "CPersona.h"
#include "CAutomovil.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CTaxista : protected CPersona {
protected:
    CAutomovil automovil;
public:
    CTaxista() {}
    CTaxista(string n, string a, short e, int ndc, string c, CAutomovil au) : CPersona(n,a,e,ndc,c) {
        automovil = au;
    }

    string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(numero_de_celular) + "\nAutomovil: " + automovil.info() + "\nContrasenia: " + contrasenia + "\n\n";
    }

    int get_numero_celular() {
        return numero_de_celular;
    }
    string get_contrasenia() {
        return contrasenia;
    }
};
