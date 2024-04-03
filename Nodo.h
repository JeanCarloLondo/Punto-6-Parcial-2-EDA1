#ifndef NODO_H
#define NODO_H

#include "Cine.h"


class Nodo {
    public:
        Nodo();
        Nodo(Cine* cine);
        ~Nodo();

        void setData(Cine* data);
        Cine* getData();

        void setSig(Nodo* siguiente);
        Nodo* getSig();

    private:
        Cine* data_;
        Nodo* sig; 
};


#endif