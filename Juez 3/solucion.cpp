//E11 Marco Desantes Gutierrez
//E33 Ruben Martin Acebedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "complejo.h"

void resuelveCaso() {
	// leer los datos de la entrada
	int iterator;
	float partereal, parteimaginaria, max = 2.00;
	
	// leemos el numero imaginario e iteraciones.
	std::cin >> partereal >> parteimaginaria >> iterator;
	//Creamos el complejo.
	Complejo complex(partereal, parteimaginaria);
	//Creamos Z sub 0.
	Complejo Z(0.00, 0.00);
	//bool para acabar antes si hay error.
	bool salir = false;
	for (int i = 0; i < iterator && !salir; i++)
	{
		Z = Z*Z + complex;
		if (Z.mod() > max)  salir = true;
	}

	if (salir) std::cout << "NO" << std::endl;
	else std::cout << "SI" << std::endl;;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}