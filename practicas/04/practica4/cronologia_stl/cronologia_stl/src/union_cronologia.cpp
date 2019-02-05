#include "../include/cronologia.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char * argv[]){

  if (argc!=3 && argc!=4){
      cout<<"Error: debe dar al menos los nombres de dos ficheros con cronologías. "<<endl;
      cout<<"[Opcional]: un tercer nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }

   Cronologia c1, c2, cUnion ;
   
   f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.
   cout << "--------------------------------------------------"<<endl;
   cout << "              IMPRIMIMOS PRIMERA CRONOLOGIA" <<endl;
   cout << "--------------------------------------------------\n\n"<<endl;
   cout << c1;

  
   f2 >> c2; 
   cout << "--------------------------------------------------"<<endl;
   cout << "              IMPRIMIMOS SEGUNDA CRONOLOGIA" <<endl;
   cout << "--------------------------------------------------\n\n"<<endl;
   cout << c2;
  
   cUnion = c1 + c2 ;
   cout << "--------------------------------------------------"<<endl;
   cout << "              IMPRIMIMOS UNION" <<endl;
   cout << "--------------------------------------------------\n\n"<<endl;
   cout << cUnion;

   cout <<"\n\n";

   int anio;
   cout << " dime un año a consultar: \t" ;
   cin >> anio;


   Evento_Historico eventos;
   int anio1 , anio2 ;
   eventos = cUnion.getEventos(anio);  //Asumimos que Cronologia::GetEventos() devuelve objeto de clase EventoHistorico
   cout << "--------------------------------------------------"<<endl;
   cout << " EN EL ANIO: "<< anio << " PASARON LOS SIGUIENTES EVENTOS: " << endl;
   cout << "--------------------------------------------------"<<endl;
   cout<< eventos << endl;
   cout << "\n\n" ;
   cout << " Introduce los anios de los cuales quieres saber el intervalo: " <<endl;
   cout<< " Primer anio: \t" ;
   cin >> anio1 ;
   cout << " Segundo anio: \t";
   cin >> anio2;
   Cronologia anios;
   cout << "--------------------------------------------------"<<endl;
   cout << "              Entre "<<anio1<< " y " <<anio2 <<    endl;
   cout << "--------------------------------------------------\n\n"<<endl;
   anios = cUnion.eventosEntreAnios(anio1, anio2);

   cout << anios << endl;




   estadisticasCronologia estadisticas;

   estadisticas = anios.recuentoEventos();
   cout << "--------------------------------------------------"<<endl;
   cout << "         Estadisticas entre "<<anio1<< " y " <<anio2 <<    endl;
   cout << "--------------------------------------------------\n\n"<<endl;
   cout << "Total anios                    -->" << estadisticas.totalAnios << endl;
   cout << "Total eventos                  -->" << estadisticas.totalEventos << endl;
   cout << "Maximo de eventos en un anio   -->" << estadisticas.maximo << endl;
   cout << "Promedio de eventos por anio   -->" << estadisticas.promedio << endl;
   
   string aleer;
   
   cout << endl; 

   cout << " Introduce una palabra clave: \t" ;
   cin >> aleer ;
    
   Cronologia conPalabra;
   conPalabra = anios.buscarEventos(aleer);
   cout << "--------------------------------------------------"<<endl;
   cout << "      IMPRIMIMOS EVENTOS CON: ' " << aleer << " ' "    <<endl;
   cout << "--------------------------------------------------\n\n"<<endl;

   cout << conPalabra;
   cout <<endl;



}