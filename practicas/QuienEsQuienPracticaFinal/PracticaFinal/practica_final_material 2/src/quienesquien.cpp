#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
//--------------------------------------------------------------------------------------------------------------
QuienEsQuien::QuienEsQuien()
{
	//Contiene vector de string personajes
	//Contiene vector de string atributos
	//Matriz de booleanas de cada personaje y atributo.
	//Arbol de preguntas.
}
//--------------------------------------------------------------------------------------------------------------
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien)
{
	this->personajes = quienEsQuien.personajes;
	this->atributos = quienEsQuien.atributos;
	this->tablero = quienEsQuien.tablero;
	this->arbol = quienEsQuien.arbol;
}
//--------------------------------------------------------------------------------------------------------------
QuienEsQuien &QuienEsQuien::operator=(const QuienEsQuien &quienEsQuien)
{
	return *this;
}
//--------------------------------------------------------------------------------------------------------------
QuienEsQuien::~QuienEsQuien()
{
	this->limpiar();
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::limpiar()
{
	personajes.clear();
	tablero.clear();
	atributos.clear();
	arbol.clear();
}
//--------------------------------------------------------------------------------------------------------------
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v)
{
	if (!v.empty())
	{
		out << '[';
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::mostrar_estructuras_leidas()
{
	cout << "personajes: " << (this->personajes) << endl;
	cout << "atributos:  " << (this->atributos) << endl;
	cout << "tablero:    " << endl;

	// Escribe la cabecera del tablero
	for (vector<string>::iterator it_atributos = this->atributos.begin();
		 it_atributos != this->atributos.end();
		 it_atributos++)
	{
		cout << *it_atributos << "\t";
	}
	cout << endl;

	int indice_personaje = 0;
	for (vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		 it_tablero_atributos != tablero.end();
		 it_tablero_atributos++)
	{

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for (vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			 it_atributos_personaje != (*it_tablero_atributos).end();
			 it_atributos_personaje++)
		{

			cout << *it_atributos_personaje << "\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}
}
//--------------------------------------------------------------------------------------------------------------
/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original, string cadena_a_eliminar)
{
	string linea(cadena_original);

	while (linea.find_first_of(cadena_a_eliminar) != std::string::npos)
	{
		linea.erase(linea.find_first_of(cadena_a_eliminar), cadena_a_eliminar.length());
	}

	return linea;
}
//--------------------------------------------------------------------------------------------------------------
istream &operator>>(istream &is, QuienEsQuien &quienEsQuien)
{
	quienEsQuien.limpiar();

	if (is.good())
	{
		string linea;
		getline(is, linea, '\n');

		linea = limpiar_string(linea, "\r");

		while (linea.find('\t') != string::npos)
		{
			string atributo = linea.substr(0, linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
			linea = linea.erase(0, linea.find('\t') + 1);
		}

		assert(linea == "Nombre personaje");
	}

	while (is.good())
	{
		string linea;
		getline(is, linea, '\n');
		linea = limpiar_string(linea, "\r");

		//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
		if (linea != "")
		{
			;
			vector<bool> atributos_personaje;

			int indice_atributo = 0;
			while (linea.find('\t') != string::npos)
			{
				string valor = linea.substr(0, linea.find('\t'));

				assert(valor == "0" || valor == "1");

				bool valor_atributo = valor == "1";

				atributos_personaje.push_back(valor_atributo);

				linea = linea.erase(0, linea.find('\t') + 1);
				indice_atributo++;
			}

			string nombre_personaje = linea;

			quienEsQuien.personajes.push_back(nombre_personaje);
			quienEsQuien.tablero.push_back(atributos_personaje);
		}
	}

	return is;
}
//--------------------------------------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const QuienEsQuien &quienEsQuien)
{

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for (vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		 it_atributos != quienEsQuien.atributos.end();
		 it_atributos++)
	{

		os << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for (int indice_personaje = 0; indice_personaje < quienEsQuien.personajes.size(); indice_personaje++)
	{
		for (int indice_atributo = 0; indice_atributo < quienEsQuien.atributos.size(); indice_atributo++)
		{

			os << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}
//--------------------------------------------------------------------------------------------------------------
/**
  * @brief Convierte un n�mero a un vector de bool que corresponde 
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n 
  *      con el n�mero de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos)
{
	vector<bool> ret;
	while (n)
	{
		if (n & 1)
		{
			ret.push_back(true);
		}
		else
		{
			ret.push_back(false);
		}
		n >>= 1;
	}

	while (ret.size() < digitos)
	{
		ret.push_back(false);
	}

	reverse(ret.begin(), ret.end());
	return ret;
}
//--------------------------------------------------------------------------------------------------------------
bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	int num_pregunta = 0;
	// Guardaremos en un set las filas correspondientes a los jugadores
	set<int> personajes_;

	for (int i = 0; i < personajes.size(); i++)
	{
		personajes_.insert(i);
	}
	int numero_de_personajes = this->personajes.size();

	string atributo = this->atributos.at(num_pregunta);
	Pregunta pregunta_root(atributo, numero_de_personajes);
	// creamos la raiz
	bintree<Pregunta> arbolfinal(pregunta_root);
	// creamos nuestro nodo raiz
	bintree<Pregunta>::node raiz = arbolfinal.root();
	// llamamos a nuestra funcion crearSubarbol la cual se llamara recursivamente
	bintree<Pregunta> subArbol = crearSubarbol(raiz, num_pregunta, personajes_);
	// asignamos el arbol creado a partir de nuestra raiz
	arbolfinal.assign_subtree(subArbol, subArbol.root());

	return arbolfinal;
}
//--------------------------------------------------------------------------------------------------------------
bintree<Pregunta> QuienEsQuien::crearSubarbol(bintree<Pregunta>::node n, int num_pregunta, set<int> personajes_r)
{
	// creamos la pregunta a partir del nodo y nuestro arbol auxiliar correspondiente
	Pregunta p(*n);
	bintree<Pregunta> aux(p);

	// creamos nuestros sets correspondientes donde se guardaran las posiciones de
	// los jugadores restantes en cada caso
	set<int> personajes_restantes_si;
	set<int> personajes_restantes_no;

	// creamos los arboles que se iran rellenando a izquierda y derecha
	bintree<Pregunta> a_derecha;
	bintree<Pregunta> a_izquierda;

	// si solo queda 1 personaje significa que hemos llegado a nuestro personaje
	if (p.obtener_num_personajes() == 1)
	{
		// nuestro personaje estara en la unica fila restante que quedara en el set
		set<int>::iterator it = personajes_r.begin();
		string atributo = this->personajes[*it];

		Pregunta nodo(atributo, 1);

		bintree<Pregunta> personaje(nodo);

		return personaje;
	}
	// si quedan mas de un personaje, seguimos preguntando
	else if (p.obtener_num_personajes() > 1)
	{

		int personajes_si = 0,
			personajes_no = 0;

		for (set<int>::iterator it = personajes_r.begin(); it != personajes_r.end(); it++)
		{
			// preguntamos en cada caso, aumentamos e insertamos su posicion
			if (tablero[*it][num_pregunta] == 1)
			{
				personajes_si++;
				personajes_restantes_si
		.insert(*it);
			}
			else if (tablero[*it][num_pregunta] == 0)
			{
				personajes_no++;
				personajes_restantes_no.insert(*it);
			}
		}
		// pasamos a la siguiente pregunta
		num_pregunta++;
		if (num_pregunta < atributos.size())
		{
			string atributo = this->atributos.at(num_pregunta);

			// siempre y cuando haya algun personaje restante creamos los subarboles
			if (personajes_no > 0)
			{
				Pregunta derecha(atributo, personajes_no);
				aux.insert_right(aux.root(), derecha);
				bintree<Pregunta>::node nodo_r = aux.root().right();
				a_derecha = crearSubarbol(nodo_r, num_pregunta, personajes_restantes_no);
				aux.insert_right(aux.root(), a_derecha);
			}
			if (personajes_si > 0)
			{
				Pregunta izquierda(atributo, personajes_si);
				aux.insert_left(aux.root(), izquierda);
				bintree<Pregunta>::node nodo_l = aux.root().left();
				a_izquierda = crearSubarbol(nodo_l, num_pregunta, personajes_restantes_si
		);
				aux.insert_left(aux.root(), a_izquierda);
			}
		}
	}
	return aux;
}

//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo)
{
	arbol = arbol_nuevo;
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::iniciar_juego()
{
	bool no_descubierto = true;
	bool valido = true;
	char caracter;
	bintree<Pregunta>::node nodo_actual = arbol.root();
	bintree<Pregunta>::node siguiente;

	siguiente = nodo_actual;
	cout << " =================== COMIENZA EL JUEGO =========================" << endl;
	cout << "Introduzca S para si o N para no " << endl;

	while (no_descubierto)
	{

		if ((*siguiente).es_pregunta())
		{
			cout << " ¿ Es " << (*nodo_actual).obtener_pregunta() << " ? " << endl;

			do
			{
				cin >> caracter;
				if (caracter == 's' || caracter == 'S')
				{
					valido = true;
					siguiente = nodo_actual.left();
				}
				else if (caracter == 'n' || caracter == 'N')
				{
					valido = true;
					siguiente = nodo_actual.right();
				}
				else
				{
					valido = false;
					cout << "Creo que no te has enterado...Introduzca S para si o N para no " << endl;
				}

			} while (!valido);

			nodo_actual = siguiente;

		}
		else if ((*siguiente).es_personaje())
		{
			
			cout << "Me juego lo que quieras a que tu personaje es  " << (*siguiente).obtener_personaje() << endl;
			no_descubierto = false;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual)
{
	set<string> personajes_levantados;
	set<string> personajes_aux1;
	set<string> personajes_aux2;

	bintree<Pregunta>::node siguiente_derecha;
	bintree<Pregunta>::node siguiente_izquierda;
	string personaje;

	if (!jugada_actual.null())
	{
		if (!jugada_actual.left().null())
		{
			siguiente_izquierda = jugada_actual.left();

			if ((*siguiente_izquierda).es_personaje())
			{
				personaje = (*siguiente_izquierda).obtener_personaje();
				personajes_aux1.insert(personaje);
			}
			else
			{
				personajes_aux1 = informacion_jugada(siguiente_izquierda);
			}
		}
		if (!jugada_actual.right().null())
		{
			siguiente_derecha = jugada_actual.right();

			if ((*siguiente_derecha).es_personaje())
			{
				personaje = (*siguiente_derecha).obtener_personaje();
				personajes_aux2.insert(personaje);
			}
			else
			{
				personajes_aux2 = informacion_jugada(siguiente_derecha);
			}
		}
	}
	set<string>::iterator it1 = personajes_aux1.begin();
	set<string>::iterator it2 = personajes_aux2.begin();

	for (it1; it1 != personajes_aux1.end(); ++it1)
	{
		personajes_levantados.insert(*it1);
	}
	for (it2; it2 != personajes_aux2.end(); ++it2)
	{
		personajes_levantados.insert(*it2);
	}

	return personajes_levantados;
}
//--------------------------------------------------------------------------------------------------------------
void escribir_esquema_arbol(ostream &ss,
							const bintree<Pregunta> &a,
							bintree<Pregunta>::node n,
							string &pre)
{
	if (n.null())
	{
		ss << pre << "-- x" << endl;
	}
	else
	{
		ss << pre << "-- " << (*n) << endl;
		if (!n.right().null() || !n.left().null())
		{ // Si no es una hoja
			pre += "   |";
			escribir_esquema_arbol(ss, a, n.right(), pre);
			pre.replace(pre.size() - 4, 4, "    ");
			escribir_esquema_arbol(ss, a, n.left(), pre);
			pre.erase(pre.size() - 4, 4);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::escribir_arbol_completo() const
{
	string pre = "";
	escribir_esquema_arbol(cout, this->arbol, this->arbol.root(), pre);
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::eliminar_nodos_redundantes(bintree<Pregunta> &arbol, typename bintree<Pregunta>::node nodo)
{

	bintree<Pregunta> aux;

	if (!nodo.null())
	{
		if (nodo.left().null() && !nodo.right().null())
		{
			arbol.prune_right(nodo, aux);
			eliminar_nodos_redundantes(aux, aux.root());
			arbol.replace_subtree(nodo, aux, aux.root());
		}
		if (!nodo.left().null() && nodo.right().null())
		{
			arbol.prune_left(nodo, aux);
			eliminar_nodos_redundantes(aux, aux.root());
			arbol.replace_subtree(nodo, aux, aux.root());
		}
		eliminar_nodos_redundantes(arbol, nodo.left());
		eliminar_nodos_redundantes(arbol, nodo.right());
	}
}
//--------------------------------------------------------------------------------------------------------------
float QuienEsQuien::profundidad_promedio_hojas()
{
	float media;

	float divisor = personajes.size();

	int alturas = suma_alturas(arbol.root(), 0);

	media = (float)alturas / divisor;

	return media;
}
//--------------------------------------------------------------------------------------------------------------
int QuienEsQuien::suma_alturas(bintree<Pregunta>::node nodo, int altura)
{
	int izquierda, derecha;
	if (!nodo.null())
	{
		if (nodo.left().null() && nodo.right().null())
		{
			return altura;
		}
		else
		{
			altura++;
			izquierda = suma_alturas(nodo.left(), altura);
			derecha = suma_alturas(nodo.right(), altura);
			return izquierda + derecha;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max)
{
	int tam = max - min;
	return ((rand() % tam) + min);
}
//--------------------------------------------------------------------------------------------------------------
bintree<Pregunta> QuienEsQuien::getArbol()
{
	return arbol;
}
//--------------------------------------------------------------------------------------------------------------
void QuienEsQuien::tablero_aleatorio(int numero_de_personajes)
{
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes) / log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar " << numero_de_personajes << " personajes ";
	cout << "con " << numero_de_atributos << " atributos" << endl;
	cout << "Paso 1: generar " << pow(2, numero_de_atributos) << " personajes" << endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for (int indice_personaje = 0; indice_personaje < pow(2, numero_de_atributos); indice_personaje++)
	{
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje, numero_de_atributos);
		string nombre_personaje = "Personaje_" + to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for (int indice_atributo = 0; indice_atributo < numero_de_atributos; indice_atributo++)
	{
		string nombre_atributo = "Atr_" + to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar " << (pow(2, numero_de_atributos) - numero_de_personajes) << " personajes" << endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while (personajes.size() > numero_de_personajes)
	{
		int personaje_a_eliminar = generaEntero(0, personajes.size());

		personajes.erase(personajes.begin() + personaje_a_eliminar);
		tablero.erase(tablero.begin() + personaje_a_eliminar);
	}
}

void QuienEsQuien::elimina_personaje(string nombre, bintree<Pregunta>::node nodo){

	bintree<Pregunta> arbol_aux;
	if (!nodo.null())
	{
		if (!nodo.left().null())
		{
			if ((*(nodo).left()).es_personaje() && (*(nodo).left()).obtener_personaje() == nombre)
			{
				//Reemplazar el nodo.
				this->arbol.prune_left(nodo, arbol_aux);
			}
			else
			{
				elimina_personaje(nombre, nodo.left());
			}
		}

		if (!nodo.right().null())
		{
			if ((*(nodo).right()).es_personaje() &&  (*(nodo).right()).obtener_personaje() == nombre)
			{
				//Reemplazar el nodo
				this->arbol.prune_right(nodo, arbol_aux);
			}
			else
			{
				elimina_personaje(nombre, nodo.right());
			}
		}		
	}
}


void QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node nodo_actual)
{
	//Subir por el arbol hacia el padre y preguntar si soy hijo izq o derecha.
	bool fin = true;
	bintree<Pregunta>::node padre;

	while (fin)
	{
		if (!nodo_actual.null())
		{
			if (!nodo_actual.parent().null())
			{
				padre = nodo_actual.parent();

				if (padre.right() == nodo_actual)
				{
					cout << (*nodo_actual).obtener_pregunta() << " ---> no" << endl;
				}
				else
				{
					cout << (*nodo_actual).obtener_pregunta() << " ---> si" << endl;
				}
				if (nodo_actual.parent().parent().null())
				{
					if (nodo_actual.parent().right() == nodo_actual)
					{
						cout << (*(nodo_actual.parent())).obtener_pregunta() << " ---> no" << endl;
					}
					else
					{
						cout << (*(nodo_actual.parent())).obtener_pregunta() << " ---> si" << endl;
					}
					fin = false;
				}
			}
		}
		nodo_actual = nodo_actual.parent();
	}
}