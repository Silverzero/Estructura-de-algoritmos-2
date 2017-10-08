// E11 Marco Desantes Gutierrez

#include <iostream>
#include <list>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "queue_eda.h"
#include <stdexcept>

template <class T>
class ListaInvertida : public queue<T> {

protected:
	using Nodo = typename queue<T>::Nodo;//heredamos SOLO Nodo de Queue_eda.h
public:

	void invertir(){
		Nodo *NodoBack = this->prim;
		Nodo *NodoNext = this->prim->sig;
		NodoBack->sig = nullptr;
		this->ult = NodoBack;
		Nodo *NodoFin;
		while (NodoNext != nullptr) {
			NodoFin = NodoNext->sig;
			NodoNext->sig = NodoBack;
			NodoBack = NodoNext;
			NodoNext = NodoFin;
		}
		this->prim = NodoBack;

	}

	void print(std::ostream & output = std::cout) const {
		Nodo *aux = this->prim;
		while (aux != nullptr) {
			output << aux->elem << ' ';
			aux = aux->sig;
		}
		output << std::endl;
	}

};

void resolver(ListaInvertida<int> &lista)
{
	lista.invertir();
	lista.print();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	ListaInvertida<int> lista;
	std::cin >> numero;
	if (!std::cin)
		return false;
	if (numero == 0) {
		std::cout << std::endl;
		std::cin >> numero;
	}
	while (numero != 0)
	{
		lista.push(numero);
		std::cin >> numero;
	}


	resolver(lista);

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("eda7.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}