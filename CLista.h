#pragma once
#include <iostream>
#include <functional>
#include "CNodo.h"

using std::string;
using std::cout;
using std::endl;

template <class Generico>
class CLista {
    Nodo<Generico>* inicio;
    Nodo<Generico>* fin;
    size_t t;
public:
    CLista() {
        inicio = fin = nullptr;
        t = 0;
    }

    void push_front(Generico e) {
        Nodo<Generico>* n = new Nodo<Generico>(e);
        if(t == 0) inicio = fin = n;
        else {
            n->ant = fin;
            fin->sig = n;
            fin = n;
        }
        ++t;
    }
    void push_back(Generico e) {
        Nodo<Generico>* n = new Nodo<Generico>(e);
        if(t == 0) inicio = fin = n;
        else {
            n->sig = inicio;
            inicio->ant = n;
            inicio = n;
        }
        ++t;
    }
    void pop_front() {
        Nodo<Generico>* n = fin->ant;
        fin->ant = fin->sig = nullptr;
        delete fin;
        fin = n;
        fin->sig = nullptr;
        --t;
    }
    void pop_back() {
        Nodo<Generico>* n = inicio->sig;
        inicio->ant = inicio->sig = nullptr;
        delete inicio;
        inicio = n;
        inicio->ant = nullptr;
        --t;
    }
    void recorrer_inicio(std::function<void(Generico)> r_nodo) {
        Nodo<Generico>* n = inicio;
        if(n == nullptr) return;
        while(n->sig != nullptr) {
            r_nodo(n->elemento);
            n = n->sig;
        }
        r_nodo(n->elemento);
    }
    void recorrer_fin(std::function<void(Generico)> r_nodo) {
        Nodo<Generico>* n = fin;
        if(n == nullptr) return;
        while(n->ant != nullptr) {
            r_nodo(n->elemento);
            n = n->ant;
        }
        r_nodo(n->elemento);
    }
    Generico buscar_indice(size_t indice) {
        Nodo<Generico>* n = inicio;
        for(size_t i=0; i<indice; ++i) {
            n = n->sig;
        }
        return n->elemento;
    }
    size_t get_t() {
        return t;
    }
};
