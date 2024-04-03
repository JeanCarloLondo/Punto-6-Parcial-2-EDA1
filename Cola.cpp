#include <iostream>
#include "Cola.h"
#include "Nodo.h"

Cola::Cola()
{
  cab = nullptr;
}

void Cola::Listar()
{

  if (cab == nullptr)
  {
    cout << "La cola se encuentra vacía" << endl;
    return;
  }

  // iteracion de todos los elementos
  Nodo *actual;
  actual = cab;
  int i = 1;
  std::cout << "Listar \n";
  while (actual != nullptr)
  {
    Cine *item = actual->getData();
    std::cout << "[" << std::to_string(i) << "]: "
              << item->to_string() << std::endl;
    i = i + 1;
    actual = actual->getSig();
  }
}

Nodo *Cola::buscarCola()
{
  Nodo *actual;
  actual = cab;
  while (actual->getSig() != nullptr)
  {
    actual = actual->getSig();
  }
  return actual;
}

Nodo *Cola::obtenerPrimero()
{
  if (cab != nullptr)
  {
    return cab;
  }
  else
  {
    cout << "La cola está vacía." << endl;
    return nullptr;
  }
}

void Cola::Add_cab(Nodo *Data)
{
  Data->setSig(cab);
  cab = Data;
}

void Cola::Add_cola(Nodo *Data)
{
  if (cab == nullptr)
  { // La lista es vacía
    cab = Data;
  }
  else
  {
    Nodo *cola = buscarCola();
    cola->setSig(Data);
  }
}

void Cola::Ret_nombre(string &nombre)
{
  Nodo *actual = cab;
  Nodo *anterior = nullptr;
  bool encontrado = false;

  while (actual != nullptr)
  {
    if (actual->getData()->nombre == nombre)
    {
      encontrado = true;
      break;
    }
    anterior = actual;
    actual = actual->getSig();
  }

  if (encontrado)
  {
    // Si se encontró el nodo, retirarlo de la cola
    if (actual == cab)
    {
      // Si el nodo a retirar es el primero en la cola
      cab = actual->getSig();
    }
    else
    {
      // Si el nodo a retirar está en el medio o al final de la cola
      anterior->setSig(actual->getSig());
    }
  }
}
  void Cola::Ret_cab()
  {
    if (cab != nullptr)
    {
      cab = cab->getSig();
    }
  }
