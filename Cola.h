#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include "Cola.h"

class Cola {
    public:
      Nodo* cab;
      Cola();

      void Listar();

      void Add_cab(Nodo* Data);
      void Add_cola(Nodo* Data);

      void Ret_nombre(string& nombre);
      void Ret_cab();
  
      Nodo* buscarCola();
      Nodo* obtenerPrimero();
};

#endif