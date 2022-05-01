#pragma once
#include <iostream>
#include "CLogin.h"
#include "CRegistro.h"
#include "CAdmin.h"

using std::cout;
using std::cin;
using std::string;

class CMenu {
public:
    CMenu() {
        cout << "=================== Menu ===================\n\n";
        cout << "\t[1] Login\n";
        cout << "\t[2] Registro\n";
        cout << "\t[S] Salir de la app\n\n";
        cout << "Por favor elija una opcion: ";

        string input;
        cin >> input;

        while(input != "1" && input != "2" && input != "s" && input != "S" && input != "admin") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Login
            CLogin();
            CMenu();
        } else if(input == "2") { // Registro
            CRegistro();
            CMenu();
        } else if(input == "s" || input == "S") { // Salir de la app (terminar programa)
            cout << "=============================================\n";
            cout << "Gracias por usar nuesto app, hasta luego! (^o^)/\n";
            cout << "=============================================\n";
        } else if(input == "admin") { // Modo admin fachero facherito
            cout << "\nBienvenido al modo admin!!!";
            CAdmin();
            CMenu();
        } else cout << "\n\n\t~ERROR~\n\n"; // Solo debe correr y hay
    }
};
