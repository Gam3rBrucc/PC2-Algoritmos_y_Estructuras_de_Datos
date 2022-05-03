#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CAutomovil.h"
#include "Archivo.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define ARCH_U "usuarios.bin" // ARCH_U se refiere a ARCHivo Usuarios
#define ARCH_T "taxistas.bin" // ARCH_T se refiere a ARCHivo Taxistas

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
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            if(verificarCelular(numero_de_celular)) {
                cuenta_usuario = new CUsuario(nombre, apellido, edad, numero_de_celular, contrasenia); // Crea objeto de usuario
                guardarObjeto<CUsuario>(ARCH_U, *cuenta_usuario); // Guarda objecto de usuario en archivo
                cout << "Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n";
            } else cout << "\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor registrese de nuevo usando otro numero de celular\n";

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
            cout << "\t[S] Si";
            cout << "\n\t[N] No";
            cout << "\nPor favor elija una respeusta: ";

            input = "";
            cin >> input;
            while(input != "s" && input != "S" && input != "n" && input != "N") {
                cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
                cin >> input;
            }

            if(input == "s" || input == "S") {
                cout << "\tModelo de automovil: ";
                cin >> modelo_auto;
                cout << "\tPlaca de automovil: ";
                cin >> placa_auto;
                automovil = new CAutomovil(modelo_auto, placa_auto);
            } else if(input == "n" || input == "N") {
                automovil = new CAutomovil("N/A", "N/A");
            } else cout << "\n\n\t~ERROR~\n\n";

            cout << "\nCreando cuenta...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            if(verificarCelular(numero_de_celular)) {
                cuenta_taxista = new CTaxista(nombre, apellido, edad, numero_de_celular, contrasenia, *automovil); // Crea objeto de taxista
                guardarObjeto<CTaxista>(ARCH_T, *cuenta_taxista); // Guarda objeto de taxista en archivo
                cout << "Su cuenta nueva ha sido creada!!! Puede ingresar a su cuenta desde el login\n\n";
            } else cout << "\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor registrese de nuevo usando otro numero de celular\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        } else if(input == "r" || input == "R") { // Regresar a pagina anterior
        } else cout << "\n\n\t~ERROR~\n\n";
    }

    bool verificarCelular(int celular) {
        bool num_cel_disponible = true; // Este bloque revisa si el numero de celular que ingreso el usuario ya esta siendo usada
        CLista<CTaxista> lista_taxistas;
        CLista<CUsuario> lista_usuarios;
        leerObjetosGuardados(ARCH_T, &lista_taxistas);
        lista_taxistas.recorrer_inicio([&celular, &num_cel_disponible](CTaxista o){
            if(o.get_numero_celular() == celular) num_cel_disponible = false;
        });
        leerObjetosGuardados(ARCH_U, &lista_usuarios);
        lista_usuarios.recorrer_inicio([&celular, &num_cel_disponible](CUsuario o){
            if(o.get_numero_celular() == celular) num_cel_disponible = false;
        });
        return num_cel_disponible;
    }
};
