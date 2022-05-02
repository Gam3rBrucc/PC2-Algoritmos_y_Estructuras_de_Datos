#pragma once
#include <iostream>
#include "CTaxista.h"
#include <string>

using std::string;

class CViaje {
public:
    string ubicacion;
    string destino;
    short calificacion;
    CTaxista chofer;

    CViaje() {}
    CViaje(string u, string d, short cal, CTaxista cho) {
        ubicacion = u;
        destino = d;
        calificacion = cal;
        chofer = cho;
    }

    string mostrar_info() {
        return "Ubicacion: " + ubicacion + "\nDestino: " + destino + "Chofer: " + chofer.get_nombre() + " " + chofer.get_apellido() + "\n\tAutomovil: " + chofer.info_auto() + "\nCalificacion: " +
                std::to_string(calificacion) + "\n";
    }
};
