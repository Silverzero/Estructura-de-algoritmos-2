//Eda 12 Rubén Martin E33 && Marco Desantes E11

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "bintree_eda.h"
#include "ext.h"

using namespace std;

template <class T>
bintree_ext<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

// El coste de recorrer el arbol depende de como sea, puede ser logaritmico si su forma es favorable
// o incluso lineal en algunos tipos de arbol donde por ejemplo solo haya hijos izquierdos
bool resolver() {

	char c;
	bintree_ext<int> p; 
	p = leerArbol(-1); //Cargo el arbol
	int equipos = 0, maxRuta = 0;
	p.nodos(maxRuta, equipos);
	cout << equipos << " " << maxRuta << endl;
	return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos1.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
	 int numCasos;
	 std::cin >> numCasos;
	 for (int i = 0; i < numCasos; ++i)
		 resolver();



    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
    //system("PAUSE");
     #endif
    
    return 0;
}