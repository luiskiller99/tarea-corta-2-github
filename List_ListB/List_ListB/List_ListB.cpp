// List_ListB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "pch.h"
#include <iostream>
#include "ListaSimple.h"

int main()
{
    std::cout << "Hello World World!\n"; 
	std::cout << "mini programita!\n";
	List<int> lm("Lista1");

	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	lm.push_back(40);
	lm.insertarR(5, 0);
	lm.insertarR(8, 1);
	lm.insertarR(15, 5);
	lm.insertarR(50, 99);
	lm.insertarR(999, 1);
	lm.print();
	std::cout << "\n";
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();
	std::cout << "\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
