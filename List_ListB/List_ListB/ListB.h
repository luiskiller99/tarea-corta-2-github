#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
template <class T, int N = 20>
class ListB{
private:
	struct Nodo {
		bool lleno;
		T elemento[N]; // Cada nodo almacena N elementos
		struct Nodo * siguiente;
		// Constructores
		Nodo() :lleno{ false }, siguiente{ 0 } {}
		Nodo(struct Nodo * sig) :lleno{ false },
			siguiente{ sig } {}
	};
	typedef struct Nodo * link;
	link primero; // Puntero al primer nodo de la lista
	int tam; // Cantidad de elementos de la lista
	string nombreLista; // Nombre de la lista
	// Métodos privados
	// Acá se incluyen los métodos privados que se requieran.

public:
	ListB(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~ListB();
};
//luis terminado
template<class T, int N>
ListB<T,N>::ListB(string nombre) {
	nombreLista = nombre;
	primero = new Nodo();
	tam = 0;
}
//luis terminado
template<class T, int N>
int ListB<T,N>::len() { return tam; }
//marco 
template<class T, int N>
void ListB<T, N>::push_front(T x) {}
//luis terminada
template<class T, int N>
void ListB<T, N>::push_back(T x) {	
	link p = primero;
	while (p) {
		//si esta lleno crea uno nuevo
		if (p->lleno) { 
			if (p->siguiente)
				p = p->siguiente;
			else {
				p->siguiente = new Nodo();
			}
		}
		//si aun no esta lleno
		else {
			p->elemento[(tam % N) ] = x;
			tam++;
			if ((tam%N) == 0) p->lleno = true; //verifica si con esa insercion se llena
			break;
		}
	}		
}
//marco
template<class T, int N>
void ListB<T, N>::insertar(T x, int pos) {}
//luis por terminar
template<class T, int N>
bool ListB<T, N>::remove(int pos, T &x) {
	//optener nodo y posicion en la que se encuentra
	int poss = pos, nums_restantes = 0,cont_nodos=0;
	while (poss - N >= 0){
		poss -= N;	
		cont_nodos++;
	}
	nums_restantes = poss;
	//realiza la modificacion y corrimiento de todos los numeros
	link p = primero;
	for (int i = 0; i <= (tam/N); i++) {//contando los nodos
		if (i == cont_nodos) {//si lo encuentra
			x = p->elemento[nums_restantes];	//guarda nodo		
			tam--;
			if (tam == 0) {
				delete primero;
				primero = NULL;
				return true;
			}
			//mover todos los que siguen hacia adelante
			//si tiene siguiente				
			while (p->siguiente) {				
				for (int j = nums_restantes ; (j+1) < N ; j++) //de esta posicion en adelante modificar todos los numeros
					p->elemento[j] = p->elemento[j + 1];
				p->elemento[N-1] = p->siguiente->elemento[0];																																			
				p = p->siguiente;
				nums_restantes = 0;
				//eliminar nodo potencialmente vacio
				if (((tam%N) == 1) ) {
					delete p->siguiente;
					p->siguiente = NULL;										
				}				
			}									
			//si es el ultimo nodo	
			if (p) {
				for (int j = 0; (j + 1) < N; j++)
					p->elemento[j] = p->elemento[j + 1];
			}
			//si nodo pierde elementos, lleno pasa a false
			if ((tam%N) != 0) {				
				p->lleno = false;
			}
			std::cout << "\nTAMAÑO: " << tam<<"\n";
			return true;
			//eliminar ultimo nodo si esta vasido....
		}
		p = p->siguiente;
	}
	return false;
}
//marco
template<class T, int N>
bool ListB<T, N>::pop(T &x) {}
//luis por terminar
template<class T, int N>
bool ListB<T, N>::pop_back(T &x) {}
//marco
template<class T, int N>
bool ListB<T, N>::get(int pos, T &element) {}
//luis por terminar
template<class T, int N>
bool ListB<T, N>::get_front(T &element) {}
//marco
template<class T, int N>
bool ListB<T, N>::get_back(T &element) {}
//luis terminado
template<class T, int N>
void ListB<T, N>::print() {
	link p = primero;		
	std::cout << "[\n";
	while (p) {
		for (int i = 0; i < N; i++) {
			if(p->siguiente)
				std::cout << p->elemento[i] << ", ";
			else {
				if (i < (tam%N) || p->lleno)
					std::cout << p->elemento[i] << ", ";
				else
					break;
			}
		}
		std::cout << "\n";
		p = p->siguiente;
	}
	std::cout << "]";
}
//marco
template<class T, int N>
ListB<T, N>::~ListB() {}