#pragma once
#include <iostream>
#include <functional>
#include "CNodo.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class Generico>
class CPila {
    Nodo<Generico>* primero;
    Nodo<Generico>* ultimo;
    size_t t;
    size_t tope;

public:
    CPila() {
        primero = ultimo = nullptr;
        t = 0;
        tope = -1;
    }
    CPila(size_t n) {
        primero = ultimo = nullptr;
        t = 0;
        tope = n;
    }

    void peek(std::function<void(Generico)> r_nodo) {
        if(!vacio()) r_nodo(ultimo->elemento);
        else cout << "\n~~pila vacia\n"; // temporal
    }
    void push(Generico e) {
        Nodo<Generico>* n = new Nodo<Generico>(e);
        if(t == tope) {
            cout << "\n\n~~Pila llena\n"; // temporal
            return;
        }
        if(t == 0) primero = ultimo = n;
        else {
            ultimo->sig = n;
            n->ant = ultimo;
            ultimo = n;
        }
        ++t;
    }
    void pop() {
        if(vacio()) {
            cout << "\n\n~~La pila ya esta vacia\n"; // temporal
        } else if(t == 1) {
            delete ultimo;
            ultimo = primero = nullptr;
            --t;
        } else {
            Nodo<Generico>* n = ultimo;
            ultimo = n->ant;
            ultimo->sig = nullptr;
            delete n;
            --t;
        }
    }
    void recorrer_ultimo(std::function<void(Generico)> r_nodo) {
        Nodo<Generico>* n = ultimo;
        if(n == nullptr) return;
        while(n->ant != nullptr) {
            r_nodo(n->elemento);
            n = n->ant;
        }
        r_nodo(n->elemento);
    }
    void recorrer_primero(std::function<void(Generico)> r_nodo) {
        Nodo<Generico>* n = primero;
        if(n == nullptr) return;
        while(n->sig != nullptr) {
            r_nodo(n->elemento);
            n = n->sig;
        }
        r_nodo(n->elemento);
    }
    bool vacio() {
        if(t == 0) return true;
        else return false;
    }
    bool lleno() {
        if(t == tope) return true;
        else return true;
    }
    size_t get_t() {
        return t;
    }
};
