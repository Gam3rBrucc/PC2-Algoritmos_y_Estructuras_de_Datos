#pragma once
#ifndef UNTITLED10_CMENU_H
#define UNTITLED10_CMENU_H

#endif //UNTITLED10_CMENU_H
#include <iostream>
#include <vector>
#include "CLogin.h"
#include "CRegistro.h"
#include "CAdmin.h"
#include "CUsuario.h"
#include "CTaxista.h"
using std::cout;

class CMenu {

public:
    CMenu(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("=================== Menu ===================\n\n");
        printf("\t[1] Login\n");
        printf("\t[2] Registro\n");
        printf("\t[S] Salir de la app\n\n");
        printf("Por favor elija una opcion: ");

        char input;
        scanf(" %c",&input);
        input = revisar_input(input);

        if(input == '1') { // Login
            CLogin(lista_usuarios, lista_taxistas);
            CMenu(lista_usuarios, lista_taxistas);
        } else if(input == '2') { // Registro
            CRegistro(lista_usuarios, lista_taxistas);
            CMenu(lista_usuarios, lista_taxistas);
        } else if(input == 's' || input == 'S') { // Salir de la app (terminar programa)
            printf("=============================================\n");
            printf("Gracias por usar nuesto app, hasta luego! (^o^)/\n");
            printf("=============================================\n");
        } else if(input == 'a' || input == 'A') { // Modo admin fachero facherito
            printf("\nBienvenido al modo admin!!!\n");
            CAdmin(lista_usuarios, lista_taxistas);
            CMenu(lista_usuarios, lista_taxistas);
        } else printf("\n\n\t~ERROR~\n\n"); // Solo debe correr y hay un error
    }

    char revisar_input(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != 's' && in != 'S' && in != 'a' && in != 'A') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input(ingr);
        } else return ingr;
    }
};
