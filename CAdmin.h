#pragma once
#ifndef UNTITLED10_CADMIN_H
#define UNTITLED10_CADMIN_H

#endif //UNTITLED10_CADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include "Archivo.h"
#include "CUsuario.h"
#include "CTaxista.h"

// TODO Implementa algoritmo de ordenamiento de stl
// TODO hacer que la opcion 1 muestre 10 objetos a la vez y que el usuario pueda elegir que numero de pagina ver

class CAdmin {
    bool encontro_usuario = false;
    bool encontro_taxista = false;
public:
    CAdmin(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("=================== Modo Admin ===================\n");
        printf("\n\t[1] Ver informacion de todos las cuentas registradas\n");
        printf("\t[2] Eliminar cuenta\n");
        printf("\t[R] Regresar\n");
        printf("\nElija una opcion: ");

        char input;
        scanf(" %c",&input);
        input = revisar_input(input);

        if (input == '1') { // Recorre las listas de usuarios y taxistas mostrando toda la informacion de estas
            printf("====================== Lista de usuarios ======================\n\n");
            for(auto i : *lista_usuarios) printf("%s", i.mostrar_info().c_str());
            printf("====================== Lista de taxistas ======================\n\n");
            for(auto i : *lista_taxistas) printf("%s", i.mostrar_info().c_str());

            CAdmin(lista_usuarios, lista_taxistas);

        } else if (input == '2') { // Eliminar cuenta
            printf("Para eliminar esta cuenta necesitas ingresar el numero de celular y contrasenia del usuario.\n\n");
            printf("\tNumero de celular: ");

            int numero_de_celular;
            scanf("%d", &numero_de_celular);
            printf("\tContrasenia: ");
            std::string contrasenia;
            std::cin >> contrasenia;

            long iU = 0, iT = 0; // indiceUsuario, indiceTaxista
            for(auto i : *lista_usuarios) {
                if(numero_de_celular == i.get_num_cel() && contrasenia == i.get_password()) {
                    encontro_usuario = true;
                    break;
                }
                ++iU;
            }
            for(auto i : *lista_taxistas) {
                if(numero_de_celular == i.get_num_cel() && contrasenia == i.get_password()) {
                    encontro_taxista = true;
                    break;
                }
                ++iT;
            }

            if (encontro_usuario) { // Si el usuario de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el usuario que el admin a eligido, efectivamente eliminandolo
                lista_usuarios->erase(lista_usuarios->begin()+iU);
            } else if (encontro_taxista) { // Si el taxista de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el taxista que el admin a eligido, efectivamente eliminandolo
                lista_taxistas->erase(lista_taxistas->begin()+iT);
            } else printf("\n~~No se encontro ningun cuenta con ese numero de celular o contrasenia\n");

            if (encontro_usuario || encontro_taxista) printf("\n~~Se logro eliminar la cuenta!\n");

            CAdmin(lista_usuarios, lista_taxistas);
        } else if(input == 'r' || input == 'R') { // Regresar pagina
        } else printf("\n\n\t~ERROR~\n\n");
    }
    char revisar_input(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != 'r' && in != 'R') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c",&ingr);
            return revisar_input(ingr);
        } else return ingr;
    }
};
