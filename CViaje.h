#pragma once
#ifndef UNTITLED10_CVIAJE_H
#define UNTITLED10_CVIAJE_H

#endif //UNTITLED10_CVIAJE_H
#include <iostream>
#include <string>
class CViaje {
public:
    std::string ubicacion;
    std::string destino;
    short calificacion;
    std::string nombre_chofer;
    std::string automovil_chofer;
    CViaje() {}
    CViaje(std::string u, std::string d, short cal, std::string cho, std::string aut) {
        this->ubicacion = u;
        this->destino = d;
        this->calificacion = cal;
        this->nombre_chofer = cho;
        this->automovil_chofer = aut;
    }
    std::string mostrar_info() {
        return "Ubicacion: " + ubicacion + "\nDestino: " + destino + "\nChofer: " + nombre_chofer + "\n\tAutomovil: " + automovil_chofer + "\nCalificacion: " + std::to_string(calificacion) + "\n\n";
    }
};
