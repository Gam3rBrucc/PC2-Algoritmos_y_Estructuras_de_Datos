#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CAutomovil.h"
#include "Archivo.h"

//Archivo donde se guardan usuarios = "usuarios.bin"
//Archivo donde se guardan taxistas = "taxistas.bin"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CRegistro {
public:
    CRegistro() {
        cout << "==================== Registro ====================\n";
        cout << "Que tipo que cuenta quisiera crear?\n\n";
        cout << "\t[1] Cuenta de pasajero\n";
        cout << "\t[2] Cuenta de taxista\n";
        cout << "\t[R] Regresar a pagina anterior\n\n";
        cout << "Elija una opcion: ";

        string input;
        cin >> input;

        while(input != "1" && input != "2" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        string nombre, apellido, contrasenia;
        string modelo_auto = "-";
        string placa_auto = "-";
        short edad;
        int numero_de_celular;
        CUsuario* cuenta_usuario;
        CTaxista* cuenta_taxista;
        CAutomovil* automovil;

        if(input == "1") { // Creacion de cuenta de pasajero
            cout << "================= Ingreso de datos =================\n\n";
            cout << "\tNombre: ";
            cin >> nombre;
            cout << "\tApellido: ";
            cin >> apellido;
            cout << "\tEdad: ";
            cin >> edad;
            cout << "\tNumero de celular: ";
            cin >> numero_de_celular;
            cout << "\tConstrasenia: ";
            cin >> contrasenia;

            cout << "\nCreando cuenta...\n";
            cuenta_usuario = new CUsuario(nombre, apellido, edad, numero_de_celular, contrasenia); // Crea objeto de usuario
            guardarObjeto<CUsuario>("usuarios.bin", *cuenta_usuario); // Guarda objecto de usuario en archivo
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            cout << "Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        } else if(input == "2") { // Creacion de cuenta de taxista
            cout << "================= Ingreso de datos =================\n\n";
            cout << "\tNombre: ";
            cin >> nombre;
            cout << "\tApellido: ";
            cin >> apellido;
            cout << "\tEdad: ";
            cin >> edad;
            cout << "\tNumero de celular: ";
            cin >> numero_de_celular;
            cout << "\tConstrasenia: ";
            cin >> contrasenia;

            cout << "\nDesea tambien registrar su automovil que usara para llevar a pasajeros?\n";
            cout << "Puede hacerlo luego si desea, pero no podra recojer pasajeros hasta que tenga un automovil registrado\n";
            cout << "\t(si / no): ";

            input = "";
            cin >> input;
            while(input != "si" && input != "no") {
                cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
                cin >> input;
            }

            if(input == "si") {
                cout << "\tModelo de automovil: ";
                cin >> modelo_auto;
                cout << "\tPlaca de automovil: ";
                cin >> placa_auto;
                automovil = new CAutomovil(modelo_auto, placa_auto);
            } else if(input == "no") {
                automovil = new CAutomovil("N/A", "N/A");
            } else cout << "\n\n\t~ERROR~\n\n";

            cout << "\nCreando cuenta...\n";
            cuenta_taxista = new CTaxista(nombre, apellido, edad, numero_de_celular, contrasenia, *automovil); // Crea objeto de taxista
            guardarObjeto<CTaxista>("taxistas.bin", *cuenta_taxista); // Guarda objeto de taxista en archivo
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            cout << "Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        } else if(input == "r" || input == "R") { // Regresar a pagina anterior
        } else cout << "\n\n\t~ERROR~\n\n";
    }
};
