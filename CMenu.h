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
        cout << "\t[3] Salir de la app\n\n";
        cout << "Por favor elija una opcion: ";

        string input;
        cin >> input;

        while(input != "1" && input != "2" && input != "3" && input != "admin") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        short opcion;
        if(input == "1") opcion = 1;
        else if(input == "2") opcion = 2;
        else if(input == "3") opcion = 3;
        else if(input == "admin") opcion = -1;
        else cout << "\n\n\t~ERROR~\n\n";

        switch(opcion) {
            case 1: // Login
                CLogin();
                CMenu();
                break;
            case 2: // Registro
                CRegistro();
                CMenu();
                break;
            case 3: // Salir (terminar programa)
                cout << "=============================================\n";
                cout << "Gracias por usar nuesto app, hasta luego! (^o^)/\n";
                cout << "=============================================\n";
                break;
            case -1: // modo admin fachero facherito
                CAdmin();
                CMenu();
                break;

        }
    }
};
