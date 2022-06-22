#pragma once
#ifndef UNTITLED10_CREGISTRO_H
#define UNTITLED10_CREGISTRO_H

#endif //UNTITLED10_CREGISTRO_H
#include <iostream>
#include <chrono>
#include <thread>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CAutomovil.h"
#include "Archivo.h"
class CRegistro {
public:
    CRegistro(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("==================== Registro ====================\n");
        printf("Que tipo que cuenta quisiera crear?\n\n");
        printf("\t[1] Cuenta de pasajero\n");
        printf("\t[2] Cuenta de taxista\n");
        printf("\t[R] Regresar a pagina anterior\n\n");
        printf("Elija una opcion: ");

        char input;
        scanf(" %c",&input);
        input = revisar_input(input);

        std::string nombre, apellido, contrasenia;
        std::string modelo_auto = "-";
        std::string placa_auto = "-";
        short edad;
        int numero_de_celular;
        CAutomovil *automovil;

        if (input == '1') { // Creacion de cuenta de pasajero
            printf("================= Ingreso de datos =================\n\n");
            printf("\tNombre: ");
            std::cin >> nombre;
            printf("\tApellido: ");
            std::cin >> apellido;
            printf("\tEdad: ");
            scanf("%hi", &edad);
            printf("\tNumero de celular: ");
            scanf("%d", &numero_de_celular);
            printf("\tConstrasenia: ");
            std::cin >> contrasenia;

            printf("\nCreando cuenta...\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            if (verificarCelular(numero_de_celular, lista_usuarios)) {
                lista_usuarios->push_back(CUsuario(nombre, apellido, contrasenia, edad, numero_de_celular));
                printf("Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n");
            } else
                printf("\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor registrese de nuevo usando otro numero de celular\n");

            std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        } else if (input == '2') { // Creacion de cuenta de taxista
            printf("================= Ingreso de datos =================\n\n");
            printf("\tNombre: ");
            std::cin >> nombre;
            printf("\tApellido: ");
            std::cin >> apellido;
            printf("\tEdad: ");
            scanf("%hi", &edad);
            printf("\tNumero de celular: ");
            scanf("%d", &numero_de_celular);
            printf("\tConstrasenia: ");
            std::cin >> contrasenia;

            printf("\nDesea tambien registrar su automovil que usara para llevar a pasajeros?\n");
            printf("Puede hacerlo luego si desea, pero no podra recojer pasajeros hasta que tenga un automovil registrado\n");
            printf("\t[S] Si");
            printf("\n\t[N] No");
            printf("\nPor favor elija una respeusta: ");

            input = '-';
            scanf(" %c", &input);
            input = revisar_input1(input);

            if (input == 's' || input == 'S') {
                printf("\tModelo de automovil: ");
                std::cin >> modelo_auto;
                printf("\tPlaca de automovil: ");
                std::cin >> placa_auto;
            } else if (input == 'n' || input == 'N') {
                modelo_auto = "N/A";
                placa_auto = "N/A";
            } else printf("\n\n\t~ERROR~\n\n");

            printf("\nCreando cuenta...\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            if (verificarCelular(numero_de_celular, lista_taxistas)) {
                lista_taxistas->push_back(CTaxista(nombre, apellido, contrasenia, edad, numero_de_celular, CAutomovil(modelo_auto, placa_auto)));
                printf("Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n");
            } else
                printf("\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor registrese de nuevo usando otro numero de celular\n");

            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        } else if (input == 'r' || input == 'R') { // Regresar a pagina anterior
        } else printf("\n\n\t~ERROR~\n\n");
    }

    bool verificarCelular(int celular, std::vector<CUsuario>* lista_usuarios) {
        bool num_cel_disponible = true; // Este bloque revisa si el numero de celular que ingreso el usuario ya esta siendo usada
        for (auto i: *lista_usuarios)
            if (i.get_num_cel() == celular)
                num_cel_disponible = false;
        return num_cel_disponible;
    }
    bool verificarCelular(int celular, std::vector<CTaxista>* lista_taxistas) {
        bool num_cel_disponible = true; // Este bloque revisa si el numero de celular que ingreso el usuario ya esta siendo usada
        for (auto i: *lista_taxistas)
            if (i.get_num_cel() == celular)
                num_cel_disponible = false;
        return num_cel_disponible;
    }

    char revisar_input(char in) {
        char ingr = in;
        if (in != '1' && in != '2' && in != 'r' && in != 'R') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            std::cin >> ingr;
            return revisar_input(ingr);
        } else return ingr;
    }

    char revisar_input1(char in) {
        char ingr = in;
        if (in != 's' && in != 'S' && in != 'n' && in != 'N') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            std::cin >> ingr;
            return revisar_input(ingr);
        } else return ingr;
    }
};
