#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "CUsuario.h"
#include "CTaxista.h"
#include "CLista.h"
#include "Archivo.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define ARCH_U "usuarios.bin" // ARCH_U se refiere a ARCHivo Usuarios
#define ARCH_T "taxistas.bin" // ARCH_T se refiere a ARCHivo Taxistas

// TODO falta desarrollar opciones 2 y 4 de cuenta usuario
// TODO falta desarrollar opciones 2,4 y 5 de cuenta taxista

class CCuenta {
    CUsuario usuario;
    CTaxista taxista;
public:
    CCuenta(CUsuario obj) { // Corre si el obj pasado es de usuario
        usuario = obj;
        cout << "============== Cuenta de " << obj.get_nombre() << " ==============\n\n";
        cout << "\t[1] Ver datos de cuenta\n";
        cout << "\t[2] Ver historial de viajes\n";
        cout << "\t[3] Cambiar datos\n";
        cout << "\t[4] Pedir taxi\n";
        cout << "\t[5] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n\n";
        cout << "Elija una opcion: ";

        string input;
        cin >> input;
        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Ver datos de cuenta
            cout << "=============== Datos de cuenta ===============\n\n";
            cout << usuario.mostrar_info();
            CCuenta cuenta_U(usuario);
        } else if(input == "2") { // Ver historial de viajes

        } else if(input == "3") { // Cambiar datos
            cambiarDatos('U');
            CCuenta cuenta_U(usuario);
        } else if(input == "4") { // Pedir taxi
            pedirTaxi();
        } else if(input == "5") { // Eliminar cuenta
            cout << "\nEstas seguro que quieres eliminar tu cuenta?\n(SI/NO): ";
            string si_no;
            cin >> si_no;
            if(si_no == "SI") {
                eliminarCuenta('U');
            } else if(si_no == "NO") {
                CCuenta cuenta_U(usuario);
            } else {
                cout << "\n~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
                CCuenta cuenta_U(usuario);
            }
        } else if(input == "r" || input == "R") { // Regresar pagina
        } else cout << "\n\n\t~ERROR~\n\n";
    }
    CCuenta(CTaxista obj) { // Corre si el obj pasado es de taxista
        taxista = obj;
        cout << "============== Cuenta de " << obj.get_nombre() << " ==============\n\n";
        cout << "\t[1] Ver datos de cuenta\n";
        cout << "\t[2] Ver historial de pasajeros\n";
        cout << "\t[3] Cambiar datos\n";
        cout << "\t[4] Buscar pasajero\n";
        cout << "\t[5] Registrar automovil\n";
        cout << "\t[6] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n\n";
        cout << "Elija una opcion: ";

        string input;
        cin >> input;
        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Ver datos de cuenta
            cout << "=============== Datos de cuenta ===============\n\n";
            cout << taxista.mostrar_info();
            CCuenta cuenta_T(taxista);
        } else if(input == "2") { // Ver historial de viajes

        } else if(input == "3") { // Cambiar datos
            cambiarDatos('T');
            CCuenta cuenta_T(taxista);
        } else if(input == "4") { // Buscar pasajero

        } else if(input == "5") { // Registrar automovil

        } else if(input == "6") { // Eliminar cuenta
            cout << "\nEstas seguro que quieres eliminar tu cuenta?\n(SI/NO): ";
            string si_no;
            cin >> si_no;
            if(si_no == "SI") {
                eliminarCuenta('T');
            } else if(si_no == "NO") {
                CCuenta cuenta_T(taxista);
            } else {
                cout << "\n~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
                CCuenta cuenta_T(taxista);
            }
        } else if(input == "r" || input == "R") { // Regresar pagina
        } else cout << "\n\n\t~ERROR~\n\n";
    }

    void eliminarCuenta(char tipo_de_cuenta) {
        if(tipo_de_cuenta == 'U') {
            CLista<CUsuario> lista_usuarios;
            leerObjetosGuardados(ARCH_U, &lista_usuarios);
            limpiarArchivo(ARCH_U);
            lista_usuarios.recorrer_inicio([=](CUsuario o){
                if (usuario.get_numero_celular() != o.get_numero_celular()) {
                    guardarObjeto(ARCH_U, o);
                }
            });
            cout << "\n~~Se logro eliminar la cuenta!\n";
        } else if(tipo_de_cuenta == 'T') {
            CLista<CTaxista> lista_taxistas;
            leerObjetosGuardados(ARCH_T, &lista_taxistas);
            limpiarArchivo(ARCH_T);
            lista_taxistas.recorrer_inicio([=](CTaxista o){
                if (taxista.get_numero_celular() != o.get_numero_celular()) {
                    guardarObjeto(ARCH_T, o);
                }
            });
            cout << "\n~~Se logro eliminar la cuenta!\n";
        } else cout << "\n\n\t~ERROR~\n\n";
    }
    void actualizarCuentaUsuario(int celular, CUsuario obj) {
        CLista<CUsuario> lista_usuarios;
        leerObjetosGuardados(ARCH_U, &lista_usuarios);
        limpiarArchivo(ARCH_U);
        lista_usuarios.recorrer_inicio([&celular, &obj](CUsuario o) {
            if(o.get_numero_celular() == celular) {
                guardarObjeto<CUsuario>(ARCH_U, obj);
            } else guardarObjeto<CUsuario>(ARCH_U, o);
        });
    }
    void actualizarCuentaTaxista(int celular, CTaxista obj) {
        CLista<CTaxista> lista_taxistas;
        leerObjetosGuardados(ARCH_T, &lista_taxistas);
        limpiarArchivo(ARCH_T);
        lista_taxistas.recorrer_inicio([&celular, &obj](CTaxista o) {
            if(o.get_numero_celular() == celular) {
                guardarObjeto<CTaxista>(ARCH_T, obj);
            } else guardarObjeto<CTaxista>(ARCH_T, o);
        });
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
    void cambiarDatos(char tipo_de_cuenta) {
        cout << "=============== Cambiar datos ===============\n\n";
        cout << "\t[1] Numero de celular\n";
        cout << "\t[2] Contrasenia\n";
        cout << "\t[R] Regresar\n";
        cout << "\nElija una opcion: ";

        string input;
        cin >> input;
        while(input != "1" && input != "2" && input != "r" && input != "R") {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
            cin >> input;
        }

        if(input == "1") { // Cambiar numero de celular
            cout << "\nPorfavor ingrese su nuevo numero de celular: ";
            int nuevo_numero_de_celular;
            cin >> nuevo_numero_de_celular;

            if(verificarCelular(nuevo_numero_de_celular)) {
                if(tipo_de_cuenta == 'U') {
                    int antiguo_celular = usuario.get_numero_celular();
                    usuario.set_numero_celular(nuevo_numero_de_celular);
                    actualizarCuentaUsuario(antiguo_celular, usuario);
                }
                if(tipo_de_cuenta == 'T') {
                    int antiguo_celular = taxista.get_numero_celular();
                    taxista.set_numero_celular(nuevo_numero_de_celular);
                    actualizarCuentaTaxista(antiguo_celular, taxista);
                }

                cout << "\nSu numero de celular ha sido actualizada exitosamente!!!\n";
            } else cout << "\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor ingrese otro numero de celular\n";

        } else if(input == "2") { // Cambiar contrasenia
            cout << "\nPorfavor ingrese su nueva contrasenia: ";
            string nueva_contrasenia;
            cin >> nueva_contrasenia;

            if(tipo_de_cuenta == 'U') {
                usuario.set_contrasenia(nueva_contrasenia);
                actualizarCuentaUsuario(usuario.get_numero_celular(), usuario);
            }
            if(tipo_de_cuenta == 'T') {
                taxista.set_contrasenia(nueva_contrasenia);
                actualizarCuentaTaxista(taxista.get_numero_celular(), taxista);
            }

            cout << "\nSu contrasenia ha sido actualizada exitosamente!!!\n";
        } else if(input == "r" || input == "R") { // Regresar
            if(tipo_de_cuenta == 'U') CCuenta cuenta_U(usuario);
            if(tipo_de_cuenta == 'T') CCuenta cuenta_T(taxista);
        } else cout << "\n\n\t~ERROR~\n\n";
    }
    void pedirTaxi() {
        cout << "Por favor ingrese a donde quisiera ir: ";
        string direccion;
        cin >> direccion;

    }
};
