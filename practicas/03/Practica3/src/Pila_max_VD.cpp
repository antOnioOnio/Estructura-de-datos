//#include <cstdlib>
#include <iostream>
//#include <cassert>

using namespace std;
//----------------------------------------------------------------------------------
// Constructor por Defecto

Pila_max::Pila_max()
{

// usamos el constructor por defecto de vector dinamico

}
//----------------------------------------------------------------------------------
// Destructor
Pila_max::~Pila_max()
{

    pila.~VectorDinamico();

}

//----------------------------------------------------------------------------------
// Funcion vacia()

bool Pila_max::vacia()
{
   bool esta = false;
    if (pila.dimension() == 0){
        esta = true;
    }
    return esta;
}

//----------------------------------------------------------------------------------
// Funcion Poner

void Pila_max::poner(int el)
{

    Elemento aux ;
    aux.ele = el;

    if (el > tope().maximo){
        aux.maximo = el;
    }
    else{
        aux.maximo =  tope().maximo;
    }
    pila.insertar(pila.dimension(), aux);



}
//----------------------------------------------------------------------------------
// Funcion quitar

void Pila_max::quitar()
{
    pila.quitarUltimo();

}
//----------------------------------------------------------------------------------
// Funcion tope

Elemento Pila_max::tope()
{
    return pila.ultimoElemento();
}
//----------------------------------------------------------------------------------
// Operator =

Pila_max& Pila_max::operator=(const Pila_max &p)
{
    if ( this != &p){
        this->pila = p.pila;

    }
    return *this;

}
//#endif //PRACTICA3_PILA_MAX_H
