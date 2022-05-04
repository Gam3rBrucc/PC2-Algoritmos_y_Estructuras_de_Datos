#pragma once
#include <iostream>
#include <string>
#include "CLista.h"
#include "Archivo.h"
#include "CUsuario.h"
#include "CTaxista.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define ARCH_U "usuarios.bin" // ARCH_U se refiere a ARCHivo Usuarios
#define ARCH_T "taxistas.bin" // ARCH_T se refiere a ARCHivo Taxistas

// TODO Implementa algoritmo de ordenamiento

class CAdmin {
    bool encontro_usuario = false;
    bool encontro_taxista = false;
    CUsuario* arreglo_usuarios;
    CTaxista* arreglo_taxistas;
public:
    CAdmin() {
        cout << "=================== Modo Admin ===================\n";
        cout << "\n\t[1] Ver informacion de todos las cuentas registradas\n";
        cout << "\t[2] Eliminar cuenta\n";
        cout << "\t[3] Ver fibonacci\n";
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
        input = revisar_input(input);

        CLista<CUsuario> lista_usuarios;
        CLista<CTaxista> lista_taxistas;

        leerObjetosGuardados<CUsuario>(ARCH_U, &lista_usuarios);
        leerObjetosGuardados<CTaxista>(ARCH_T, &lista_taxistas);

        if (input == '1') { // Recorre las listas de usuarios y taxistas mostrando toda la informacion de estas
            // TODO implementarlo aqui
            cout << "====================== Lista de usuarios ======================\n\n";
            bubble_sort(lista_usuarios);
            //lista_usuarios.recorrer_inicio([](CUsuario o) { cout << o.mostrar_info(); });
            cout << "====================== Lista de taxistas ======================\n\n";
            insertion_sort(lista_taxistas);
            //lista_taxistas.recorrer_inicio([](CTaxista o) { cout << o.mostrar_info(); });

            CAdmin();

        } else if (input == '2') { // Eliminar cuenta
            cout << "Para eliminar esta cuenta necesitas ingresar el numero de celular y contrasenia del usuario.\n\n";
            cout << "\tNumero de celular: ";

            int numero_de_celular;
            cin >> numero_de_celular;
            cout << "\tContrasenia: ";
            string contrasenia;
            cin >> contrasenia;

            lista_usuarios.recorrer_inicio(
                    [=](CUsuario o) { // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
                        if (numero_de_celular == o.get_numero_celular() &&
                            contrasenia == o.get_contrasenia())
                            encontro_usuario = true;
                    });
            lista_taxistas.recorrer_inicio(
                    [=](CTaxista o) { // Recorre toda la lista de usuarios y revisa si el numero de celular y contrasenia coinciden
                        if (numero_de_celular == o.get_numero_celular() &&
                            contrasenia == o.get_contrasenia())
                            encontro_taxista = true;
                    });

            if (encontro_usuario) { // Si el usuario de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el usuario que el admin a eligido, efectivamente eliminandolo
                limpiarArchivo(ARCH_U);
                lista_usuarios.recorrer_inicio([=](CUsuario o) {
                    if (numero_de_celular != o.get_numero_celular()) {
                        guardarObjeto(ARCH_U, o);
                    }
                });
            } else if (encontro_taxista) { // Si el taxista de encontro, recorre toda la lista guardando cada objecto en el archivo SIN el taxista que el admin a eligido, efectivamente eliminandolo
                limpiarArchivo(ARCH_T);
                lista_taxistas.recorrer_inicio([=](CTaxista o) {
                    if (numero_de_celular != o.get_numero_celular()) {
                        guardarObjeto(ARCH_T, o);
                    }
                });
            } else cout << "\n~~No se encontro ningun cuenta con ese numero de celular o contrasenia\n";

            if (encontro_usuario || encontro_taxista) cout << "\n~~Se logro eliminar la cuenta!\n";

            CAdmin();

        } else if(input == '3') {
            cout << "\nPor favor ingrese un numero: ";
            size_t num;
            cin >> num;
            for(size_t i=0; i<num; ++i) {
                cout << "[" << calcular_fibonacci(i) << "] ";
            }
            cout << endl;
            CAdmin();
        } else if(input == 'r' || input == 'R') { // Regresar pagina
        } else cout << "\n\n\t~ERROR~\n\n";
    }
    char revisar_input(char in) {
        char ingr = in;
        if(in != '1' && in != '2' && in != '3' && in != 'r' && in != 'R') {
            cout << "~~Lo sentimos pero no entendemos lo que ha ingresado, por favor elija una opcion de nuevo: ";
            cin >> ingr;
            return revisar_input(ingr);
        } else return ingr;
    }
    void bubble_sort(CLista<CUsuario> lista_usuario) {
        arreglo_usuarios = new CUsuario[lista_usuario.get_t()];
        size_t i = 0;
        lista_usuario.recorrer_inicio([&](CUsuario o){
            arreglo_usuarios[i] = o;
            ++i;
        });
        CUsuario aux;
        size_t cap = lista_usuario.get_t() - 1;
        for(size_t i=0; i<lista_usuario.get_t(); ++i) {
            for(size_t j=0; j<cap; ++j) {
                if(arreglo_usuarios[j].get_nombre().compare(arreglo_usuarios[j+1].get_nombre()) > arreglo_usuarios[j+1].get_nombre().compare(arreglo_usuarios[j].get_nombre())) {
                    aux = arreglo_usuarios[j];
                    arreglo_usuarios[j] = arreglo_usuarios[j+1];
                    arreglo_usuarios[j+1] = aux;
                }
            }
            --cap;
        }
        for(size_t i=0; i<lista_usuario.get_t(); ++i) {
            cout << arreglo_usuarios[i].mostrar_info();
        }
    }
    void insertion_sort(CLista<CTaxista> lista_taxista) {
        arreglo_taxistas = new CTaxista[lista_taxista.get_t()];
        size_t i = 0;
        lista_taxista.recorrer_inicio([&](CTaxista o){
            arreglo_taxistas[i] = o;
            ++i;
        });
        CTaxista aux_taxista;
        size_t j;
        for(size_t i=0; i<lista_taxista.get_t(); ++i) {
            aux_taxista = arreglo_taxistas[i];
            j = i - 1;
            while(j>=0 && arreglo_taxistas[j].get_nombre().compare(aux_taxista.get_nombre()) > aux_taxista.get_nombre().compare(arreglo_usuarios[j].get_nombre())) {
                arreglo_taxistas[j+1] = arreglo_taxistas[j];
                --j;
            }
            arreglo_taxistas[j+1] = aux_taxista;
        }
        for(size_t i=0; i<lista_taxista.get_t(); ++i) {
            cout << arreglo_taxistas[i].mostrar_info();
        }
    }
    size_t calcular_fibonacci(size_t n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return calcular_fibonacci(n-1) + calcular_fibonacci(n - 2);
    }
};
