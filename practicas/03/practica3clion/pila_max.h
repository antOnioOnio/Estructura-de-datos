
#ifndef PRACTICA3_PILA_MAX_H
#define PRACTICA3_PILA_MAX_H

#include <iostream>
#include <cassert>
#include "cola.h"

using namespace std;

struct Elemento{
    int ele;
    int maximo;
};

std::ostream& operator<<(std::ostream & os,const Elemento & a){
    os<< " Elemento " << a.ele << " Maximo: "<<a.maximo<<endl;
    return os;
}

class Pila_max {
private:
    Cola<Elemento> pila;

public:

    /**
    * @brief      Constructor por defecto
    */
    Pila_max();

    /**
    * @brief             Constructor de copias
    *
    * @param[in]  p      Objeto que sera copiado, constante.
    */
   // Pila_max(const Pila_max &p);

    /**
    * @brief      Destructor de la clase
    */
    ~Pila_max();

    /**
     * @brief   funcion para saber si esta vacia la pila
     * @return true vacia, false si no lo esta
     */
    bool vacia();

    /**
     * @brief      Añadimos int a la pila en el tope
     *
     * @param[in]  t     Objeto a añadir
     */
    void poner(int el);

    /**
    * @brief      Quitamos un elemento de la pila
    */
    void quitar();

    /**
     * @brief funcion que nos devuelve el elemento tope
     * @return elemento tope
     */
    Elemento tope();

    /**
     * @brief operator = de la clase
     */
    Pila_max &operator=(const Pila_max & p);

};
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

    if (el > tope().maximo){
        aux.maximo = el;
    }
    else{
        aux.maximo =  tope().maximo;
    }
    pila.poner(aux);



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
#include "cola.h"

//Pila_max::Pila_max(const Pila_max &p) {

//}


#endif