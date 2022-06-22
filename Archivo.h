#pragma once
#ifndef UNTITLED10_ARCHIVO_H
#define UNTITLED10_ARCHIVO_H

#endif //UNTITLED10_ARCHIVO_H
#include <iostream>
#include <vector>
#include "CUsuario.h"
#include "CTaxista.h"

void limpiarArchivo(std::string nombre_arch) {
    FILE* archivo = fopen(nombre_arch.c_str(), "w");
    if(archivo == NULL) printf("~~ERROR, No se pudo abrir el archivo \"%s\"\n",nombre_arch.c_str());
}
void guardarObjeto(std::string nombre_arch, CUsuario obj) {
    FILE* archivo = fopen(nombre_arch.c_str(), "a");
    if(archivo != NULL) {
        fprintf(archivo, "%s %s %s %hi %d\n",obj.get_nombre().c_str(), obj.get_apellido().c_str(), obj.get_password().c_str(), obj.get_edad(), obj.get_num_cel());
        fclose(archivo);
    } else printf("~~ERROR, No se pudo abrir el archivo \"%s\"\n",nombre_arch.c_str());
}
void guardarObjeto(std::string nombre_arch, CTaxista obj) {
    FILE* archivo = fopen(nombre_arch.c_str(), "a");
    if(archivo != NULL) {
        fprintf(archivo, "%s %s %s %hi %d %s %s\n",obj.get_nombre().c_str(), obj.get_apellido().c_str(), obj.get_password().c_str(), obj.get_edad(), obj.get_num_cel(), obj.get_modelo_auto().c_str(), obj.get_placa_auto().c_str());
        fclose(archivo);
    } else printf("~~ERROR, No se pudo abrir el archivo \"%s\"\n",nombre_arch.c_str());
}
void leerObjetosGuardados(std::string nombre_arch, std::vector<CUsuario>* lista) {
    FILE* archivo = fopen(nombre_arch.c_str(), "r");
    if(archivo != NULL) {
        while(!feof(archivo)) {
            char* nombre = new char[16];
            char* apellido = new char[16];
            char* contrasenia = new char[32];
            short edad;
            int num_cel;
            fscanf(archivo, "%s %s %s %hi %d", nombre, apellido, contrasenia, &edad, &num_cel);
            lista->push_back(CUsuario(nombre, apellido, contrasenia, edad, num_cel));
            delete[] nombre;
            delete[] apellido;
            delete[] contrasenia;
        }
        fclose(archivo);
        if(lista->size() >= 2)
            lista->pop_back(); // esto es para eliminar el objeto duplicado que siempre aparece al final
    } else printf("~~ERROR, No se pudo abrir el archivo \"%s\"\n",nombre_arch.c_str());
}
void leerObjetosGuardados(std::string nombre_arch, std::vector<CTaxista>* lista) {
    FILE* archivo = fopen(nombre_arch.c_str(), "r");
    if(archivo != NULL) {
        while(!feof(archivo)) {
            char* nombre = new char[32];
            char* apellido = new char[32];
            char* contrasenia = new char[32];
            short edad;
            int num_cel;
            char* modelo_auto = new char[32];
            char* placa_auto = new char[32];
            fscanf(archivo, "%s %s %s %hi %d %s %s", nombre, apellido, contrasenia, &edad, &num_cel, modelo_auto, placa_auto);
            lista->push_back(CTaxista(nombre, apellido, contrasenia, edad, num_cel, CAutomovil(modelo_auto, placa_auto)));
            delete[] nombre;
            delete[] apellido;
            delete[] contrasenia;
            delete[] modelo_auto;
            delete[] placa_auto;
        }
        fclose(archivo);
        if(lista->size() >= 2)
            lista->pop_back(); // esto es para eliminar el objeto duplicado que siempre aparece al final
    } else printf("~~ERROR, No se pudo abrir el archivo \"%s\"\n",nombre_arch.c_str());
}
