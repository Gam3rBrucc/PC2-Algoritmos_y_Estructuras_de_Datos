#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CLogin {
    string numero_de_celular;
    string contrasenia;
public:
    CLogin() {
        cout << "================== Login ==================\n\n";
        cout << "\tUsuario: ";
        cin >> numero_de_celular;
        cout << "\tContrasenia: ";
        cin >> contrasenia;
        
        // TODO falta desarrollar la clase CLogin
    }
};
