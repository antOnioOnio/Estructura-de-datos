/**
  * @file cola.h
  * @brief Fichero cabecera del TDA Cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

#ifndef __Cola_H__
#define __Cola_H__

#include <cstdlib>
#include <iostream>
#include <cassert>

/**
 *  @brief T.D.A. Cola
 *
 *
 * Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número
 * de elementos de la cola.
 *
 * @author J. Fdez-Valdivia
 * @date Octubre 2011
*/
template <class T>
class Cola{

private:
    struct Celda {
        T elemento;        ///< Elemento de información.
        Celda * siguiente; ///< Puntero al siguiente nodo.

        /**
         * @brief Constructor por defecto
         */
        Celda() : siguiente(0){
        }
        /**
         * @brief Constructor con parámetros
         * @param elem Elemento de información.
         * @param sig Puntero al siguiente nodo.
         */
        Celda(const T & elem, Celda * sig): elemento(elem), siguiente(sig){
        }
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    Celda * ultima;  ///< Puntero al último nodo de la lista.
    int num_elem;    ///< Número de elementos de la cola.

public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Cola(): primera(0), ultima(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param original La cola de la que se hará la copia.
     */
    Cola(const Cola<T> & original);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Cola();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    Cola& operator= (const Cola<T> & otra);
    /**
     * @brief Comprueba si la cola está vacía
     */
    bool vacia() const{
        return num_elem==0;
    }
    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    T& frente (){
        //assert(primera!=0);        //Si la cola está vacía, abortar
        return primera->elemento;  //Devuelve el elemento del frente de la cola
    }
    /**
     * @brief Devuelve el elemento del frente de una cola constante
     */
    const T & frente () const{
        //assert(primera!=0);        //Si la cola está vacía, abortar
        return primera->elemento;  //Devuelve el elemento del frente de la cola
    }
    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(const T & elem);
    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();
    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const{
        return num_elem;
    }
};
template <class T>
Cola<T>::Cola(const Cola<T> & original){
    if (original.primera!=0){           //Si tiene elementos
        Celda *p = original.primera;      //Copiamos el puntero a la primera celda
        primera = ultima = new Celda(p->elemento,0); //Inicializamos la lista de nodos
        p = p->siguiente;                     //Avanzamos el puntero
        while (p!=0){                         //Mientras queden elementos
            ultima->siguiente = new Celda(p->elemento,0); //Copiamos el elemento
            ultima = ultima->siguiente;                   //Avanzamos los punteros
            p = p->siguiente;
        }
    }
    else
        primera = ultima = 0;            //Si no tiene elementos
    num_elem = original.num_elem;
}

/* _________________________________________________________________________ */

template <class T>
Cola<T>::~Cola(){
    Celda * aux;
    while (primera!=0){             //Mientras queden elementos
        aux = primera;                //Copiamos el puntero
        primera = primera->siguiente; //Avanzamos primera
        delete aux;                   //Borramos el nodo
    }
}

/* _________________________________________________________________________ */

template <class T>
Cola<T>& Cola<T>::operator=(const Cola<T> & otra){
    Celda * p;

    if (this != &otra){    //Comprobación de rigor. Si son diferentes objetos
        while (primera!=0){  //Borramos la lista de nodos de la cola *this
            p = primera;
            primera = primera->siguiente;
            delete p;
        }
        if (otra.primera!=0){        //Si la otra cola tiene elementos
            p = otra.primera;          //Copiamos el puntero al primer nodo
            primera=ultima= new Celda(p->elemento,0); //Reservamos el primer nodo
            p=p->siguiente;                           //Avanzamos el puntero
            while (p!=0){                             //Mientras queden elementos
                ultima->siguiente=new Celda(p->elemento,0); //Creamos un nuevo nodo
                ultima=ultima->siguiente;                   //Actualizamos ultima
                p=p->siguiente;                             //Avanzamos el puntero
            }
        }
        else primera=ultima=0;      //Si la otra cola está vacía
        num_elem=otra.num_elem;
    }
    return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

template <class T>
void Cola<T>::poner(const T & elem){
    Celda *aux = new Celda(elem,0);    //Creamos un nuevo nodo
    if (primera==0)                    //Si la lista está vacía,
        primera = ultima = aux;          //primera y ultima apuntan a ese nodo
    else{                              //Si la lista ya tenia nodos,
        Celda *aux2 = primera;
        primera = aux;
        primera->siguiente = aux2;
       // aux ->siguiente = primera;
       // primera = aux;
    }
    num_elem++;                //Incrementamos el numero de elementos
}

/* _________________________________________________________________________ */

template <class T>
void Cola<T>::quitar(){
    assert(primera!=0);             //Si la cola está vacía, abortar
    Celda *aux = primera;           //Copiamos el puntero al primer nodo
    primera = primera->siguiente;   //Actualizamos primera
    delete aux;                     //Borramos el primer nodo
    if (primera == 0)               //Si no quedan nodos,
        ultima=0;                     //actualizamos ultima
    num_elem--;                     //Actualizamos el número de elementos
}



#endif // __Cola_H__
