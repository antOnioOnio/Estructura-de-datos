#include <iostream>
#include "AVL.hpp"
using namespace std;

AVL<int> UnionDe(AVL<int> &a1, AVL<int> &a2){
  AVL<int> resultado(a1);

  AVL<int>::iterator it;
  
  for(it = a2.begin(); it!=a2.end(); ++it){

    if ( ! resultado.existe(*it) ){
      resultado.insertar(*it);
    }
  }
  return resultado;
}

AVL<int> interseccion(AVL<int> &a1, AVL<int> &a2){
  AVL<int> resultado;
  AVL<int>::iterator it;

   for(it = a1.begin(); it!=a1.end(); ++it){

    if (a2.existe(*it)){
      resultado.insertar(*it);
    }
  }
  return resultado;

}
  


int main(int argc, const char * argv[]) {
  AVL<int> avl, avl2, avl3;
  AVL<int>::iterator it;
  int e;
  
  cout << "INSERCIÓN DE DATOS" << endl;
  
  cout << "Introduce un entero para el primero (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl.insertar(e);
    for(it = avl.begin(); it!=avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();

    cout << "Introduce un entero para el primero (<0 para terminar) ";
    cin >> e;
  }


  cout << "Introduce un entero para el segudo (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl2.insertar(e);
    for(it = avl2.begin(); it!=avl2.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl2.Esquema();

    cout << "Introduce un entero para el segundo (<0 para terminar) ";
    cin >> e;
  }
  
  AVL<int> avl4(interseccion(avl,avl2));

  cout << " esquema del resultado" <<endl;
  avl4.Esquema();
//  const int N = 50;
//  const float max = 100.0;
//  srand(time(NULL));
//  for(int i=0; i<N; i++)
//    avl.insertar((int) (max*rand()/RAND_MAX));
//  
//  
//  for(it = avl.begin(); it!=avl.end(); ++it)
//    cout << *it << " ";
//  cout << endl;
//  
//  avl.Esquema();
  
  // cout << "BÚSQUEDA DE DATOS" << endl;
  // cout << "Introduce un entero (< 0 para terminar) ";
  // cin >> e;
  // while(e>=0){
  //   cout << e << (avl.existe(e)? " SÍ" : " NO") << " está en el AVL" << endl;
  //   cout << "Introduce un entero (< 0 para terminar) ";
  //   cin >> e;
  // }
  
  // avl.Esquema();
  // cout << "BORRADO DE DATOS" << endl;
  // cout << "Introduce un entero (< 0 para terminar) ";
  // cin >> e;
  // while(e>=0){
  //   avl.borrar(e);
  //   for(it = avl.begin(); it!=avl.end(); ++it)
  //     cout << *it << " ";
  //   cout << endl;
  //   avl.Esquema();
    
  //   cout << "Introduce un entero (< 0 para terminar) ";
  //   cin >> e;
  // }
  
  return 0;
}

