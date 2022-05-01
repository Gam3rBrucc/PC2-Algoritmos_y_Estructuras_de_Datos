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

#define ARCH_U "usuarios.bin" // ARCH_U se refiere a ARCHivo Usuarios
#define ARCH_T "taxistas.bin" // ARCH_T se refiere a ARCHivo Taxistas

class CAdmin {
    bool encontro_usuario = false;
    bool encontro_taxista = false;
public:
    CAdmin() {
        cout << "\n=================== Modo Admin ===================\n";
        cout << "\n\t[1] Ver informacion de todos las cuentas registradas\n";
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

        leerObjetosGuardados<CUsuario>(ARCH_U, &lista_usuarios);
        leerObjetosGuardados<CTaxista>(ARCH_T, &lista_taxistas);

        if(input == "1") { // Recorre las listas de usuarios y taxistas mostrando toda la informacion de estas
            cout << "====================== Lista de usuarios ======================\n\n";
            lista_usuarios.recorrer_inicio([](CUsuario o){cout << o.mostrar_info();});
            cout << "====================== Lista de taxistas ======================\n\n";
            lista_taxistas.recorrer_inicio([](CTaxista o){cout << o.mostrar_info();});

            CAdmin();

        } else if(input == "2") { // Eliminar cuenta
            cout << "Para eliminar esta cuenta necesitas ingresar el numero de celular y contrasenia del usuario.\n\n";
            cout << "\tNumero de celular: ";

            int numero_de_celular;
            cin >> numero_de_celular;
            cout << "\tContrasenia: ";
            string contrasenia;
            cin >> contrasenia;

            lista_usuarios.recorrer_inicio([=](CUsuario o){ // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
                if(numero_de_celular == o.get_numero_celular() && contrasenia == o.get_contrasenia()) encontro_usuario = true;
            });
            lista_taxistas.recorrer_inicio([=](CTaxista o){ // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
                if(numero_de_celular == o.get_numero_celular() && contrasenia == o.get_contrasenia()) encontro_taxista = true;
            });

            if(encontro_usuario) { // Si el usuario de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el usuario que el admin a eligido, efectivamente eliminandolo
                limpiarArchivo(ARCH_U);
                lista_usuarios.recorrer_inicio([=](CUsuario o){
                    if (numero_de_celular != o.get_numero_celular()) {
                        guardarObjeto(ARCH_U, o);
                    }
                });
            }
            else if(encontro_taxista) { // Si el taxista de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el taxista que el admin a eligido, efectivamente eliminandolo
                limpiarArchivo(ARCH_T);
                lista_taxistas.recorrer_inicio([=](CTaxista o){
                    if(numero_de_celular != o.get_numero_celular()) {
                        guardarObjeto(ARCH_T, o);
                    }
                });
            }
            else cout << "\n~~No se encontro ningun cuenta con ese numero de celular o contrasenia\n";

            if(encontro_usuario || encontro_taxista) cout << "\n~~Se logro eliminar la cuenta!\n";

            CAdmin();

        } else if(input == "r" || input == "R") { // Regresar pagina
        } else cout << "\n\n\t~ERROR~\n\n";
    }
};
