#pragma once
#include <iostream>

using std::string;

class CAutomovil {
protected:
    string modelo_automovil;
    string placa_automovil;

public:
    CAutomovil(string ma = "-", string pa = "-") {
        modelo_automovil = ma;
        placa_automovil = pa;
    }

    string info() {
        return modelo_automovil + " [" + placa_automovil + "]";
    }
    string get_modelo() {
        return modelo_automovil;
    }
    string get_placa() {
        return placa_automovil;
    }
    void set_modelo(string m) {
        modelo_automovil = m;
    }
    void set_placa(string p) {
        placa_automovil = p;
    }
};
