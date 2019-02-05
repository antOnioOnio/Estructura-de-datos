//#include <cstdlib>
#include <iostream>
//#include <cassert>

using namespace std;
//----------------------------------------------------------------------------------
// Constructor por Defecto

Pila_max::Pila_max()
{

// usamos el constructor por defecto de la cola

}
//----------------------------------------------------------------------------------
// Destructor
Pila_max::~Pila_max()
{

    pila.~Cola();

}

//----------------------------------------------------------------------------------
// Funcion vacia()

bool Pila_max::vacia()
{
  
    return pila.vacia();
}

//----------------------------------------------------------------------------------
// Funcion Poner

void Pila_max::poner(int el)
{
    Elemento aux ;
    aux.ele = el;
    int maximo_actual = 0;
    if ( pila.vacia()){
        aux.maximo = el;
        pila.poner(aux);
    }
    else{
        maximo_actual = pila.frente().maximo;
        if (el > maximo_actual){
            aux.maximo = el;
            pila.poner(aux);
        }
    }

}
//----------------------------------------------------------------------------------
// Funcion quitar

void Pila_max::quitar()
{
    pila.quitar();

}
//----------------------------------------------------------------------------------
// Funcion tope

Elemento Pila_max::tope()
{
    return pila.frente();
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
