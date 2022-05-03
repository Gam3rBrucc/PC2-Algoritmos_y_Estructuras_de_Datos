#pragma once
#include <iostream>
#include "CPersona.h"
#include "CAutomovil.h"
#include "CPasajero.h"
#include "CPila.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CTaxista : protected CPersona {
protected:
    CAutomovil automovil;
    CPila<CPasajero> lista_pasajeros;

public:
    CTaxista() {}
    CTaxista(string n, string a, short e, int ndc, string c, CAutomovil au) : CPersona(n,a,e,ndc,c) {
        automovil = au;
    }

    void agregar_pasajero(string p, string u, string d, short c) {
        lista_pasajeros.push(CPasajero(p, u, d, c));
    }
    void recorrer_viajes(std::function<void(CPasajero)> r_pas) {
        lista_pasajeros.recorrer_primero([&](CPasajero o){r_pas(o);});
    }
    string mostrar_info() {
        return nombre + " " + apellido + ", " + std::to_string(edad) + "\nNumero de celular: " + std::to_string(numero_de_celular) + "\nAutomovil: " + automovil.info() + "\nContrasenia: " + contrasenia + "\n\n";
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
    string info_auto() {
        return automovil.get_modelo() + " [" + automovil.get_placa() + "]";
    }
    void set_auto(string m, string p) {
        automovil.set_modelo(m);
        automovil.set_placa(p);
    }
    bool auto_registrado() {
        if(automovil.get_modelo() == "N/A") return false;
        else return true;
    }
};
