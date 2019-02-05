/**
 @file Evento_Historico.h
  * @brief Fichero cabecera del TDA Evento_Historico
  */


#ifndef _Evento_Historico_
#define _Evento_Historico_

#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include <utility>
#include <set> 

using namespace std;

/**
  *  @brief T.D.A. Evento_Historico
  *
  * Una instancia @e c del tipo de datos abstracto @c Evento_Historico es un objeto
  * con un campo pair<int, set<string> > evento
  * donde el primer campo del pair representa nuestro año y el segundo almacenara nuestros 
  * eventos que acaecieron en ese año
  *
  * Año 
  * *)Evento_Historico_1
  * ...
  * ...
  * *)Evento_Historico_N 
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author     Antonio Garcia Castillo
  * @author 
  * @date       20/11/2017
  */

class Evento_Historico {
    /**
     * @page repConjunto Rep del TDA Evento_Historico
     * 
     * Un objeto válido del TDA Evento_Historico representa el valor
     * 
     * Año#evento1#evento2#....#eventon
     * 
     */

private:
  pair<int,set<string> >evento ;

public:

    /**
      * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar 
      * errores o asignaciones de basura a objetos de nuestra clase. Crea una Fecha Historica 
      * por defecto con año 0 y con un set inicializado a ""
      */

  Evento_Historico();


/**
  * @brief Constructor de la clase
  * @param a año del evento a construir
  * @param eventos set de string con el evento o eventos de ese año
  * @return Crea el evento con año a eventos asociados al set
  */

  Evento_Historico(int a, set<string> eventos);

/**
  * @brief Constructor de copias de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */

  Evento_Historico(const Evento_Historico& e);

/**
  * @brief Destructor de la clase
  */

  ~Evento_Historico();


/**
  * @brief Método de acceso al año de la Evento_Historico
  * @return int con el valor del campo anio
  */

  int getAnio ()const;

/**
 * @brief      Metodo de acceso al tamaño del set
 *
 * @return     Numero de eventos 
 */
  int size(){ return evento.second.size();}

/**
  * @brief Añade un evento
  * @param event string con evento a añadir
  */

  void aniadirevento(string& event);


/**
  * @brief Búsqueda de eventos en una Evento_Historico dada una palabra clave s
  * @param s string con la palabra a buscar
  * @param matches nueva Evento_Historico donde se introducen únicamente los eventos de this que contienen el string s
  * @return Devuelve true o false indicando si hay o no algún match de la cadena clave s en los eventos de this
  */

 
 
 bool buscarEventos(string s);

/**
  * @brief Salida de un Evento_Historico a ostream
  * @param os stream de salida
  * @param e Evento_Historico a escribir
  * @post Se muestra la Evento_Historico en formato "año#evento1#evento2#...#eventoN" 
  */

 friend ostream& operator<< (ostream& os, const Evento_Historico& e);

/**
  * @brief Entrada de un Evento_Historico desde istream
  * @param is stream de entrada
  * @param e Evento_Historico que recibe el valor
  * @retval El Evento_Historico leído en e
  * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN
  */

 friend istream& operator>> (istream& is, Evento_Historico& e);  

/**
  * @brief Operador = del TDA Evento_Historico
  * @param fec de tipo Evento_Historico que se asignara a otro TDA Evento_Historico
  * 
  */


 Evento_Historico &operator=(const Evento_Historico& fec);

/**
 * @brief      operator+ del TDA Evento_Historico
 *
 * @param[in]  e     Objeto constante de tipo Evento_Historico a sumar
 * @pre        ambos objetos deben tener el mismo anio
 * @return     *this con la suma de ambos eventos
 */

 Evento_Historico operator+( const Evento_Historico& e);


/**
 * @brief clase para iterar sobre la clase evento
 * */
class iterator{
 private:
  set<string>::iterator it;
 public:
   iterator & operator++()
   {
     ++it;
   }

   iterator & operator--()
   {
    --it;
   }

   const string &operator *()
   {
    return *it; 
   }

   bool operator ==(const iterator &i)
   {
    return i.it==it;
   }    
   
   bool operator !=(const iterator &i)
   {
    return i.it!=it;
   }
   friend class Evento_Historico;
};

class const_iterator{
 private:
  set<string>::const_iterator it;
 public:
   const_iterator & operator++()
   {
     ++it;
   }

   const_iterator & operator--()
   {
    --it;
   }

   const string &operator *()
   {
    return *it; 
   }

   bool operator ==(const const_iterator &i)
   {
    return i.it==it;
   }    
   
   bool operator !=(const const_iterator &i)
   {
    return it != i.it;
   }

   const_iterator& operator=(const const_iterator& i){
    this->it = i.it;
    return *this;
   }
   friend class Evento_Historico;
};
  /**
   * @brief      Inicializa un iterator al principio del TDA Evento_Historico
   *
   * @return     Iterator al comiemzo del set de strings
   */
  iterator begin()
  {
    iterator i;
    i.it=evento.second.begin();
  return i;

  } 
   /**
   * @brief      Inicializa un iterator al final del TDA Evento_Historico
   *
   * @return     Iterator al final del set de strings
   */
  iterator end()
  {
    iterator i;
    i.it=evento.second.end();
  return i;
  }

  /**
   * @brief      Inicializa un iterator al comienzo pero constante
   *
   * @return     Iterator constante al comienzo del set de strings
   */

  const_iterator cbegin() const
  {
    const_iterator i;
    i.it = evento.second.cbegin();
  }
  /**
   * @brief      Inicializa un iterator al final pero constante
   *
   * @return     Iterator constante al final del set de strings
   */

  const_iterator cend() const
  {
    const_iterator i;
    i.it = evento.second.cend();
  }

};

#endif
