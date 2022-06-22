#include <iostream>
#include <vector>
#include "CMenu.h"
#include "Archivo.h"
#include "CUsuario.h"
#include "CTaxista.h"

int main() {
    srand(time(NULL));

    std::vector<CUsuario> lista_usuarios;
    std::vector<CTaxista> lista_taxistas;

    leerObjetosGuardados("usuarios.txt", &lista_usuarios);
    leerObjetosGuardados("taxistas.txt", &lista_taxistas);

    printf("===============================\n");
    printf("\tBienvendio a UPC Rider!\n");
    printf("===============================\n");
    printf("La app desarrollada por la mentes mas ingeniosas de la UPC.\n\n");
    printf("\tU20211E803 - Bruce Matias Fleck Ojeda\n");
    printf("\tU202116752 - Cesar Rafael Sanchez Garay\n");
    printf("\tU201921599 - Joaquin Enrique Mantilla Huaranga\n\n");
    printf("Esperamos le guste nuestro trabajo!\n\n");

    CMenu(&lista_usuarios, &lista_taxistas);

    limpiarArchivo("usuarios.txt");
    limpiarArchivo("taxistas.txt");
    for(auto i : lista_usuarios) guardarObjeto("usuarios.txt", i);
    for(auto i : lista_taxistas) guardarObjeto("taxistas.txt", i);

    return 0;
}
