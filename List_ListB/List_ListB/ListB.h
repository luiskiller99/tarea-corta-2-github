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
		Nodo(T x) :elemento{ x }, siguiente{ 0 },
			lleno{ false } {}
		Nodo(T x, struct Nodo* sig)
			:elemento{ x }, siguiente{ sig },
			lleno{ false } {}
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
}
//luis terminado
template<class T, int N>
int ListB<T,N>::len() { return tam*N; }
//marco
template<class T, int N>
void ListB<T, N>::push_front(T x) {}
//luis
template<class T, int N>
void ListB<T, N>::push_back(T x) {}
//marco
template<class T, int N>
void ListB<T, N>::insertar(T x, int pos) {}
//luis
template<class T, int N>
bool ListB<T, N>::remove(int pos, T &x) {}
//marco
template<class T, int N>
bool ListB<T, N>::pop(T &x) {}
//luis
template<class T, int N>
bool ListB<T, N>::pop_back(T &x) {}
//marco
template<class T, int N>
bool ListB<T, N>::get(int pos, T &element) {}
//luis
template<class T, int N>
bool ListB<T, N>::get_front(T &element) {}
//marco
template<class T, int N>
bool ListB<T, N>::get_back(T &element) {}
//luis
template<class T, int N>
void ListB<T, N>::print() {
	link p = primero;	
	std::cout << "\n";
	while (p) {
		for (int i = 0; i < N; i++) 
			std::cout << p->elemento[i] << ", ";
		std::cout << "\n";
		p = p->siguiente;
	}
}
//marco
template<class T, int N>
ListB<T, N>::~ListB() {}