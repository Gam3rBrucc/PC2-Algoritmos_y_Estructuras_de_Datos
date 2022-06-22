#pragma once
#ifndef UNTITLED10_CCUENTA_H
#define UNTITLED10_CCUENTA_H

#endif //UNTITLED10_CCUENTA_H
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "CUsuario.h"
#include "CTaxista.h"
#include "Archivo.h"
class CCuenta {
    CUsuario usuario;
    CTaxista taxista;
public:
    CCuenta(CUsuario obj, std::vector<CUsuario>* lista_usuarios ,std::vector<CTaxista>* lista_taxistas) { // Corre si el obj pasado es de usuario
        usuario = obj;
        printf("============== Cuenta de %s ==============\n\n", obj.get_nombre().c_str());
        printf("\t[1] Ver datos de cuenta\n");
        printf("\t[2] Ver historial de viajes\n");
        printf("\t[3] Cambiar datos\n");
        printf("\t[4] Pedir taxi\n");
        printf("\t[5] Eliminar cuenta\n");
        printf("\t[R] Regresar\n\n");
        printf("Elija una opcion: ");

        char input;
        scanf(" %c", &input);
        input = revisar_input1(input);

        if(input == '1') { // Ver datos de cuenta
            printf("=============== Datos de cuenta ===============\n\n");
            printf("%s", usuario.mostrar_info().c_str());
            CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
        } else if(input == '2') { // Ver historial de viajes
            ver_historial_viajes('U');
            CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
        } else if(input == '3') { // Cambiar datos
            cambiarDatos('U', lista_usuarios, lista_taxistas);
            CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
        } else if(input == '4') { // Pedir taxi
            pedirTaxi(lista_usuarios, lista_taxistas);
            CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
        } else if(input == '5') { // Eliminar cuenta
            printf("\nEstas seguro que quieres eliminar tu cuenta?\n");
            printf("\n\t[S] Si\n");
            printf("\t[N] No\n");
            printf("Por favor ingrese una opcion: ");
            char si_no;
            scanf(" %c", &si_no);
            revisar_input4(si_no);
            if(si_no == 's' || si_no == 'S') eliminarCuenta(lista_usuarios);
            else if(si_no == 'n' || si_no == 'N') CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
        } else if(input == 'r' || input == 'R') { // Regresar pagina
        } else printf("\n\n\t~ERROR~\n\n");
    }
    CCuenta(CTaxista obj, std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) { // Corre si el obj pasado es de taxista
        taxista = obj;
        printf("============== Cuenta de %s ==============\n\n", obj.get_nombre().c_str());
        printf("\t[1] Ver datos de cuenta\n");
        printf("\t[2] Ver historial de pasajeros\n");
        printf("\t[3] Cambiar datos\n");
        printf("\t[4] Buscar pasajero\n");
        printf("\t[5] Registrar automovil\n");
        printf("\t[6] Eliminar cuenta\n");
        printf("\t[R] Regresar\n\n");
        printf("Elija una opcion: ");

        char input;
        scanf(" %c", &input);
        input = revisar_input2(input);

        if(input == '1') { // Ver datos de cuenta
            printf("=============== Datos de cuenta ===============\n\n");
            printf("%s",taxista.mostrar_info().c_str());
            CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == '2') { // Ver historial de viajes
            ver_historial_viajes('T');
            CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == '3') { // Cambiar datos
            cambiarDatos('T', lista_usuarios, lista_taxistas);
            CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == '4') { // Buscar pasajero
            printf("\n~~Buscando un pasajero\n");
            buscar_pasajero(lista_usuarios);
            CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == '5') { // Registrar automovil
            if(taxista.auto_registrado()) {
                printf("\n~~Ya tiene un automovil registrado!\n");
            } else {
                std::string modelo;
                std::string placa;
                printf("\nPor favor ingrese el modelo de su automovil: ");
                std::cin >> modelo;
                printf("Y la placa del mismo: ");
                std::cin >> placa;

                taxista.set_auto(modelo, placa);
                actualizarCuentaTaxista(taxista.get_num_cel(), lista_taxistas);

                printf("\n~~Automovil registrado con exito!!!\n");
            }
            CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == '6') { // Eliminar cuenta
            printf("\nEstas seguro que quieres eliminar tu cuenta?\n");
            printf("\n\t[S] Si\n");
            printf("\t[N] No\n");
            printf("Por favor ingrese una opcion: ");
            char si_no;
            scanf(" %c", &si_no);
            si_no = revisar_input4(si_no);
            if(si_no == 's' || si_no == 'S') eliminarCuenta(lista_taxistas);
            else if(si_no == 'n' || si_no == 'N') CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else if(input == 'r' || input == 'R') { // Regresar pagina
        } else printf("\n\n\t~ERROR~\n\n");
    }

    void eliminarCuenta(std::vector<CUsuario>* lista_usuarios) {
        long iU = 0;
        for (auto i: *lista_usuarios) {
            if (usuario.get_num_cel() == i.get_num_cel()) break;
            ++iU;
        }
        lista_usuarios->erase(lista_usuarios->begin() + iU);
        printf("\n~~Se logro eliminar la cuenta!\n");
    }
    void eliminarCuenta(std::vector<CTaxista>* lista_taxistas) {
        long iT = 0;
        for (auto i: *lista_taxistas) {
            if (taxista.get_num_cel() == i.get_num_cel()) break;
            ++iT;
        }
        lista_taxistas->erase(lista_taxistas->begin() + iT);
        printf("\n~~Se logro eliminar la cuenta!\n");
    }
    void actualizarCuentaUsuario(int ant_celular, std::vector<CUsuario>* lista_usuarios) {
        CUsuario nuevo_obj = usuario;
        long iU = 0;
        for (auto i: *lista_usuarios) {
            if (ant_celular == i.get_num_cel()) {
                break;
            }
            ++iU;
        }
        lista_usuarios->erase(lista_usuarios->begin()+iU);
        lista_usuarios->push_back(nuevo_obj);
    }
    void actualizarCuentaTaxista(int ant_celular, std::vector<CTaxista>* lista_taxistas) {
        CTaxista nuevo_obj = taxista;
        long iT = 0;
        for (auto i: *lista_taxistas) {
            if (ant_celular == i.get_num_cel()) {
                break;
            }
            ++iT;
        }
        lista_taxistas->erase(lista_taxistas->begin()+iT);
        lista_taxistas->push_back(nuevo_obj);
    }
    bool verificarCelular(int celular, std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        bool num_cel_disponible = true; // Este bloque revisa si el numero de celular que ingreso el usuario ya esta siendo usada
        for(auto i : *lista_usuarios) if(i.get_num_cel() == celular) num_cel_disponible = false;
        for(auto i : *lista_taxistas) if(i.get_num_cel() == celular) num_cel_disponible = false;
        return num_cel_disponible;
    }
    void cambiarDatos(char tipo_de_cuenta, std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("=============== Cambiar datos ===============\n\n");
        printf("\t[1] Numero de celular\n");
        printf("\t[2] Contrasenia\n");
        printf("\t[R] Regresar\n");
        printf("\nElija una opcion: ");

        char input;
        scanf(" %c", &input);
        input = revisar_input3(input);

        if(input == '1') { // Cambiar numero de celular
            printf("\nPorfavor ingrese su nuevo numero de celular: ");
            int nuevo_numero_de_celular;
            scanf("%d", &nuevo_numero_de_celular);

            if(verificarCelular(nuevo_numero_de_celular, lista_usuarios, lista_taxistas)) {
                if(tipo_de_cuenta == 'U') {
                    int antiguo_celular = usuario.get_num_cel();
                    usuario.set_num_cel(nuevo_numero_de_celular);
                    actualizarCuentaUsuario(antiguo_celular, lista_usuarios);
                }
                if(tipo_de_cuenta == 'T') {
                    int antiguo_celular = taxista.get_num_cel();
                    taxista.set_num_cel(nuevo_numero_de_celular);
                    actualizarCuentaTaxista(antiguo_celular, lista_taxistas);
                }

                printf("\nSu numero de celular ha sido actualizada exitosamente!!!\n");
            } else printf("\n~~Oh no! Al parecer ya existe una cuenta registrado con el numero de celular que ingreso, por favor ingrese otro numero de celular\n");

        } else if(input == '2') { // Cambiar contrasenia
            printf("\nPorfavor ingrese su nueva contrasenia: ");
            std::string nueva_contrasenia;
            std::cin >> nueva_contrasenia;

            if(tipo_de_cuenta == 'U') {
                usuario.set_contrasenia(nueva_contrasenia);
                actualizarCuentaUsuario(usuario.get_num_cel(), lista_usuarios);
            }
            if(tipo_de_cuenta == 'T') {
                taxista.set_password(nueva_contrasenia);
                actualizarCuentaTaxista(taxista.get_num_cel(), lista_taxistas);
            }

            printf("\nSu contrasenia ha sido actualizada exitosamente!!!\n");
        } else if(input == 'r' || input == 'R') { // Regresar
            if(tipo_de_cuenta == 'U') CCuenta cuenta_U(usuario, lista_usuarios ,lista_taxistas);
            if(tipo_de_cuenta == 'T') CCuenta cuenta_T(taxista, lista_usuarios, lista_taxistas);
        } else printf("\n\n\t~ERROR~\n\n");
    }
    void pedirTaxi(std::vector<CUsuario>* lista_usuarios, std::vector<CTaxista>* lista_taxistas) {
        printf("Por favor ingrese a donde quisiera ir: ");
        std::string destino;
        std::cin >> destino;
        printf("Ahora ingrese su ubicacion actual: ");
        std::string ubicacion;
        std::cin >> ubicacion;

        bool buscar = true;

        CTaxista taxi;

        printf("\n~~Gracias!! Ahora buscamos un taxi, por favor espere...\n");

        buscar_taxi(buscar, destino, ubicacion, taxi, lista_taxistas);

        CCuenta cuenta_U(usuario, lista_usuarios, lista_taxistas);
    }
    void buscar_pasajero(std::vector<CUsuario>* lista_usuarios) {
        std::string ubicaciones[5] = {"Casa", "Parque", "Banco", "Mercado", "Aeropuerto"};
        std::string destino[5] = {"Trabajo", "Colegio", "Universidad", "Hospital", "Fiesta"};
        std::string ubi;
        std::string dest;
        char respuesta;
        bool buscar = true;
        CUsuario u;

        while(buscar) {
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            size_t indice = rand() % lista_usuarios->size();
            u = get_usuario(indice, lista_usuarios);

            ubi = ubicaciones[rand() % 5];
            dest = destino[rand() % 5];

            printf("%s %s quiere ir de [%s] a [%s]\n", u.get_nombre().c_str(), u.get_apellido().c_str(), ubi.c_str(), dest.c_str());
            printf("Quieres aceptar a %s?\n", u.get_nombre().c_str());
            printf("\n\t[S] Si\n");
            printf("\t[N] No\n");
            printf("\t[C] Cancelar busqueda\n");

            printf("\nElija una opcion: ");
            scanf(" %c", &respuesta);
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N' && respuesta != 'c' && respuesta != 'C') {
                printf("\n~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo\n");
                scanf(" %c", &respuesta);
            }

            if(respuesta == 's' || respuesta == 'S') {
                buscar = false;
                printf("\n~~Has aceptado a %s!!\n", u.get_nombre().c_str());
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                printf("\n  ___\n");
                printf("    _-_-  _/\\______\\\\__\n");
                printf(" _-_-__  / ,-. -|-  ,-.`-.\n");
                printf("    _-_- `( o )----( o )-'\n");
                printf("           `-'      `-'\n");
                printf("    Llevando a destino!!!\n");

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                taxista.agregar_pasajero(u.get_nombre(), ubi, dest, 5);

                printf("\n~~Listo! Has llevado a %s a su destino!\n", u.get_nombre().c_str());
            } else if(respuesta == 'n' || respuesta == 'N') {
                printf("\n~~Buscando otro pasajero\n");
            } else if(respuesta == 'c' || respuesta == 'C') {
                buscar = false;
                printf("\n~Se ha cancelado la busqueda\n");
            } else {
                printf("\n\n\t~~ERROR~~\n");
            }
        }
    }
    void ver_historial_viajes(char tipo_de_cuenta) {
        printf("================== Historial Viajes ==================\n\n");
        if(tipo_de_cuenta == 'U') {
            usuario.recorrer_viajes([](CViaje o){printf("%s", o.mostrar_info().c_str());});
        } else if(tipo_de_cuenta == 'T') {
            taxista.recorrer_viajes([](CPasajero o){printf("%s", o.mostrar_info().c_str());});
        }
    }

