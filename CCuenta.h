#pragma once
#include <iostream>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CLista.h"
#include "Archivo.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

// TODO falta desarrollar la classe CCuenta

class CCuenta {
    CUsuario usuario;
    CTaxista taxista;
public:
    CCuenta(CUsuario obj) { // Corre si el obj pasado es de usuario
        usuario = obj;
        cout << "====================== Cuenta ======================\n\n";
        cout << "\t[1] Ver datos de cuenta\n";
        cout << "\t[2] Ver historial de viajes\n";
        cout << "\t[3] Cambiar datos\n";
        cout << "\t[4] Pedir taxi\n";
        cout << "\t[5] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n\n";
        cout << "Elija una opcion: ";

        string input;
        cin >> input;
        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Ver datos de cuenta
            cout << "=============== Datos de cuenta ===============\n\n";
            cout << usuario.mostrar_info();
            CCuenta cuenta_U(usuario);
        } else if(input == "2") { // Ver historial de viajes

        } else if(input == "3") { // Cambiar datos

        } else if(input == "4") { // Pedir taxi

        } else if(input == "5") { // Eliminar cuenta

        } else if(input == "r" || input == "R") { // Regresar pagina

        } else cout << "\n\n\t~ERROR~\n\n";
    }
    CCuenta(CTaxista obj) { // Corre si el obj pasado es de taxista
        taxista = obj;
        cout << "====================== Cuenta ======================\n\n";
        cout << "\t[1] Ver datos de cuenta\n";
        cout << "\t[2] Ver historial de pasajeros\n";
        cout << "\t[3] Cambiar datos\n";
        cout << "\t[4] Buscar pasajero\n";
        cout << "\t[5] Registrar automovil\n";
        cout << "\t[6] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n\n";
        cout << "Elija una opcion: ";

        string input;
        cin >> input;
        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Ver datos de cuenta
            cout << taxista.mostrar_info();
            CCuenta cuenta_T(taxista);
        } else if(input == "2") { // Ver historial de viajes

        } else if(input == "3") { // Cambiar datos

        } else if(input == "4") { // Buscar pasajero

        } else if(input == "5") { // Registrar automovil

        } else if(input == "6") { // Eliminar cuenta

        } else if(input == "r" || input == "R") { // Regresar pagina

        } else cout << "\n\n\t~ERROR~\n\n";
    }
};
