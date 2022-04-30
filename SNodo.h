#pragma once
#include <iostream>

template <typename Generico>
struct Nodo {
    Generico elemento;
    Nodo<Generico>* sig;
    Nodo<Generico>* ant;

    Nodo(Generico e) {
        elemento = e;
        sig = ant = nullptr;
    }
};
