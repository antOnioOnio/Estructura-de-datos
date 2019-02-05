#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

void multiplicacionMatrices(int *m1, int *m2, int *m3, int tam)
{
  for(int i=0; i<tam; ++i)
          for(int j=0; j<tam; ++j)
              for(int z=0; z<tam; ++z)
                  m3[i+j] += m1[i+z] * m2[z+j];
}
void imprimeMatriz(int *m, int tam){

  for(int i=0; i<tam; ++i)
  {
      for(int j=0; j<tam; ++j)
      {
          cout<<m[i+j]<<" ";
      }
      cout<<endl;
  }
}
void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();


  // Generación de matrices
  int *m1=new int[tam*tam];     //reserva de memoria
  int *m2=new int[tam*tam];    // Reserva de memoria
  int *m3=new int[tam*tam];
  srand(time(0));    // Inicialización del generador de números pseudoaleatorios

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++) {
          m1[i+j] = rand()%tam;
          m2[i+j] = rand()%tam;
          m3[i+j] = 0;
      }
  }

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();


  multiplicacionMatrices(m1,m1,m3,tam); // de esta forma forzamos que recorra siempre el vector completo
  
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  delete [] m1;
  delete [] m2;
  delete [] m3;    // Liberamos memoria dinámica
}
