#pragma once
#include <iostream>
#include <functional>
#include <fstream>
#include "CLista.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ios;

template <typename Generico>
void guardarObjeto(string archivo, Generico obj) {
    std::ofstream guardar;
    guardar.open(archivo, ios::binary | ios::app);
    if(guardar.is_open()) {
        guardar.write((char*)&obj, sizeof(Generico));
        guardar.close();
    } else cout << "~~ERROR, No se pudo abrir el archivo\n";
}

template <typename Generico>
void leerObjetosGuardados(string archivo, CLista<Generico>* lista) {
    std::ifstream leer;
    leer.open(archivo, ios::binary);
    if(leer.is_open()) {
        while(leer.eof() == false) {
            Generico n;
            leer.read((char*)&n, sizeof(Generico));
            lista->push_back(n);
        }
        leer.close();
        lista->pop_back();
    } else cout << "~~ERROR, No se pudo abrir el archivo\n";
}
