#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;
// algoritmo burbuja

void ordenar(int *v, int n) 
{
	bool cambio=true;
	for (int i=0; i<n-1 && cambio; i++) 
	{
		cambio=false;
		for (int j=0; j<n-i-1; j++)
		{
			if (v[j]>v[j+1]) 
			{
			cambio=true;
			int aux = v[j];
			v[j] = v[j+1];
			v[j+1] = aux;
			}
		}
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
  int vmax=atoi(argv[1]);     // Tamaño del vector
  if (vmax<=0)
    sintaxis();
  

  // Generación del vector aleatorio
  int *v=new int[vmax];       // Reserva de memoria

  
  for (int i=0; i<vmax; i++)  // Recorrer vector
    v[i] = i ;    // Rellenamos el vector ordenadamente
  
  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  

  ordenar(v,vmax); // de esta forma forzamos que recorra siempre el vector completo
  
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << vmax << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}


