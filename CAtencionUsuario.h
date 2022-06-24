#pragma once
#ifndef TF_ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_CATENCIONUSUARIO_H
#define TF_ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_CATENCIONUSUARIO_H

#endif //TF_ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_CATENCIONUSUARIO_H
#include <iostream>
class CAtencionUsuario {
    int ticket = rand() % 500;
    char opcion, op2, op3;
    char solicitud[500], reclamo[500];
public:
    CAtencionUsuario() {

        printf("================== Atencion al cliente ==================\n\n");
        printf("\t[1] Preguntas Frecuentes \n");
        printf("\t[2] Libro de Reclamaciones\n");
        printf("\t[S] Regresar\n\n");
        printf("Por favor elija una opcion: ");
        std::cin >> opcion;
        //Preguntas frecuentes
        if (opcion == '1') {
            printf("\t[1] Usuarios\n");
            printf("\t[2] CONDUCIR Y HACER ENTREGAS \n");
            printf("\t[3] UPC RIDER EATS\n");
            printf("\t[4] ESTABLECIMIENTOS Y RESTAURANTES\n");
            printf("\t[5] ¿No te solucionaste tu duda? Contactanos \n");
            printf("\t[S] Regresar\n\n");
            printf("Por favor elija una opcion: ");
            std::cin >> op2;
            if (op2 == '1') {
                printf("\t[1] Ayuda con un viaje\n");
                printf("\t[2] Cuenta y opciones de pago \n");
                printf("\t[3] Mas\n");
                printf("\t[]Tu Guia UPC Rider\n");
                printf("\t[] UBER FREIGHT\n");
                printf("\t[] EMPRESAS\n");
                printf("\t[S] Regresar\n\n");
                printf("Por favor elija una opcion: ");
            } else if (op2 == '2') {
                printf("\t[1] Ayuda con un viaje\n");
                printf("\t[2]Problemas con la cuenta o la app \n");
                printf("\t[3] Problemas con el cliente y con el establecimiento\n");
                printf("\t[] Ganancias y pagos\n");
                printf("\t[] Una guía para conducir y entregar\n");
                printf("\t[] Ayuda con un artículo encontrado\n");
                printf("\t[S] Seguridad\n\n");
                printf("\t[S] Accesibilidad\n\n");
                printf("\t[S] Más\n\n");
                printf("Por favor elija una opcion: ");
            } else if (op2 == '3') {
                printf("\t[1] Ayuda con un pedido\n");
                printf("\t[2] Cuenta y Pagos \n");
                printf("\t[3] Aspectos basicos sobre la entrega y recoleccion\n");
                printf("Por favor elija una opcion: ");
            } else if (op2 == '4') {
                printf("\t[1] Cierre de Uber Eats\n");
                printf("\t[2] Soporte relacionado con los pedidos\n");
                printf("\t[3] Gestión de pedidos\n");
                printf("\t[] Soporte técnico \n");
                printf("\t[] Soporte relacionado con la cuenta y los pagos\n");
                printf("\t[]  Guía para Uber Eats\n");
                printf("\t[]  Haz crecer tu negocio con la app Uber Eats \n");
                printf("\t[]  Uber Direct\n");
                printf("\t[]  Tienda web\n");
                printf("\t[S] \n\n");

                printf("Por favor elija una opcion: ");
            } else if (op2 == '5') {
                printf("\t-------------GENERANDO TICKET----------\n");
                std::cout << "Su ticket es el numero: " << ticket << " en la cola ";
                printf("\tEn breve lo atenderemos ....\n");
                printf("\tHola, mi nombre es Rodolfo y me encargare de atenterlo \n");
                printf("\t¿Cual es su duda, cuenteme? \n");
                std::cin >> reclamo;
                printf("\tGracias por contactar con nosotros en breve resolveremos su duda \n");
                printf("\tSu problema o inquitud fue resuelta magicamente, agradecemos su espera \n");
                printf("\tHasta la proxima!!!! \n");
            } else if (op2 == 's' || op2 == 'S') {

            }
            //Libro de Reclamaciones
        } else if (opcion == '2') {
            printf("\t Registra 2 tipos de insatisfacciones: quejas y reclamaciones \n\n");
            printf("\t Ingrese su solicitud AQUI \n\n");
            std::cin >> solicitud;
            printf("\t Muchas gracias por ingresar su solicitud, le comunicaremos cuando la hayamos revisado :) \n\n");
        } else if (opcion == 's' || opcion == 'S') {
            printf("=============================================\n");
            printf("Hasta luego! (^o^)/\n");
            printf("=============================================\n");
        }
    }
};