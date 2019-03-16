#pragma once
#include <iostream>
#include <string>
#include<cstdlib>
#include <queue>
using std::string;
using std::cout;
using std::queue;
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
	//int tam; // Cantidad de elementos de la lista
	string nombreLista; // Nombre de la lista
	// Métodos privados
	// Acá se incluyen los métodos privados que se requieran.
	void insertarNuevamente(queue<T>q);
public:
	int tam; // Cantidad de elementos de la lista
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
//Marco Extra Cola
template<class T, int N>
void ListB<T, N>::insertarNuevamente(queue<T>q) {
	while (!q.empty()) {
		this->push_back(q.front());
		q.pop();
	}
}
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
//marco listo
template<class T, int N>
inline void ListB<T, N>::push_front(T x) {
	std::queue<T> ColaElementos;
	ColaElementos.push(x);
	for (int i = 1; i <= tam; i++) {
		T a;
		this->get(i, a);
		ColaElementos.push(a);
	}
	tam = 0;
	this->~ListB();
	primero = NULL;
	insertarNuevamente(ColaElementos);
}

//luis terminada
template<class T, int N>
void ListB<T, N>::push_back(T x) {	
	
	if(primero){
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
				p->elemento[(tam++ % N) ] = x;												
				if ((tam%N) == 0) p->lleno = true; //verifica si con esa insercion se llena				
				break;
			}
		}
	}
	else {		
		primero = new Nodo();
		primero->elemento[0] = x;
		tam++;
	}
}
//marco listo
template<class T, int N>
void ListB<T, N>::insertar(T x, int pos) {
	std::queue<T> ColaElementos;
	for (int i = 0; i < pos; i++) {
		T a;
		this->get(i, a);
		ColaElementos.push(a);
	}
	ColaElementos.push(x);
	for (int j = pos + 1; j < tam; j++) {
		T a;
		this->get(j, a);
		ColaElementos.push(a);
	}
	tam = 0;
	this->~ListB();
	primero = NULL;
	insertarNuevamente(ColaElementos);
}
//luis terminada
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
	if (!p || tam == 0) { 
		delete primero;
		primero = NULL;
		return false; 
	}
	else if ((tam == 1) && p) {
		tam--;
		x = p->elemento[0];
		delete primero;
		primero = NULL;
		return true;
	}
	for (int i = 0; i <= (tam/N); i++) {//contando los nodos
		if (i == cont_nodos) {//si lo encuentra
			x = p->elemento[nums_restantes];	//guarda nodo		
			tam--;			
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
			return true;			
		}
		p = p->siguiente;
	}
	return false;
}
//marco listo
template<class T, int N>
bool ListB<T, N>::pop(T &x) {
	std::queue<T> ColaElementos;
	if (primero == NULL) {
		return false;
	}else {
		x = primero->elemento[0];
		
		for (int i = 1; i < tam; i++) {
			T a;
			this->get(i, a);
			ColaElementos.push(a);
		}
	}
	tam = 0;
	this->~ListB();
	primero == NULL;
	insertarNuevamente(ColaElementos);
	return true;
}
//luis tarminada
template<class T, int N>
bool ListB<T, N>::pop_back(T &x) {
	int nodos = (tam-1) / N, ultima_pos = (tam-1) % N;
	link p = primero;
	bool elimino = false;
	cout << "\n nodos: " << nodos << " pos: " << ultima_pos<<" tam: "<<tam<<"\n";	
	for (int i = 0; i < nodos; i++) {		
		//preguntar si nodo siguiente se tiene que eliminar, decrementar tamaño,optener elemento, eliminar y retornar
		if (p->siguiente && !p->siguiente->siguiente && (tam%N)==1) {
			x = p->siguiente->elemento[0];
			delete p->siguiente;
			p->siguiente = NULL;
			tam--;		
			elimino = true;
			return true;
		}
		else p = p->siguiente;
	}
	//si nodo vasio
	if (tam == 0) {
		delete primero;
		primero = nullptr;
		//para verificar si estaba vacio o si se elimino en este instante
		if (elimino)  return true; return false;
	}
	// eliminar ultimo elemento, decrementar tamaño y returnar y decir que lleno = false
	else {		
		x = p->elemento[ultima_pos];
		tam--;
		p->elemento[ultima_pos] = "";
		p->lleno = false;
		return true;
	}
}
//marco listo
template<class T, int N>
bool ListB<T, N>::get(int pos, T &element) {
	link p = primero;
	int posicion, numerosRestantes = 0, cantidadNodos;
	while (posicion - N >= 0) {
		posicion -= N;
		p = p->siguiente;
		cantidadNodos++;
	}
	numerosRestantes = posicion;
	for (int i = 0; i <= (tam / N); i++) {
		if (i == cantidadNodos);
		element = p->elemento[numerosRestantes];
	}
}
//luis termianda
template<class T, int N>
bool ListB<T, N>::get_front(T& element) {
	if (tam>0) element = primero->elemento[0];
	else return false;
	return true;
}
//marco listo
template<class T, int N>
bool ListB<T, N>::get_back(T &element) {
	link p = primero;
	while (p->siguiente) {
		p = p->siguiente;
	}
	if (p->lleno) {
		element = p->elemento[(tam%N - 1)];
		return true;
	}
	return false;
}
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
//marco listo
template<class T, int N>
ListB<T, N>::~ListB() {
	link p;
	while (primero) {
		p = primero->siguiente;
		delete primero;
		p = primero;
	}
}