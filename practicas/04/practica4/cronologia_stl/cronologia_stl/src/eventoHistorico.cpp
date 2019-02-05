#include <iostream>
#include "../include/eventoHistorico.h"

using namespace std;

  
//------------------------------------------------------------------------------------
//Constructor vacío
  Evento_Historico::Evento_Historico(){
  
  }
//------------------------------------------------------------------------------------  
//Constructor con parametros 
  Evento_Historico::Evento_Historico(int a, set<string> eventos){
   evento.first = a;
   evento.second = eventos;
   
  }
//------------------------------------------------------------------------------------
//Constructor de copias
   Evento_Historico::Evento_Historico(const Evento_Historico& e){
     
     evento.first = e.evento.first;
     evento.second = e.evento.second;
     
   }

   Evento_Historico::~Evento_Historico(){
      evento.first = 0;
      evento.second.clear();
    }

//------------------------------------------------------------------------------------
//Método de acceso a año
   int Evento_Historico::getAnio()const {
    return evento.first;
   }

//------------------------------------------------------------------------------------
//Añade un evento
  void Evento_Historico::aniadirevento(string& event){
    evento.second.insert(event);

  }

//------------------------------------------------------------------------------------
//Buscador de eventos
  bool Evento_Historico::buscarEventos(string s){
    bool is_in = false;
    Evento_Historico::iterator it ;

    for ( it = begin() ; it != end(); ++it){
      
      if ( (*it).find(s) != string::npos){
        is_in = true;
      }
    }
  
    return is_in;
   }
//------------------------------------------------------------------------------------
//Operador <<

  ostream& operator<< (ostream& os,  const Evento_Historico& e)
  {
    set<string>::iterator it;
    os << e.evento.first << flush ;
    
    for (it=e.evento.second.begin(); it!=e.evento.second.end(); ++it){
      os<< "#" << *it ;
    }
    
    return os;

}
//------------------------------------------------------------------------------------
//Operador >>
istream &operator>>(istream& is, Evento_Historico &f) {
   
    int anio = -1;
    char a;
    string evento ;
    
    is >> anio;
    if ( anio >= 0 && anio < 9999){
      f.evento.first = anio;
    }
    is.get(a);
    is.get(a);
    while ( ( a != '\n') && !is.eof()){
     
      if ( a == '#'){
        f.evento.second.insert(evento);
        evento.clear();

      }
      else if (a != '\r') {
        evento += a;
      }
       is.get(a);
    }
    f.evento.second.insert(evento);
    return is;

}

//------------------------------------------------------------------------------------
Evento_Historico& Evento_Historico::operator=(const Evento_Historico& fec){

  if( this!= & fec){
    evento.first = fec.evento.first;
    evento.second = fec.evento.second;
  }

  return *this;

}

//------------------------------------------------------------------------------------


 Evento_Historico Evento_Historico::operator+( const Evento_Historico& e){

   Evento_Historico aux(*this);
   set<string>::const_iterator it;

      if(aux.evento.first == e.evento.first){
        for(it=e.evento.second.begin(); it!=e.evento.second.end(); ++it){
          if (!buscarEventos(*it)){
          aux.evento.second.insert(*it);
          }
        }
      }
    return aux;
}













