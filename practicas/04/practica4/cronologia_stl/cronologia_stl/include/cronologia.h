/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  * @
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include <iostream>
#include <string>
#include "eventoHistorico.h"
#include <map>

using namespace std;



struct estadisticasCronologia{
    int totalAnios;
    int totalEventos;
    int maximo ;
    double promedio ;
};
/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * con un campo, Un map<int, Evento_Historico> donde el int representara
  * el anio y el Evento_Historico seran los eventos asociados a ese anio.
  *  Lo representamos como
  *
  * Año_1 a.C/d.C N_eventos evento/s:
  * *)Evento_Historico_1
  * ...
  * *)Evento_Historico_N 
  * .
  * .
  * .
  * Año_N a.C/d.C N_eventos evento/s:
  * *)Evento_Historico_1
  * ...
  * *)Evento_Historico_M 
  *
  * Un ejemplo de su uso:
  * @include union_cronologia.cpp
  *
  * @author Antonio Garcia Castillo
  * @author 
  * @date   27/10/2017
  */

class Cronologia {
    /**
      * @page repConjunto Rep del TDA Cronologia
      *
      * @section invConjunto Invariante de la representación
      *
      * El invariante está ligado al de los Eventos_Historicos \e rep.anio < 0 && rep.anio > 9999
      * que ya hemos fijado anteriormente
      *
      * @section faConjunto Función de abstracción
      *
      * Un objeto válido @e rep del TDA Cronologia representa al valor
      *
      * Año_1 a.C/d.C N_eventos evento/s:
      * *)Evento_Historico_1
      * ...
      * *)Evento_Historico_N 
      * .
      * .
      * .
      * Año_N a.C/d.C N_eventos evento/s:
      * *)Evento_Historico_1
      * ...
      * *)Evento_Historico_M 
      *
      */
  private:
    map<int, Evento_Historico> datos;
 public:

/**
  * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar 
  * errores o asignaciones de basura a objetos de nuestra clase.
  */

  Cronologia(){};

/**
  * @brief Añade un Evento Histórico  en la Cronología
  * @param eh el nuevo Evento Historico
  * @return no devuelve nada
  */

  void aniadirEvento(const Evento_Historico& eh);

/**
 * @brief      Funcion para las estadisticas de la cronologia
 *
 * @return     Un objeto struct estadisticasCronologia que contiente
 *             el promedio, maximo, numero de eventos y numero de anios
 */

  estadisticasCronologia recuentoEventos();

/**
  * @brief Busca un Evento Histórico dado su fecha
  * @param f la fecha del evento a buscar
  * @pre la fecha debe ser válida
  * @return Devuelve la posición del evento
  */

  bool buscarAnio(int f)const ;


  /**
  * @brief buscador de eventos dado una palabra clave
  * @param s vector de string con la palabra a buscar
  * @return Devuelve una Cronología
  */

  Cronologia buscarEventos(string s);

  
 /**
  * @brief      suma de dos cronologias que se almacena en nuestra cronologia
  *
  * @param[in]  cro   cronologia que se sumara a nuestra cronologia
  *             
  */
  Cronologia operator+( Cronologia& cro);

  /**
   * @brief      Encuentra las fechas historicas entre dos fechas
   *
   * @param[in]  anio1  Primer año
   * @param[in]  anio2  Segundo año
   *
   * @return      Devuelve una cronologia con las fechas historicas que haya entre ambas
   */

  Cronologia eventosEntreAnios(int anio1, int anio2);

 /**
  * @brief Busca los eventos acaecidos en un anio especifico
  * @param[in] int anio especifico
  * @return Devuelve una Evento_Historico
  */

  Evento_Historico getEventos(int anio);


/**
  * @brief Salida de una Cronologia a ostream
  * @param os stream de salida
  * @param c Cronologia a escribir
  * @post Se obtienen varios años seguidos de la cadena de Eventos_Historico con el formato
  * de Evento_Historico
  */

  friend ostream& operator<< (ostream& os, const Cronologia& c);

/**
  * @brief Entrada de una Cronologia desde istream
  * @param is stream de entrada
  * @param c Cronologia que recibe el valor
  * @retval La Cronologia leída en c
  * @pre La entrada tiene el formato de Evento_Historico neventos numero de veces
  */

  friend istream& operator>> (istream& is, Cronologia& c);



   /**
     * @brief clase para iterar sobre la cronologia
     * */
    class iterator{
     private:
      map<int,Evento_Historico>::iterator it;
     public:
       iterator & operator++(){
          ++it;
       }
       iterator & operator--(){
         --it;
       }
       pair<const int,Evento_Historico> &operator*(){
         return *it;
       }
       bool operator ==(const iterator &i){
         return i.it==it;
       }    
       
       bool operator !=(const iterator &i){
        return i.it!=it;
       }
       friend class Cronologia;
    };
    
    class const_iterator{
     private:
      map<int,Evento_Historico>::const_iterator it;
     public:
       const_iterator & operator++(){
          ++it;
       }
       const_iterator & operator--(){
         --it;
       }
       const pair<const int,Evento_Historico> &operator*(){
         return *it;
       }
       bool operator ==(const const_iterator &i){
         return i.it==it;
       }    
       
       bool operator !=(const const_iterator &i){
        return it != i.it;
       }

       const_iterator & operator=(const const_iterator &i){
        this->it = i.it;

        return *this;
       }

       friend class Cronologia;
    };
     /**
       * @brief Inicializa un iterator al comienzo de la guia
       * */
      iterator begin(){
        iterator i;
        i.it=datos.begin();
        return i;
      } 
      /**
       * @brief Inicializa un iterator al final de la guia
       * */
      iterator end(){
        iterator i;
        i.it=datos.end();
        return i;
      }

      const_iterator cend() const{
        const_iterator i;
        i.it = datos.cend();
      }

      const_iterator cbegin() const{
        const_iterator i;
        i.it = datos.cbegin();
      }


};  

#endif
