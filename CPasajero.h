#pragma once
#ifndef UNTITLED10_CPASAJERO_H
#define UNTITLED10_CPASAJERO_H

#endif //UNTITLED10_CPASAJERO_H
#include <iostream>
#include <string>
class CPasajero {
public:
    std::string ubicacion;
    std::string destino;
    short calificacion;
    std::string nombre_pasajero;
    CPasajero() {}
    CPasajero(std::string p, std::string u, std::string d, short c) {
        this->nombre_pasajero = p;
        this->ubicacion = u;
        this->destino = d;
        this->calificacion = c;
    }
    std::string mostrar_info() {
        return "Pasajero: " + nombre_pasajero + "\n\tUbicacion: " + ubicacion + "\n\tDestino: " + destino + "\nCalificaion: " + std::to_string(calificacion) + "\n\n";
    }
};
