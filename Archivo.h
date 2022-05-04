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

void limpiarArchivo(string archivo) // Para cambiar datos, se guarda la lista y se crea una nueva pero con los datos nuevos
{
    std::ofstream limpiar;
    limpiar.open(archivo, ios::binary);
    if(limpiar.is_open()) {}
    else cout << "~~ERROR, No se pudo abrir el archivo \"" << archivo << "\"\n";
}

template <typename Generico>
void guardarObjeto(string archivo, Generico obj) {
    std::ofstream guardar;
    guardar.open(archivo, ios::binary | ios::app);
    if(guardar.is_open()) {
        guardar.write((char*)&obj, sizeof(Generico));
        guardar.close();
    } else cout << "~~ERROR, No se pudo abrir el archivo \"" << archivo << "\"\n";
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
        if(lista->get_t() > 1) lista->pop_back();

    } else cout << "~~ERROR, No se pudo abrir el archivo \"" << archivo << "\"\n";
}
