#pragma once
#ifndef UNTITLED10_CUSUARIO_H
#define UNTITLED10_CUSUARIO_H

#endif //UNTITLED10_CUSUARIO_H
#include <iostream>
#include <string>
#include <functional>
#include "CPersona.h"
#include "CViaje.h"
#include "CPila.h"
class CUsuario : protected CPersona {
    CPila<CViaje> viajes;
public:
    CUsuario(){}
    CUsuario(std::string n, std::string a, std::string p, short e, int ndc) : CPersona(n,a,p,e,ndc) {}
    std::string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(num_cel) + "\nContrasenia: " + password + "\n\n";
    }
    void agregar_viaje(std::string ubi, std::string dir, short cal, std::string cho, std::string aut) {
        viajes.push(CViaje(ubi, dir, cal, cho, aut));
    }
    void recorrer_viajes(std::function<void(CViaje)> r_viaje) {
        viajes.recorrer([&](CViaje o){r_viaje(o);});
    }
    void set_num_cel(int cel) {
        num_cel = cel;
    }
    int get_num_cel() {
        return num_cel;
    }
    void set_contrasenia(std::string cont) {
        password = cont;
    }
    std::string get_password() {
        return password;
    }
    std::string get_nombre() {
        return nombre;
    }
    std::string get_apellido() {
        return apellido;
    }
    short get_edad() {
        return edad;
    }
};
