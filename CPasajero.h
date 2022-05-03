#pragma once
#include <iostream>
#include <string>

using std::string;

class CPasajero {
public:
    string ubicacion;
    string destino;
    short calificacion;
    string nombre_pasajero;

    CPasajero() {}
    CPasajero(string p, string u, string d, short c) {
        nombre_pasajero = p;
        ubicacion = u;
        destino = d;
        calificacion = c;
    }

    string mostrar_info() {
        return "Pasajero: " + nombre_pasajero + "\n\tUbicacion: " + ubicacion + "\n\tDestino: " + destino + "\nCalificaion: " + std::to_string(calificacion) + "\n";
    }
};
