//
// Created by antonio garcia on 29/10/17.
//

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
    Pila_max(const Pila_max &p);

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
#include "../src/Pila_Max_cola.cpp"
#endif
