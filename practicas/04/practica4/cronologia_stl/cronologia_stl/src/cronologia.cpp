#include <iostream>
#include "../include/cronologia.h"
#include "../include/eventoHistorico.h"

using namespace std;


//------------------------------------------------------------------------------------
//Añade objeto de Evento_Historico
  void Cronologia::aniadirEvento(const Evento_Historico& eh)
  {
    map<int,Evento_Historico>::iterator it;

    pair<int,Evento_Historico> ameter(eh.getAnio(),eh);

    it = datos.find(eh.getAnio());

    if ( it == datos.end()){
      
      datos.insert(ameter);
    }
    else{
      
      (*it).second = (*it).second + eh ;
    }  
  }

//------------------------------------------------------------------------------------
//Busca un evento en la Cronología 
  Cronologia Cronologia::buscarEventos(string s)
  {

     Cronologia nuevo;
     map<int, Evento_Historico>::iterator it;   
     for (it = datos.begin(); it!=datos.end(); ++it)
     {
      if((*it).second.buscarEventos(s)){
        Evento_Historico ameter = (*it).second ;
        nuevo.aniadirEvento(ameter);
      }
     }
     return nuevo;
  }
//------------------------------------------------------------------------------------
// Devuelve datos estadisticos de la cronologia
  estadisticasCronologia Cronologia::recuentoEventos(){

        estadisticasCronologia aux;
        map<int, Evento_Historico>::iterator it;

        aux.totalAnios = datos.size();

        int maximo = 0;
        double contador = 0.0;
        int n_eventos = 0;

        for (it = datos.begin(); it!=datos.end(); ++it){
          contador ++;
          n_eventos = (*it).second.size();
          aux.totalEventos += n_eventos;

          if (n_eventos > maximo){
            maximo = n_eventos;
          }
        }
        aux.maximo = maximo ;
        aux.promedio = aux.totalEventos / contador ;
      return aux;
  }
  //------------------------------------------------------------------------------------
  bool Cronologia::buscarAnio(int num)const {
    map<int, Evento_Historico>::const_iterator it = datos.find(num);
    bool esta = false;
    if ( it!= datos.end()){
      esta = true;
    }
    return esta;
  }



  //------------------------------------------------------------------------------------
  // Funcion eventos entre determinados años
  Cronologia Cronologia::eventosEntreAnios(int anio1, int anio2)
  {
    assert((anio2>anio1)&&(anio1 >0 && anio1 <9999) && (anio2 >0 && anio2 <9999));
    Cronologia nueva;
    Evento_Historico aux;
    bool esta = false;

    for (int a = anio1; a<=anio2 ; a++){
      esta = buscarAnio(a);
      if (esta){
        aux = getEventos(a);
        nueva.aniadirEvento(aux);
      }
    }
    return nueva;
  }
  //------------------------------------------------------------------------------------
  // funcion eventosanio
  
  Evento_Historico Cronologia::getEventos(int anio)
  {
    assert(anio >0 && anio <9999);
    map<int,Evento_Historico>::iterator it  = datos.find(anio);
    
    Evento_Historico nueva;

    if (it != datos.end()){
      nueva = it->second ;
    }
    
    return nueva;

  }
  //------------------------------------------------------------------------------------
  //Operador <<
  ostream& operator<< (ostream& os, const Cronologia& c)
  {
    map<int, Evento_Historico>::const_iterator it;
    
     for(it=c.datos.begin(); it!= c.datos.end(); ++it){
       
        os << it->second;
        os << endl;
      }
     return os;


  }
  //------------------------------------------------------------------------------------
  //Operador >>
  istream& operator>> (istream& is, Cronologia& c)
  {
     Evento_Historico b;
     while(is >> b){
        c.aniadirEvento(b);
        b = Evento_Historico();
     }
     return is;
  }
  //------------------------------------------------------------------------------------
  // Operator+
  Cronologia Cronologia::operator+( Cronologia &cro)
  {
    
    Cronologia::iterator it;
    Evento_Historico aux;
 
    for(it=cro.begin(); it!= cro.end(); ++it){
      
      
      aniadirEvento((*it).second);

    }

    return *this;
    
  }














