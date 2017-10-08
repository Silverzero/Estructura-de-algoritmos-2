//E11 Marco Desantes Gutierrez
//E33 Ruben Martin Acebedo

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"
#include "pelicula.h"

bool resuelveCaso() {
	int n; //numero de peliculas
	cin >> n;

	if (n == 0)  // no hay más casos
		return false;

	// leemos las peliculas
	vector<pelicula> pelis(n);
	for (pelicula & h : pelis)
		cin >> h;

	//Lo ordenamos segun la duracion
	 sort(pelis.begin(), pelis.end());
	for (int i = 0; i < n; i++)
	{
		cout << pelis[i]; //Muestra la duracion y la peli
		cout << endl;
	}
	cout << "---" << endl;
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif
	return 0;
}
