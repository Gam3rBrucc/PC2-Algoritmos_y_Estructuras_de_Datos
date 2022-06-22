#pragma once
#ifndef UNTITLED10_CLOGIN_H
#define UNTITLED10_CLOGIN_H

#endif //UNTITLED10_CLOGIN_H
#include <iostream>
#include <vector>
#include "CUsuario.h"
#include "CTaxista.h"
#include "Archivo.h"
#include "CCuenta.h"
class CLogin {
    int numero_de_celular;
    std::string contrasenia;

    CUsuario cuenta_usuario; // Aqui se guardara el objeto de la cuenta de usuario si se encuentra
    CTaxista cuenta_taxista; // Aqui se guardara el objeto de la cuenta de taxista si se encuentra

    bool encontro_usuario = false;
    bool encontro_taxista = false;
public:
    CLogin(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("================== Login ==================\n\n");
        printf("\tNumero de celular: ");
        scanf("%d",&numero_de_celular);
        printf("\tContrasenia: ");
        std::cin >> contrasenia;

        for(auto i : *lista_usuarios) {
            if (numero_de_celular == i.get_num_cel() && contrasenia == i.get_password()) {
                cuenta_usuario = i;
                encontro_usuario = true;
                break;
            }
        }
        for(auto i : *lista_taxistas) {
            if (numero_de_celular == i.get_num_cel() && contrasenia == i.get_password()) {
                cuenta_taxista = i;
                encontro_taxista = true;
                break;
            }
        }
        if(encontro_usuario) {
            printf("\nBienvenido %s!!!\n",cuenta_usuario.get_nombre().c_str());
            CCuenta cuenta_U(cuenta_usuario, lista_usuarios, lista_taxistas); // Crea un objeto de CCuenta para poder pasarle el objecto de usuario
        } else if(encontro_taxista) {
            printf("\nBienvenido %s!!!\n",cuenta_taxista.get_nombre().c_str());
            CCuenta cuenta_T(cuenta_taxista, lista_usuarios, lista_taxistas); // Crea un objeto de CCuenta para poder pasarle el objecto de taxista
        } else printf("\n~~No se encontro ningun cuenta con ese numero de celular o contrasenia\n");
    }
};
