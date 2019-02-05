#include <iostream>
#include "bintree.h"
#include<queue>

using namespace std;

bool simetricos(const bintree<int> &a, const bintree<int> &b ){
    
    bintree<int> aux(a);
    bintree<int> aux2(b);
    bintree<int> izquierda;
    bintree<int> derecha;
    bintree<int> izquierda2;
    bintree<int> derecha2;

    bool son_iguales;
    if ( !aux.root().null() && !aux2.root().null())
    {
        if ( *(aux.root()) == *(aux2).root())
        {
            //son_iguales = true;
            aux.prune_left(a.root(), izquierda);
            aux2.prune_right(b.root(),derecha );
            son_iguales = simetricos(izquierda, derecha);
            
            if ( son_iguales)
            {
                aux.prune_right(a.root(), derecha2);
                aux2.prune_left(b.root(), izquierda2);
                son_iguales = simetricos(derecha2, izquierda2);
            }
        }
        else{
            son_iguales = false;
        }
    }
   if ( aux.root().null() && aux2.root().null()){
       son_iguales = true;
   }

    return son_iguales;
}

int main ( ){

  bintree<int> arbol(5), arbol2(5);

  arbol.insert_left(arbol.root(), 3);
  arbol.insert_right(arbol.root(), 8);
  arbol.insert_left(arbol.root().left(), 1);
  arbol.insert_right(arbol.root().left(), 4);
  arbol.insert_left(arbol.root().right(), 6);
  arbol.insert_right(arbol.root().right(), 9);
  arbol.insert_right(arbol.root().right().left(), 7);

  arbol2.insert_left(arbol2.root(), 8);
  arbol2.insert_right(arbol2.root(), 3);
  arbol2.insert_left(arbol2.root().left(), 9);
  arbol2.insert_right(arbol2.root().left(), 6);
  arbol2.insert_left(arbol2.root().right(), 4);
  arbol2.insert_right(arbol2.root().right(), 1);
  arbol2.insert_left(arbol2.root().left().right(), 7);

 bool simet = simetricos(arbol, arbol2);

    if ( simet){
        cout << " son " << endl;

    }
    else {
        cout << " no son" << endl;
    }
    return 0 ;
}