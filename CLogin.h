#pragma once
#include <iostream>
#include "CUsuario.h"
#include "CTaxista.h"
#include "Archivo.h"
#include "CLogin.h"
#include "CCuenta.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define ARCH_U "usuarios.bin" // ARCH_U se refiere a ARCHivo Usuarios
#define ARCH_T "taxistas.bin" // ARCH_T se refiere a ARCHivo Taxistas

class CLogin {
    int numero_de_celular;
    string contrasenia;

    CUsuario cuenta_usuario; // Aqui se guardara el objeto de la cuenta de usuario si se encuentra
    CTaxista cuenta_taxista; // Aqui se guardara el objeto de la cuenta de taxista si se encuentra
    CLista<CUsuario> lista_usuarios;
    CLista<CTaxista> lista_taxistas;

    bool encontro_usuario = false;
    bool encontro_taxista = false;
public:
    CLogin() {


        cout << "================== Login ==================\n\n";
        cout << "\tNumero de celular: ";
        cin >> numero_de_celular;
        cout << "\tContrasenia: ";
        cin >> contrasenia;

        leerObjetosGuardados<CUsuario>(ARCH_U, &lista_usuarios);
        leerObjetosGuardados<CTaxista>(ARCH_T, &lista_taxistas);


        lista_usuarios.recorrer_inicio([=](CUsuario o){ // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
           if(numero_de_celular == o.get_numero_celular() && contrasenia == o.get_contrasenia()) {
               cuenta_usuario = o;
               encontro_usuario = true;
           }
        });
        lista_taxistas.recorrer_inicio([=](CTaxista o){ // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
            if(numero_de_celular == o.get_numero_celular() && contrasenia == o.get_contrasenia()) {
                cuenta_taxista = o;
                encontro_taxista = true;
            }
        });

        if(encontro_usuario) {
            cout << "\nBienvenido " << cuenta_usuario.get_nombre() << "!!!\n";
            CCuenta cuenta_U(cuenta_usuario); // Crea un objeto de CCuenta para poder pasarle el objecto de usuario
        }
        else if(encontro_taxista) {
            cout << "\nBienvenido " << cuenta_taxista.get_nombre() << "!!!\n";
            CCuenta cuenta_T(cuenta_taxista); // Crea un objeto de CCuenta para poder pasarle el objecto de taxista
        }
        else cout << "\n~~No se encontro ningun cuenta con ese numero de celular o contrasenia\n";
    }
};
