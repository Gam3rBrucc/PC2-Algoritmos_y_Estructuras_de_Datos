#pragma once
#include <iostream>
#include <string>
#include "CPersona.h"
#include "CViaje.h"
#include "CPila.h"

using std::string;

class CUsuario : protected CPersona {
    size_t t_arreglo;
    CViaje viajes_arreglo[0];
    CPila<CViaje>* viajes;
public:
    CUsuario() {}
    CUsuario(string n, string a, short e, int ndc, string c) : CPersona(n,a,e,ndc,c) {}

    void preparar_para_almacenamiento() {

    }
    void sacar_de_almacenamiento() {

    }
    void agregar_viaje(CViaje v) {
        viajes->push(v);
    }
    string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(numero_de_celular) + "\nContrasenia: " + contrasenia + "\n\n";
    }
    void set_numero_celular(int cel) {
        numero_de_celular = cel;
    }
    int get_numero_celular() {
        return numero_de_celular;
    }
    void set_contrasenia(string cont) {
        contrasenia = cont;
    }
    string get_contrasenia() {
        return contrasenia;
    }
    string get_nombre() {
        return nombre;
    }
};