    char revisar_input1(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != '4' && in != '5' && in != 'r' && in != 'R') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input2(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != '4' && in != '5' && in != '6' && in != 'r' && in != 'R') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input3(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != 'r' && in != 'R') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input1(ingr);
        } else return ingr;
    }
    char revisar_input4(char in) {
        char ingr = in;
        if(in != 'n' && in != 'N' && in != 's' && in != 'S') {
            printf("~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
            scanf(" %c", &ingr);
            return revisar_input1(ingr);
        } else return ingr;
    }
    bool buscar_taxi(bool buscar, std::string dest, std::string ubi, CTaxista tax, std::vector<CTaxista>* lista_tax) {
        char res;
        if(buscar) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            printf("~~Buscando taxi...\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));

            size_t indice = rand() % lista_tax->size();
            while(!get_taxista(indice, lista_tax).auto_registrado())
                indice = rand() % lista_tax->size();

            tax = get_taxista(indice, lista_tax);

            printf("%s %s - %s, esta disponible para recogerte!\n", tax.get_nombre().c_str(), tax.get_apellido().c_str(), tax.info_auto().c_str());
            printf("\nAceptar a %s?\n", tax.get_nombre().c_str());
            printf("\t[S] Si\n\t[N] No\n\t[C] Cancelar busqueda\n\n");
            printf("Por favor elija una opcion: ");
            scanf(" %c", &res);
            while(res != 's'&& res != 'S' && res != 'n'&& res != 'N' && res != 'c'&& res != 'C') {
                printf("~~Lo sentimos pero entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ");
                scanf(" %c", &res);
            }

            if(res == 's' || res == 'S') {
                buscar = false;
                printf("\n  ___\n");
                printf("    _-_-  _/\\______\\\\__\n");
                printf(" _-_-__  / ,-. -|-  ,-.`-.\n");
                printf("    _-_- `( o )----( o )-'\n");
                printf("           `-'      `-'\n");
                printf("    Ya va a su destino!!!\n");

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                short calificacion;
                printf("\n~Ya llego a su destino!\n");
                printf("\nQue calificacion quisiera darle a %s? (1-5): ", tax.get_nombre().c_str());
                scanf("%hi", &calificacion);
                while(calificacion > 5 || calificacion < 1) {
                    printf("Al parecer ha ingresado un numero que no esta entre el rango de 1 - 5, por favor ingrese un numero de nuevo\n");
                    scanf("%hi", &calificacion);
                }

                usuario.agregar_viaje(ubi, dest, calificacion, tax.get_nombre(), tax.info_auto());
                printf("\n~Gracias!!!\n");
            } else if(res == 'n' || res == 'N') {
                printf("\n~Buscando otro taxi\n");
            } else if(res == 'c' || res == 'C') {
                buscar = false;
                printf("\n~Se ha cancelado la busqueda\n");
            } else {
                printf("\n\n\t~~ERROR~~\n");
            }
            buscar_taxi(buscar, ubi, dest, tax, lista_tax);
        } else return false;
    }
    CUsuario get_usuario(long i, std::vector<CUsuario>* lista_usuarios) {
        long count = 0;
        for(auto o : *lista_usuarios) {
            if(count == i) return o;
            ++count;
        }
    }
    CTaxista get_taxista(long i, std::vector<CTaxista>* lista_taxistas) {
        long count = 0;
        for(auto o : *lista_taxistas) {
            if(count == i) return o;
            ++count;
        }
    }
};
