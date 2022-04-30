#pragma once
#include <iostream>
#include "CLista.h"
#include "Archivo.h"
#include "CUsuario.h"
#include "CTaxista.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CAdmin {

public:
    CAdmin() {
        cout << "\n=================== Modo Admin ===================\n";
        cout << "Bienvenido al modo admin!!!\n";
        cout << "\t[1] Ver informacion de todos los usuarios registrados\n";
        cout << "\t[2] Eliminar usuario\n";
        cout << "\t[R] Regresar\n";
        cout << "\nElija una opcion: ";

        string input;
        cin >> input;

        while(input != "1" && input != "2" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        short opcion;
        if(input == "1") opcion = 1;
        else if(input == "2") opcion = 2;
        else if(input == "r" || input == "R") opcion = 3;
        else cout << "\n\n\t~ERROR~\n\n";

        CLista<CUsuario> lista_usuarios;
        CLista<CTaxista> lista_taxistas;

        leerObjetosGuardados<CUsuario>("usuarios.bin", &lista_usuarios);
        leerObjetosGuardados<CTaxista>("taxistas.bin", &lista_taxistas);

        switch(opcion) {
            case 1:
                cout << "====================== Lista de usuarios ======================\n\n";
                lista_usuarios.recorrer_inicio([](CUsuario o){cout << o.mostrar_info();});
                cout << "====================== Lista de taxistas ======================\n\n";
                lista_taxistas.recorrer_inicio([](CTaxista o){cout << o.mostrar_info();});
                break;
            case 2:

                break;
            case 3:
                break;
        }
    }
};
