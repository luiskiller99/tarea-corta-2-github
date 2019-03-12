// List_ListB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListB.h"
void pruebas_ListB() {

	std::cout << "\n";
	std::cout << "\n PARTE ListB \n";
	string holiss;
	ListB<int, 3> el("Numeros");
	std::cout << "\n push back \n";
	el.push_back(45);
	el.push_back(67);
	el.push_back(64);
	el.push_back(37);
	el.push_back(67);
	el.push_back(67);
	el.push_back(67);
	el.push_back(67);
	el.push_back(67);
	el.push_back(45);

	el.print();

	ListB<string, 3> las("nombres");
	std::cout << "\n push back \n";
	las.push_back("Luis");
	las.push_back("roberto");
	las.push_back("ana");
	las.push_back("pao");
	las.push_back("susana");
	las.push_back("carlos");
	las.push_back("pri");
	las.print();


	std::cout << "\n remove \n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(3, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";	

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";

	las.remove(0, holiss);
	std::cout << "\n eliminara a : " << holiss << "\n";
	las.print();
	std::cout << "\n\n";	


	las.push_back("alonso");
	las.print();
	std::cout << "\n\n";
	las.push_back("alonso");
	las.print();
	std::cout << "\n\n";
	las.push_back("Luis");
	las.print();
	std::cout << "\n\n";
	las.push_back("alonso");
	las.print();
	std::cout << "\n\n";
	las.push_back("ana");
	las.print();
	std::cout << "\n\n";
	

	las.remove(1, holiss);		

	las.print();
	std::cout << "\n\n";
	
	std::cout << "\n pop back \n";
	las.pop_back(holiss);
	std::cout << "\nSe eliminara a: "<<holiss<<"\n";
	las.print();
	std::cout << "\n\n";
	las.pop_back(holiss);
	std::cout << "\nSe eliminara a: " << holiss << "\n";
	las.print();
	std::cout << "\n\n";
	std::cout << "\n get front \n";
}
void pruebas_List() {
	/*lista numeros*/
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
	/*lista personas*/
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("Luis");
	la.push_back("juan");
	la.print();
	std::cout << "\n";

	int holis;
	string holiss;
	std::cout << "\nPrueba del remove en List<int>\n";
	lm.remove(0, holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	lm.remove(4, holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	lm.remove(6, holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	std::cout << "\n";

	std::cout << "\nPrueba del remove en List<String>\n";
	la.remove(0, holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.remove(1, holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.remove(0, holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.remove(0, holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	std::cout << "\n";

	std::cout << "\nPrueba del pop en List<int>\n";
	lm.pop(holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	lm.pop(holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	std::cout << "\n";

	std::cout << "\nPrueba del pop en List<String>\n";
	la.pop(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	std::cout << "\n";
	std::cout << "\nPrueba del popback en List<int>\n";
	lm.pop_back(holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	lm.pop_back(holis);
	std::cout << "\nelimino a :" << holis << "\n";
	lm.print();
	std::cout << "\n";

	std::cout << "\nPrueba del popback en List<String>\n";
	la.pop_back(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop_back(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop_back(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	la.pop_back(holiss);
	std::cout << "\nelimino a :" << holiss << "\n";
	la.print();
	std::cout << "\n";
}
int main(){    	
	/*Prueba de remove, pop, popback*/
	/*List  luis*/
	if (false) 
		pruebas_List();
	/*Prueba de ,,,,,,,*/
	/*ListB luis*/
	else if(true)
		pruebas_ListB();
	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
