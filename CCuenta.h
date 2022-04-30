#pragma once
#include <iostream>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CLista.h"
#include "Archivo.h"

// TODO falta desarrollar la classe CCuenta

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CCuenta {

public:
    CCuenta(CUsuario obj) { // Corre si el obj pasado es de usuario
        cout << "Cuento usuario works!\n";
    }
    CCuenta(CTaxista obj) { // Corre si el obj pasado es de taxista
        cout << "Cuenta taxista works!\n";
    }
};
