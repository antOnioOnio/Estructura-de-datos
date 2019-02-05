#include <iostream>
#include "Fecha_Historica.h"

using namespace std;
//------------------------------------------------------------------------------------
//Resize simple
  void Fecha_Historica::resize(int r){
     string *aux = new string[r];
     for(int i=0; i<numeventos; ++i){
        aux[i]=str[i];
     }
     delete[] str;
     str = aux;
     reservados = r;
  }
//------------------------------------------------------------------------------------
//Constructor vacío
  Fecha_Historica::Fecha_Historica(){
    anio = 0;
    reservados = 0;
    numeventos = 0;
    str = 0;
  }
//------------------------------------------------------------------------------------  
//Constructor con parametros año, cadena de eventos y número de eventos a añadir
  Fecha_Historica::Fecha_Historica(int a, string *s, int n){
     assert(a >= 0 && a<= 9999);
     reservados = n;
     numeventos = n;
     anio = a;
     str = new string[n];
     for (int i=0; i<n; i++)
        str[i]=s[i];
  }
//------------------------------------------------------------------------------------
//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica& e){
      str = new string[e.reservados];
      anio=e.anio;
      numeventos = e.numeventos;
      reservados = e.numeventos;
      for(int i=0; i<numeventos; ++i)
         str[i] = e.str[i];
   }

//------------------------------------------------------------------------------------
//Método de acceso a año
   int Fecha_Historica::getAnio(){
    return anio;
   }

//------------------------------------------------------------------------------------
//Añade un evento
  void Fecha_Historica::aniadirevento(string& event){
     if (numeventos == reservados){
        if (numeventos==0)
           resize(1);
        else
        resize(2*reservados);
     }
     str[numeventos]=event;
     numeventos++;
  }

//------------------------------------------------------------------------------------
//Buscador de eventos
  bool Fecha_Historica::buscarEventos(string s, Fecha_Historica &matches){
     bool encontrado=false;
     for (int i=0; i < numeventos; ++i){
        if(str[i].find(s) != -1 ){
           matches.aniadirevento(str[i]);
           encontrado = true;
        }
     }
     if (encontrado){
        matches.anio=anio;
      }
    return encontrado;
   }
//------------------------------------------------------------------------------------
//Operador <<

  ostream& operator<< (ostream& os,  const Fecha_Historica& e){
    os << e.anio ;

    for(int i=0; i < e.numeventos ; ++i){
        os << "#";
        os << e.str[i];
    }
    os << endl;
    return os;

}
//------------------------------------------------------------------------------------
//Operador >>
istream &operator>>(istream& is, Fecha_Historica &f) {
   
    int anio = -1;
    char a ;
    string evento ;

    is >> anio;
    if ( anio >= 0 && anio < 9999){
      f.anio = anio;
    }
     is.get(a);
    while ( ( a != '\n') && !is.eof()){
      is.get(a);
      if ( a =='#'){
        f.aniadirevento(evento);
        evento="";

      }
      else {
        evento += a;
      }
      
    }
    f.aniadirevento(evento);
    return is;
}

//------------------------------------------------------------------------------------
Fecha_Historica& Fecha_Historica::operator=(const Fecha_Historica& fec){

  if( this!= & fec){
    delete [] str ;
    this->numeventos = fec.numeventos;
    this->reservados = fec.reservados;
    this->anio = fec.anio;
      if (this->numeventos > 0){
        str = new string[reservados];

        for (int i = 0; i< numeventos ; i++){
          this->str[i]=fec.str[i];
        }
      }
      else str = 0;
  }
  return *this;

}




















