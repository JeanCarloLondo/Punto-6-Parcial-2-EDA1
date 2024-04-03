#include <iostream>
#include "Menu.h"

// Definición de códigos ANSI para colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m" //"\033[40m\033[34m"

void mostrarMenu() {
    std::cout << YELLOW << "\n\nCine Ruben Dario Borja" << RESET << std::endl;
    std::cout << BLUE << "1- Dar Turno" << RESET << std::endl;
    std::cout << GREEN << "2- Atender"<< RESET << std::endl;
    std::cout << BLUE << "3- Cancelar función"<< RESET << std::endl;
    std::cout << BLUE << "4- Mostrar lista de boletas"<< RESET << std::endl;
    std::cout << RED <<  "5- Terminar\n" << RESET << std::endl;
}

int obtenerOpcion() {
    char opcion;
    std::cout << GREEN << "Ingrese la opción: "<< RESET;
    std::cin >> opcion;
    std::cout << RESET;

    //validar un numero entre 1 y 4
    if (opcion >= 49  && opcion <= 52) { //[0]=49 y [4]=42 en ascii
        return opcion - 48; //para tener un numero desde 1, 48 es el 0 en Ascci
    }
    return 0;
}
