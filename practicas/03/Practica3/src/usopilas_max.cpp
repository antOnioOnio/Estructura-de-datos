 #include <iostream>
 #include "Pila_max.h"
 

 using namespace std;

 int main(){
	 Pila_max p;
	 int i;
 	for ( i=1; i<20 ; i++){

 		p.poner(i);
 		cout << p.tope();
 	}

 	p.poner(49);
 	cout<<p.tope();
 	p.poner(20);
 	cout<<p.tope();
 	p.poner(192);
 	cout<<p.tope();

 	while(!p.vacia()){
 		cout<<p.tope();
 		p.quitar();
 	}

	
 return 0;
 }
