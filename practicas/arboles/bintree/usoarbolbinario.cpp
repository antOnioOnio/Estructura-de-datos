#include <iostream>
#include "bintree.h"
#include <queue>
#include <list>
using namespace std;

/**
//Ejercicio 2 Funcion que cuente hojas.
template <class T>
int ContarHojas( bintree<T>& a){
	int hojas;
	int  cont=0;
	for ( bintree<int>::preorder_iterator i = a.begin_preorder(); i!=a.end_preorder(); ++i){
		if(esHoja(a,*i))
			cont++;	
	}
	return cont;
	
}
*/
//Ejercicio 4 Hacer que funcione Esquema.
template <class T>
void Esquema(const bintree<T> &a,
             const typename bintree<T>::node n, string &pre)
{
  int i;

  if (n.null())
    cout << pre << "-- x" << endl;
  else
  {
    cout << pre << "-- " << *n << endl;
    if (n.right() != 0 || n.left() != 0)
    { // Si no es una hoja
      pre += "   |";
      Esquema(a, n.right(), pre);
      pre.replace(pre.size() - 4, 4, "    ");
      Esquema(a, n.left(), pre);
      pre.erase(pre.size() - 4, 4);
    }
  }
}
//Ejercicio 3 Hacer que funcione Altura.
template <class T>
int Altura(const bintree<T> &a,
           const typename bintree<T>::node n)
{
  int iz, de;
  if (n.null())
    return -1;
  else
  {
    iz = Altura(a, n.left());
    de = Altura(a, n.right());
    return 1 + (iz > de ? iz : de);
  }
}

template <class T>
bool esHoja(const bintree<T> &A, const typename bintree<T>::node &v)
{
  return (v.left().null() && v.right().null());
}

template <class T>
bool esInterno(const bintree<T> &A, const typename bintree<T>::node &v)
{
  return (!v.left().null() || !v.right().null());
}

template <class T>
void PreordenBinario(const bintree<T> &A,
                     typename bintree<T>::node v)
{
  if (!v.null())
  {
    cout << *v; // acción sobre el nodo v.
    PreordenBinario(A, v.left());
    PreordenBinario(A, v.right());
  }
}

template <class T>
void InordenBinario(const bintree<T> &A,
                    typename bintree<T>::node v)
{
  if (!v.null())
  {
    InordenBinario(A, v.left());
    cout << *v; //acción sobre el nodo v.
    InordenBinario(A, v.right());
  }
}

template <class T>
void PostordenBinario(const bintree<T> &A,
                      typename bintree<T>::node v)
{
  if (!v.null())
  {
    PostordenBinario(A, v.left());
    PostordenBinario(A, v.right());
    cout << *v; // acción sobre el nodo v.
  }
}

template <class T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n)
{
  queue<typename bintree<T>::node> nodos;
  if (!n.null())
  {
    nodos.push(n);
    while (!nodos.empty())
    {
      n = nodos.front();
      nodos.pop();
      cout << *n;
      if (!n.left().null())
        nodos.push(n.left());
      if (!n.right().null())
        nodos.push(n.right());
    }
  }
}

template <class T>
int contador_v2(typename bintree<T>::node nodo)
{
  if (nodo.null())
  {
    return 0;
  }
  else
  {
    return contador_v2(nodo.right()) + contador_v2(nodo.left()) + 1;
  }
}

template <class T>
ostream &operator<<(ostream &os, bintree<T> &arb)
{

  cout << "Preorden:";

  for (typename bintree<T>::preorder_iterator i = arb.begin_preorder(); i != arb.end_preorder(); ++i)
    cout << *i << " ";

  cout << endl;
}
void caminos(bintree<int>::node n, int k, list<list<int> > final, list<int> camino)
{

  list<int> der;
  list<int> izq;
  list<int>::iterator it;
  bool esta = false;

  if (n.right().null() && n.left().null())
  {
    cout << " llegue a hoja y voy a meter" << *n << endl;
    camino.push_back(*n);
    it = camino.begin();

    for (it; it != camino.end() && !esta; ++it)
    {
      if (*it == k)
      {
        final.push_back(camino);
        esta = true;
      }
    }
    if (esta)
    {
      for (it = camino.begin(); it != camino.end(); ++it)
      {
        cout << *it << "\t";
      }
      cout << endl;
    }
  }
  else
  {
    cout << " entre y voy a meter " << *n << endl;
    camino.push_back(*n);

    if (!n.right().null())
    {
      der = camino;
      //der.push_back(*(n.right()));
      caminos(n.right(), k, final, der);
    }
    if (!n.left().null())
    {
      izq = camino;
      //izq.push_back(*(n.left()));
      caminos(n.left(), k, final, izq);
    }
  }
}
queue<int> multiInterseccion(queue<int> q1, queue<int> q2)
{
  int numero;
  queue<int> devolver;

  while (!q1.empty() && !q2.empty())
  {
    if (q1.front() < q2.front())
    {
      q2.pop();
    }
    if (q1.front() > q2.front())
    {

      q1.pop();
    }
    else if (q1.front() == q2.front())
    {

      numero = q1.front();
      devolver.push(numero);
      q1.pop();
      q2.pop();
    }
  }
  return devolver;
}
list<int> repetidos(list<int> entrada)
{
  list<int> devolver;
  list<int> aux = entrada;
  list<int>::iterator it;
  list<int>::iterator it_2;
  bool esta = false;
  int numero;
  while (!aux.empty())
  {
    esta = false;
    it = aux.begin();
    it_2 = it;
    numero = *it;
    it_2++;
    if (it_2 != aux.end())
    {
      for (it_2; it_2 != aux.end(); it_2++)
      {
        if (*it_2 == numero)
        {
          esta = true;
          aux.erase(it_2);
        }
      }

      if (esta)
      {
        devolver.push_back(numero);
      }
      aux.erase(it);
    }
  }
  return devolver;
}

