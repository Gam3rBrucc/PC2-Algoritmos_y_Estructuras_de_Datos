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
        printf("\t[3] Generar datos\n");
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
        } else if(input == '3') {
            generar_datos(lista_usuarios, lista_taxistas);
            printf("\n\n~Datos generados exitosamente!\n");
            CMenu(lista_usuarios, lista_taxistas);
        } else printf("\n\n\t~ERROR~\n\n"); // Solo debe correr y hay un error
    }

    char revisar_input(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != 's' && in != 'S' && in != 'a' && in != 'A' && in != '3') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input(ingr);
        } else return ingr;
    }

    void generar_datos(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        for(int i=0; i<1000000; ++i) {
            lista_usuarios->push_back(CUsuario(nombre(), apellido(), contrasenia(), rand() % 62 + 18, rand() % 888888888 + 111111111));
            lista_taxistas->push_back(CTaxista(nombre(), apellido(), contrasenia(), rand() % 62 + 18, rand() % 888888888 + 111111111, CAutomovil(carro(), placa())));
        }
        lista_usuarios->erase(lista_usuarios->begin());
        lista_taxistas->erase(lista_taxistas->begin());
    }
    std::string nombre() {
        std::string nombres[50] = {"David","Maria","Jose","Nushi","Mohammed","Wei","Ahmed","Yan","Ali","Abdul","Ana",
                                   "Ying","Juan","Mary","Jean","Luis","Robert","Carlos","Antonio","Joseph",
                                   "Hong","Marie","Daniel","Bruce","Joaquin","Cesar","Angelis","Andres","Joana",
                                   "Olga","William","Sergey","Patricia","Paul","Emmanuel","Sandra","Mario","Luigi",
                                   "Tatyana","Martha","Christian","Sarah","Ivan","Carmen","Brian","Sebastian",
                                   "Fernando","Gloria","Denis","Oscar"};
        return nombres[rand() % 50];
    }
    std::string apellido() {
        std::string apellidos[50] = {"Garcia","Ruiz","Romero","Suarez","Fernandez","Gonzales","Rodriguez","Lopez","Martinez",
                                     "Sanchez","Perez","Gomez","Torres","Castillo","Marroquin","Mendez","Ortiz","Reyes",
                                     "Ramos","Morales","Rivera","Alvarez","Castro","Soto","Guzman","Ojeda","Salas",
                                     "Espinoza","Vega","Cortez","Santos","Duran","Leon","Calderon","Pacheco","Velazquez",
                                     "Tapia","Villa","Palacios","Espinoza","Alayza","Parra","Follano","Suclla",
                                     "Tomasio","Quiroz","Begazo","Reynoso","Sandiga","Malaga"};
        return apellidos[rand() % 50];
    }
    std::string carro() {
        std::string nombres[25] = {"Cooper","Toyota","Ford","Ferrari","Kia","Fiat","Dodge","Subaru",
                                   "Suzuki","Tesla","Mitsubishi","Pontiac","Nissan","Acura","BMW",
                                   "Maserati","Volvo","Honda","Mercedes","GMT","Audi","Jeep","Volkswagen",
                                   "Chevrolet","Porsche"};
        return nombres[rand() % 25];
    }
    std::string contrasenia() {
        std::string c = "";
        short n;
        for(int i=4; i<rand() % 8 + 8; ++i) {
            n = rand() % 3;
            c += char((n==0)*(rand() % 26 + 65) + (n==1)*(rand() % 26 + 97) + (n==2)*(rand() % 10 + 48));
        }
        return c;
    }
    std::string placa() {
        std::string c = "";
        c += char(rand() % 26 + 65);
        c += char(rand() % 26 + 65);
        c += char(rand() % 26 + 65);
        c += "-";
        c += char(rand() % 8 + 49);
        c += char(rand() % 8 + 49);
        c += char(rand() % 8 + 49);
        return c;
    }
};
