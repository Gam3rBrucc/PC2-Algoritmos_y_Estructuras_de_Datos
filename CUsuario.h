#pragma once
#include <iostream>
#include <string>
#include "CPersona.h"
#include "CViaje.h"
#include "CPila.h"

using std::string;

class CUsuario : protected CPersona {
    CPila<CViaje> lista_viajes;
public:
    CUsuario() {}
    CUsuario(string n, string a, short e, int ndc, string c) : CPersona(n,a,e,ndc,c) {}

    void agregar_viaje(string ubi, string dir, short cal, string cho, string aut) {
        lista_viajes.push(CViaje(ubi, dir, cal, cho, aut));
    }
    void recorrer_viajes(std::function<void(CViaje)> r_viaje) {
        lista_viajes.recorrer_ultimo([&](CViaje o){r_viaje(o);});
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
    string get_apellido() {
        return apellido;
    }
};
