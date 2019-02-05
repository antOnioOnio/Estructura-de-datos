
/*

  ** Función de abstracción:
     ----------------------

     fA : tipo_rep  -------> Tipo Abstracto
        {datos, num_comp}--> { datos[0], datos[1], ..., datos[num_comp - 1]}


  ** Invariante de Representación:
     ----------------------------
     Cualquier objeto del tipo_rep, {datos, num_comp}, debe cumplir:
     - num_comp >= 0;
     - datos: apunta a una zona con capacidad para albergar a
       'num_comp' objetos de la clase T.
 */

#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;

//----------------------------------------------------------------------------------

template<class T>
VectorDinamico<T>::VectorDinamico() {
    datos = new T[1];
    num_comp = 0;
    reservados = 0;
}

//----------------------------------------------------------------------------------

template <class T>
VectorDinamico<T>::VectorDinamico(int num_elem)
{
    datos = new T[num_elem];
    if (datos == 0)
    {
       std::cout<< "Memoria Insuficiente\n";
        exit(-1);
    }
    num_comp = 0;
    reservados = num_elem;
}

//----------------------------------------------------------------------------------


template <class T>
VectorDinamico<T>::~VectorDinamico()
{
    delete [] datos;
    datos = 0;
    num_comp = 0;
    reservados = 0;
}

//----------------------------------------------------------------------------------

template <class T>
int
VectorDinamico<T>::redimensionar(int num_elem)
{
    if( num_elem > reservados ){
        T *aux = new T[num_elem];
        for (int i=0; i<num_comp; i++){
            aux[i]=datos[i];
        }

        delete[] datos;
        datos = aux;
        reservados=num_elem;
    }

}

//----------------------------------------------------------------------------------


template <class T>
int
VectorDinamico<T>::dimension() const
{
    return num_comp;
}

//----------------------------------------------------------------------------------

template <class T>
T
VectorDinamico<T>::componente(int i) const
{
    assert (0 <= i && i <= num_comp);

    return datos[i];
}
//----------------------------------------------------------------------------------

template <class T>
T VectorDinamico<T>::ultimoElemento() const
{
    return this->datos[num_comp-1];
}

//----------------------------------------------------------------------------------

template <class T>
void
VectorDinamico<T>::insertar(int i, const T & valor)
{
    if (num_comp == reservados){
        if (num_comp == 0){
            redimensionar(1);
        }
        else {
            redimensionar(2*reservados);
        }
    }
    datos[num_comp]=valor;
    num_comp++;

}
//----------------------------------------------------------------------------------

template <class T>
void
VectorDinamico<T>::quitarUltimo() {
    if (num_comp!=0){
        num_comp--;
    }
}

//----------------------------------------------------------------------------------

template <class T>
T &
VectorDinamico<T>::operator[](int i) {
    assert (0 <= i && i <= num_comp);

    return datos[i];
}

//----------------------------------------------------------------------------------


