#pragma once
#ifndef UNTITLED10_CPERSONA_H
#define UNTITLED10_CPERSONA_H

#endif //UNTITLED10_CPERSONA_H
#include <iostream>
class CPersona {
protected:
    std::string nombre, apellido, password;
    short edad;
    int num_cel;
public:
    CPersona() {}
    CPersona(std::string n, std::string a, std::string p, short e, int nc) {
        this->nombre = n;
        this->apellido = a;
        this->password = p;
        this->edad = e;
        this->num_cel = nc;
    }
};
