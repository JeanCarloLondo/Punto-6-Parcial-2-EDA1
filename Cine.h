#ifndef CINE
#define CINE

#include <iostream>
#include <string>
using namespace std;

class Cine
{
public:
    string nombre;
    int membresia;
    int pelicula;
    int hora;

    Cine(string nombre, int membresia, int pelicula,
         int hora);


    string to_string();

private:
};

#endif