int main()
{
  list<int> listica;
  list<int> res;

  listica.push_back(5);
  listica.push_back(2);
  listica.push_back(7);
  listica.push_back(2);
  listica.push_back(5);
  listica.push_back(5);
  listica.push_back(1);

  res = repetidos(listica);
  list<int>::iterator it = res.begin();
  for (it; it != res.end(); ++it)
  {
    cout << *it << " \t";
  }
  // queue<int>q1 ;
  // queue<int>q2;
  // queue<int>q_r;

  // q1.push(3);
  // q1.push(3);
  // q1.push(2);
  // q1.push(2);

  // q2.push(4);
  // q2.push(3);
  // q2.push(3);
  // q2.push(3);
  // q2.push(2);
  // q2.push(1);
  // cout << " aqui" << endl;
  // q_r = multiInterseccion ( q1, q2);

  // while ( !q_r.empty()){
  //   cout << q_r.front() << endl;
  //   q_r.pop();
  // }

  // Creamos el árbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4
  // Ejercicio 1 Crear otro arbol para leer.
  //Creamos el árbol:
  //        3
  //      /  \
  //     6    8
  //     \   / \
  //     8  5   4
  //    /   \
  //   2    4
  // typedef bintree<int> bti;
  // bintree<int> Arb(3);
  // Arb.insert_left(Arb.root(), 6);
  // Arb.insert_right(Arb.root(), 8);
  // Arb.insert_right(Arb.root().left(), 8);
  // Arb.insert_left(Arb.root().left().right(), 2);
  // Arb.insert_left(Arb.root().right(), 5);
  // Arb.insert_right(Arb.root().right(), 4);
  // Arb.insert_right(Arb.root().right().left(), 4);

  // list<list<int> > resu;
  // list<int> c;
  // caminos(Arb.root(), 8, resu, c);
  // list<list<int> >::iterator it;
  // list<int>::iterator i;
  // cout << " alla va " << endl;
  // for (it = resu.begin(); it != resu.end(); ++it)
  // {
  //   for (i = (*it).begin(); i != (*it).end(); ++i)
  //   {
  //     cout << *i << " \t";
  //   }
  //   cout << endl;
  // }
  // cout << "Altura: "<<Altura(Arb,Arb.root())<< endl;

  // string pre= " ";
  // Esquema(Arb,Arb.root(),pre);

  // cout << "Preorden:";

  // for (bintree<int>::preorder_iterator i = Arb.begin_preorder(); i!=Arb.end_preorder(); ++i)
  //   cout << *i << " ";

  // cout << endl;

  // cout << "Inorden:";

  // for (bintree<int>::inorder_iterator i = Arb.begin_inorder(); i!=Arb.end_inorder(); ++i)
  //   cout << *i << " ";

  // cout << endl;

  // cout << "Postorden:";

  // for (bintree<int>::postorder_iterator i = Arb.begin_postorder(); i!=Arb.end_postorder(); ++i)
  //   cout << *i << " ";

  // cout << endl;

  // cout << "Por Niveles:";

  // for (bintree<int>::level_iterator i = Arb.begin_level(); i!=Arb.end_level(); ++i)
  //   cout << *i << " ";

  // cout << endl;
  // cout << "E aqui el numero de nodos debajo de raiz" << contador_v2(Arb.root());
  // //cout << Arb;

  // //cout << "El numero de hojas son: "<< ContarHojas(Arb) << endl;
}
