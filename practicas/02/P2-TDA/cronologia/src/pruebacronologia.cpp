#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;
// 
// 
// Programa de prueba de los TDA Cronologia y Fecha_Historica
// 
// Antonio Garcia Castillo
// 
// 
// 
int main(int argc, char * argv[]){

   if (argc!=2){  // cambiar dependiendo si le entra una o dos cronologias
       cout<<"Dime el nombre del fichero con la cronologia"<<endl;
       return 0;
    }

    ifstream f (argv[1]);
    if (!f){
     cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
    }
    //ifstream s(argv[2]);

    // --------------------------------------------------------------
    //               Prueba 1, suma de dos cronologias
    // --------------------------------------------------------------             
    //    para ello deberiamos cambiar los argumentos que le entran
    // 
        Cronologia mi_cronologia, su_cronologia;    


        f >> mi_cronologia;        //Cargamos en memoria
    //    s >> su_cronologia;        //Cargamos en memoria   
    //    mi_cronologia + su_cronologia;
    //     cout << mi_cronologia <<endl;
    // --------------------------------------------------------------
    //               Prueba 2, eventos entre años
    // --------------------------------------------------------------          
    // 
    //Cronologia mi_cronologia;     
    //mi_cronologia = mi_cronologia.eventosEntreAnios(2001,2010);
    //cout << mi_cronologia <<endl;
    //
    // --------------------------------------------------------------
    //              Prueba 3, Busqueda de un string
    // --------------------------------------------------------------         
    //     
    // string peli = "Mulholland Drive";
    // mi_cronologia = mi_cronologia.buscarEventos(peli);
    // cout << mi_cronologia <<endl;
    // 
    // 
    
    // --------------------------------------------------------------
    //              Prueba 4, Eventos en un año especifico
    // --------------------------------------------------------------
     //Fecha_Historica fecha ;
     //fecha = mi_cronologia.eventosAnio(1927);
     cout << mi_cronologia <<endl;
     //cout << "Cronología leida del archivo: " << endl << mi_cronologia << endl;
   

    
    

  

}
