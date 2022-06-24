#pragma once
#ifndef _RESTAURANTE_H
#define _RESTAURANTE_H

#endif //_RESTAURANTE_H
#include <iostream>
#include <string>

using namespace std;

class Restaurante {
public:
    string pedido;
    string direccion;
    int opcion;

    Restaurante() {
        cout << "=========Bienvenido a UBER FREIGHT===============\n\n";
        cout << "Por favor ingrese el tipo de comida que desea ordenar: \n";
        cout << "[1] Comida rapida\n";
        cout << "[2] Almuerzos\n";
        cout << "[3] postres\n";
        cout << "[R] regresar\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Por favor, ingrese que tipo de comida rapida desea comer\n\n";
                cout << "[1] Pollo frito\n";
                cout << "[2] Pizza\n";
                cout << "[3] Hamburguesa\n";
                cout << "[R] regresar\n";
                break;

            case 2:
                cout << "Por favor, ingrese que tipo de Almuerzo desea comer\n\n";
                cout << "Menu del dia\n";
                cout << "[1] Pollo a la plancha a lo pobre\n";
                cout << "[2] Lomo saltado\n";
                cout << "[3] Aji de gallina\n";
                cout << "[4] Ensalada Rusa con pollo\n";
                cout << "[R] Regresar\n";
                break;
            case 3:
                cout << "Por favor, ingrese que tipo de postre desea comer\n\n";
                cout << "[1] Helados\n";
                cout << "[2] Tortas\n";
                cout << "[3] Pies\n";
                cout << "[4] Crepas\n";
                cout << "[5] Frapuccinos\n";
                cout << "[R] regresar\n";
                break;


        }
    };

    string mostrar_orden(){
        return "pedido: " + pedido + "\ndireccion: " + direccion + "\n\n";

    }

    bool aceptar_pedido(int opcion){

        if(opcion==1){
            return true;
        } else
            return false;
    }

};