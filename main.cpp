#include <iostream>
#include "CMenu.h"
#include "CLista.h"
#include "Archivo.h"
#include "CTaxista.h"
#include "CAutomovil.h"
#include "CPila.h"

using std::cout;
using std::endl;

// TODO hacer un metodo de ordenamiento

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
//
//int main() {
//
//    CPila<Person> pila(3);
//
//    pila.push(Person("Bruci", 19));
//    pila.push(Person("Dibi", 17));
//    pila.push(Person("grrrr", 99));
//
//    pila.peek([](Person o){cout << o.info() << endl;});
//
//    pila.push(Person("Tilin", 12));
//
//    pila.peek([](Person o){cout << o.info() << endl;});
//
//    return 0;
//};
