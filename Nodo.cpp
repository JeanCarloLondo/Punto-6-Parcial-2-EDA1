#include "Nodo.h"
#include "Cine.h"

Nodo::Nodo()
{
    sig = nullptr;
}

Nodo::Nodo(Cine *data)
{
    data_ = data;
    sig = nullptr;
}

Nodo::~Nodo()
{
    std::cout << "El objeto se destruira" << std::endl;
}

void Nodo::setData(Cine *data)
{
    data_ = data;
}

Cine *Nodo::getData()
{
    return data_;
}

void Nodo::setSig(Nodo *siguiente)
{
    sig = siguiente;
}


Nodo *Nodo::getSig()
{
    return sig;
}
