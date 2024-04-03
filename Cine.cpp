#include <iostream>
#include <string>
#include "Cine.h"
#include <sstream>

using namespace std;

Cine::Cine(string nombre, int membresia, int pelicula, int hora)
{
    this->nombre = nombre;
    this->membresia = membresia;
    this->pelicula = pelicula;
    this->hora = hora;
}

string Cine::to_string()
{

    // Convierto las variable de tipo int  en un string

    std::string tipo_membresia;

    // Convertir el valor de membresía a un string
    if (membresia == 0)
    {
        tipo_membresia = "Normal";
    }
    else if (membresia == 1)
    {
        tipo_membresia = "VIP";
    }

    // Mismo comportamiento con la variable pelicula
    std::string tipo_pelicula;

    if (pelicula == 1)
    {
        tipo_pelicula = "La cucaracha mágica";
    }
    else if (pelicula == 2)
    {
        tipo_pelicula = "Lentos Y Calmados 45";
    }
    else if (pelicula == 3)
    {
        tipo_pelicula = "Pelicula de moda generica";
    }
    else if (pelicula == 4)
    {
        tipo_pelicula = "La increible historia de EdiEdi";
    }

    // Mismo comportamiento con la variable hora
    std::string tipo_hora;
    if (hora == 1)
    {
        tipo_hora = "11:30";
    }
    else if (hora == 2)
    {
        tipo_hora = "13:00";
    }
    else if (hora == 3)
    {
        tipo_hora = "15:45";
    }
    else if (hora == 4)
    {
        tipo_hora = "17:20";
    }
    else if (hora == 5)
    {
        tipo_hora = "19:00";
    }
    else if (hora == 6)
    {
        tipo_hora = "21:30";
    }
    else if (hora == 7)
    {
        tipo_hora = "00:00";
    }

    string valor = "";
    valor = "Nombre: " + nombre + ", Membresía: " + tipo_membresia + ", Pelicula elegida: " + tipo_pelicula +
            ", Hora de función: " + "(" + tipo_hora + ")";
    return valor;
}