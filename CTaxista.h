#pragma once
#ifndef UNTITLED10_CTAXISTA_H
#define UNTITLED10_CTAXISTA_H

#endif //UNTITLED10_CTAXISTA_H
#include <iostream>
#include <functional>
#include "CPersona.h"
#include "CAutomovil.h"
#include "CPasajero.h"
#include "CPila.h"
class CTaxista : protected CPersona {
    CAutomovil automovil;
    CPila<CPasajero> lista_pasajeros;
public:
    CTaxista() {}
    CTaxista(std::string n, std::string a, std::string p, short e, int ndc, CAutomovil au) : CPersona(n,a,p,e,ndc) {
        automovil = au;
    }
    void agregar_pasajero(std::string p, std::string u, std::string d, short c) {
        lista_pasajeros.push(CPasajero(p, u, d, c));
    }
    void recorrer_viajes(std::function<void(CPasajero)> r_pas) {
        lista_pasajeros.recorrer([&](CPasajero o){r_pas(o);});
    }
    std::string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(num_cel) + "\nAutomovil: " + automovil.info() + "\nContrasenia: " + password + "\n\n";
    }
    void set_num_cel(int cel) {
        num_cel = cel;
    }
    int get_num_cel() {
        return num_cel;
    }
    void set_password(std::string cont) {
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
    std::string info_auto() {
        return automovil.get_modelo() + " [" + automovil.get_placa() + "]";
    }
    void set_auto(std::string m, std::string p) {
        automovil.set_modelo(m);
        automovil.set_placa(p);
    }
    bool auto_registrado() {
        if(automovil.get_modelo() == "N/A") return false;
        else return true;
    }
    short get_edad() {
        return edad;
    }
    std::string get_modelo_auto() {
        return automovil.get_modelo();
    }
    std::string get_placa_auto() {
        return automovil.get_placa();
    }
};
