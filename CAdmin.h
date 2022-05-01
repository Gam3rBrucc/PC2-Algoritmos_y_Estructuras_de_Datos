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
        cout << "\n\t[1] Ver informacion de todos las cuentas registrados\n";
        cout << "\t[2] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n";
        cout << "\nElija una opcion: ";

        string input;
        cin >> input;

        while(input != "1" && input != "2" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        CLista<CUsuario> lista_usuarios;
        CLista<CTaxista> lista_taxistas;

        leerObjetosGuardados<CUsuario>("usuarios.bin", &lista_usuarios);
        leerObjetosGuardados<CTaxista>("taxistas.bin", &lista_taxistas);

        if(input == "1") { // Recorre las listas de usuarios y taxistas mostrando toda la informacion de estas
            cout << "====================== Lista de usuarios ======================\n\n";
            lista_usuarios.recorrer_inicio([](CUsuario o){cout << o.mostrar_info();});
            cout << "====================== Lista de taxistas ======================\n\n";
            lista_taxistas.recorrer_inicio([](CTaxista o){cout << o.mostrar_info();});
        } else if(input == "2") { // Eliminar cuenta
            // TODO falta desarrollar el case 2 en la clase CAdmin (eliminar usuario)
        } else if(input == "r" || input == "R") { // Regresar pagina
        } else cout << "\n\n\t~ERROR~\n\n";
    }
};
