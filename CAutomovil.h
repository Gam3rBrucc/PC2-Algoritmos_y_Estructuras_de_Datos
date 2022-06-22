#pragma once
#ifndef UNTITLED10_CAUTOMOVIL_H
#define UNTITLED10_CAUTOMOVIL_H

#endif //UNTITLED10_CAUTOMOVIL_H
#include <iostream>
class CAutomovil {
protected:
    std::string modelo_auto;
    std::string placa_auto;
public:
    CAutomovil() {}
    CAutomovil(std::string ma, std::string pa) {
        this->modelo_auto = ma;
        this->placa_auto = pa;
    }
    std::string info() {
        return modelo_auto+ " [" + placa_auto + "]";
    }
    std::string get_modelo() {
        return modelo_auto;
    }
    std::string get_placa() {
        return placa_auto;
    }
    void set_modelo(std::string m) {
        modelo_auto = m;
    }
    void set_placa(std::string p) {
        placa_auto = p;
    }
};
