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

//        string input;
//        cin >> input;
//        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "r" && input != "R") {
//            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
//            cin >> input;
//        }
        char input;
        cin >> input;
        input = revisar_input1(input);

        if(input == '1') { // Ver datos de cuenta
            cout << "=============== Datos de cuenta ===============\n\n";
            cout << usuario.mostrar_info();
            CCuenta cuenta_U(usuario);
        } else if(input == '2') { // Ver historial de viajes
            ver_historial_viajes('U');
            CCuenta cuenta_U(usuario);
        } else if(input == '3') { // Cambiar datos
            cambiarDatos('U');
            CCuenta cuenta_U(usuario);
        } else if(input == '4') { // Pedir taxi
            pedirTaxi();
            CCuenta cuenta_U(usuario);
        } else if(input == '5') { // Eliminar cuenta
            cout << "\nEstas seguro que quieres eliminar tu cuenta?\n";
            cout << "\n\t[S] Si\n";
            cout << "\t[N] No\n";
            cout << "Por favor ingrese una opcion: ";
            char si_no;
            cin >> si_no;
            revisar_input4(si_no);
//            string si_no;
//            cin >> si_no;
            if(si_no == 's' || si_no == 'S') eliminarCuenta('U');
            else if(si_no == 'n' || si_no == 'N') CCuenta cuenta_U(usuario);
        } else if(input == 'r' || input == 'R') { // Regresar pagina
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
        cout << "\t[7] Eliminar cuenta\n";
        cout << "\t[R] Regresar\n\n";
        cout << "Elija una opcion: ";

//        string input;
//        cin >> input;
//        while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "r" && input != "R") {
//            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
//            cin >> input;
//        }

        char input;
        cin >> input;
        input = revisar_input2(input);

        if(input == '1') { // Ver datos de cuenta
            cout << "=============== Datos de cuenta ===============\n\n";
            cout << taxista.mostrar_info();
            CCuenta cuenta_T(taxista);
        } else if(input == '2') { // Ver historial de viajes
            ver_historial_viajes('T');
            CCuenta cuenta_T(taxista);
        } else if(input == '3') { // Cambiar datos
            cambiarDatos('T');
            CCuenta cuenta_T(taxista);
        } else if(input == '4') { // Buscar pasajero
            cout << "\n~~Buscando un pasajero\n";
            buscar_pasajero();
            CCuenta cuenta_T(taxista);
        } else if(input == '5') { // Registrar automovil
            if(!taxista.auto_registrado()) {
                string modelo;
                string placa;
                cout << "\nPor favor ingrese el modelo de su automovil: ";
                cin >> modelo;
                cout << "Y la placa del mismo: ";
                cin >> placa;

                taxista.set_auto(modelo, placa);
                actualizarCuentaTaxista(taxista.get_numero_celular(), taxista);

                cout << "\n~~Automovil registrado con exito!!!\n";
            }

            if(taxista.auto_registrado()) {
                cout << "\n~~Ya tiene un automovil registrado!\n";
            } else {
                string modelo;
                string placa;
                cout << "\nPor favor ingrese el modelo de su automovil: ";
                cin >> modelo;
                cout << "Y la placa del mismo: ";
                cin >> placa;

                taxista.set_auto(modelo, placa);
                actualizarCuentaTaxista(taxista.get_numero_celular(), taxista);

                cout << "\n~~Automovil registrado con exito!!!\n";
            }
            CCuenta cuenta_T(taxista);
        } else if(input == '6') { // Eliminar cuenta
            cout << "\nEstas seguro que quieres eliminar tu cuenta?\n(SI/NO): ";
//            string si_no;
//            cin >> si_no;
            char si_no;
            cin >> si_no;
            si_no = revisar_input4(si_no);
            if(si_no == 's' || si_no == 'S') eliminarCuenta('U');
            else if(si_no == 'n' || si_no == 'N') CCuenta cuenta_U(usuario);
        } else if(input == 'r' || input == 'R') { // Regresar pagina
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

//        string input;
//        cin >> input;
//        while(input != "1" && input != "2" && input != "r" && input != "R") {
//            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
//            cin >> input;
//        }

        char input;
        cin >> input;
        input = revisar_input3(input);

        if(input == '1') { // Cambiar numero de celular
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

        } else if(input == '2') { // Cambiar contrasenia
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
        } else if(input == 'r' || input == 'R') { // Regresar
            if(tipo_de_cuenta == 'U') CCuenta cuenta_U(usuario);
            if(tipo_de_cuenta == 'T') CCuenta cuenta_T(taxista);
        } else cout << "\n\n\t~ERROR~\n\n";
    }
    void pedirTaxi() {
        cout << "Por favor ingrese a donde quisiera ir: ";
        string destino;
        cin >> destino;
        cout << "Ahora ingrese su ubicacion actual: ";
        string ubicacion;
        cin >> ubicacion;

        bool buscar = true;
        string respuesta;

        CTaxista taxi;
        CLista<CTaxista> lista_taxistas;
        leerObjetosGuardados(ARCH_T, &lista_taxistas);

        cout << "\n~~Gracias!! Ahora buscamos un taxi, por favor espere...\n";

        buscar_taxi(buscar, destino, ubicacion, taxi, lista_taxistas, respuesta);

        // (1)
    }
    void buscar_pasajero() {
        string ubicaciones[5] = {"Casa", "Parque", "Banco", "Mercado", "Aeropuerto"};
        string destino[5] = {"Trabajo", "Colegio", "Universidad", "Hospital", "Fiesta"};
        string ubi;
        string dest;
        bool buscar = true;
        CUsuario usuario;
        CLista<CUsuario> lista_usuarios;
        leerObjetosGuardados(ARCH_U, &lista_usuarios);

        //pasajero(buscar, ubicaciones, destino, ubi, dest, usuario, lista_usuarios);

        while(buscar) {
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            size_t indice = rand() % lista_usuarios.get_t();
            usuario = lista_usuarios.buscar_indice(indice);

            ubi = ubicaciones[rand() % 5];
            dest = destino[rand() % 5];

            cout << usuario.get_nombre() << " " << usuario.get_apellido() << " quiere ir de [" << ubi << "] a [" << dest << "]\n";
            string respuesta;
            cout << "Quieres aceptar a " << usuario.get_nombre() << "?\n";
            cout << "\n\t[S] Si\n";
            cout << "\t[N] No\n";
            cout << "\t[C] Cancelar busqueda\n";

            cout << "\nElija una opcion: ";
            cin >> respuesta;
            while(respuesta != "s" && respuesta != "S" && respuesta != "n" && respuesta != "N" && respuesta != "c" && respuesta != "C") {
                cout << "\n~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n";
                cin >> respuesta;
            }

            if(respuesta == "s" || respuesta == "S") {
                buscar = false;
                cout << "\n~~Has aceptado a " << usuario.get_nombre() << "!!\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                cout << "\n  ___\n";
                cout << "    _-_-  _/\\______\\\\__\n";
                cout << " _-_-__  / ,-. -|-  ,-.`-.\n";
                cout << "    _-_- `( o )----( o )-'\n";
                cout << "           `-'      `-'\n";
                cout << "    Llevando a destino!!!\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                taxista.agregar_pasajero(usuario.get_nombre(), ubi, dest, 5);

                cout << "\n~~Listo! Has llevado a " << usuario.get_nombre() << " a su destino!\n";
            } else if(respuesta == "n" || respuesta == "N") {
                cout << "\n~~Buscando otro pasajero\n";
            } else if(respuesta == "c" || respuesta == "C") {
                buscar = false;
                cout << "\n~Se ha cancelado la busqueda\n";
            } else {
                cout << "\n\n\t~~ERROR~~\n";
            }
        }
    }
    void ver_historial_viajes(char tipo_de_cuenta) {
        cout << "================== Historial Viajes ==================\n\n";
        if(tipo_de_cuenta == 'U') {
            usuario.recorrer_viajes([](CViaje o){cout << o.mostrar_info() << endl;});
        } else if(tipo_de_cuenta == 'T') {
            //taxista.recorrer_viajes([](CPasajero o){cout << o.mostrar_info() << endl;});
        }
    }

    char revisar_input1(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != '4' && in != '5' && in != 'r' && in != 'R') {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
            cin >> ingr;
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input2(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != '4' && in != '5' && in != '6' && in != 'r' && in != 'R') {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
            cin >> ingr;
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input3(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != 'r' && in != 'R') {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
            cin >> ingr;
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input4(char in) {
        char ingr = in;
        if(in != 'n' && in != 'N' && in != 's' && in != 'S') {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
            cin >> ingr;
            return revisar_input1(ingr);
        } else return ingr;
    }
    bool buscar_taxi(bool buscar, string dest, string ubi, CTaxista tax, CLista<CTaxista> lista_tax, string res) {
        if(buscar) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cout << "~~Buscando taxi...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));

            size_t indice = rand() % lista_tax.get_t();
            while(!lista_tax.buscar_indice(indice).auto_registrado()) {
                indice = rand() % lista_tax.get_t();
            }

            tax = lista_tax.buscar_indice(indice);

            cout << tax.get_nombre() << " " << tax.get_apellido() << " - " << tax.info_auto() << ", esta disponible para recogerte!\n";
            cout << "\nAceptar a " << tax.get_nombre() << "?\n";
            cout << "\t[S] Si\n\t[N] No\n\t[C] Cancelar busqueda\n\n";
            cout << "Por favor elija una opcion: ";
            cin >> res;
            while(res != "s" && res != "S" && res != "n" && res != "N" && res != "c" && res != "C") {
                cout << "~~Lo sentimos pero entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
                cin >> res;
            }

            if(res == "s" || res == "S") {
                buscar = false;
                cout << "\n  ___\n";
                cout << "    _-_-  _/\\______\\\\__\n";
                cout << " _-_-__  / ,-. -|-  ,-.`-.\n";
                cout << "    _-_- `( o )----( o )-'\n";
                cout << "           `-'      `-'\n";
                cout << "    Ya va a su destino!!!\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                short calificacion;
                cout << "\n~Ya llego a su destino!\n";
                cout << "\nQue calificacion quisiera darle a " << tax.get_nombre() << "? (1-5): ";
                cin >> calificacion;
                while(calificacion > 5 || calificacion < 1) {
                    cout << "Al parecer ha ingresado un numero que no esta entre el rango de 1 - 5, por favor ingrese un numero de nuevo\n";
                    cin >> calificacion;
                }

                usuario.agregar_viaje(ubi, dest, calificacion, tax.get_nombre(), tax.info_auto());
                cout << "\n~Gracias!!!\n";
            } else if(res == "n" || res == "N") {
                cout << "\n~Buscando otro taxi\n";
            } else if(res == "c" || res == "C") {
                buscar = false;
                cout << "\n~Se ha cancelado la busqueda\n";
            } else {
                cout << "\n\n\t~~ERROR~~\n";
            }
            buscar_taxi(buscar, ubi, dest, tax, lista_tax, res);
        } else return false;
    }

    // (3)
};
