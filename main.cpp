#include <iostream>
#include "CMenu.h"
#include "CLista.h"
#include "Archivo.h"
#include "CTaxista.h"
#include "CAutomovil.h"

using std::cout;
using std::endl;

int main() {
    cout << "===============================\n";
    cout << "\tBienvendio a UPC Rider!\n";
    cout << "===============================\n";
    cout << "La app desarrollada por la mentes mas ingeniosas de la UPC.\n\n";
    cout << "\tU20211E803 - Bruce Matias Fleck Ojeda\n";
    cout << "\tU202116752 - Cesar Rafael Sanchez Garay\n";
    cout << "\tU201921599 - Joaquin Enrique Mantilla Huaranga\n\n";
    cout << "Esperamos le guste nuestro trabajo!\n";
    cout << "============================================\n";

    CMenu();

    return 0;
}

//struct Person {
//    std::string name;
//    short age;
//
//    Person() {}
//    Person(string n, short a) {
//        name = n;
//        age = a;
//    }
//
//    std::string info() {
//        return name + ", " + std::to_string(age);
//    }
//};

//int main() {
////    CTaxista* t1 = new CTaxista("Fulano", "Mengano", 20, 333666999, "abc123", CAutomovil("Tesla", "BRUV-123"));
////    CTaxista* t2 = new CTaxista("Fulano", "Mengano", 20, 333666999, "abc123", CAutomovil("N/A", "N/A"));
////
////    guardarObjeto("test.bin", *t1);
////    guardarObjeto("test.bin", *t2);
//
//    CLista<CTaxista> lista;
//
//    leerObjetosGuardados("test.bin", &lista);
//
//    lista.recorrer_inicio([](CTaxista o){cout << o.mostrar_info() << endl;});
//
//    return 0;
//};
