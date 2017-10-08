//Eda 12 Rubén Martin E33 && Marco Desantes E11

#ifndef ext_h
#define ext_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include "bintree_eda.h"
using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	//constructoras
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	//Le meto un parametro generico, para que una vez declarado de un tipo en su llamada
	// tenga una valor inicializado de referencia 
	void nodos(int &max_ruta, int &equipos)const{
		int actRuta = 0;
		nodos(this->root_,  max_ruta, actRuta, equipos);
		}

private:
	

	static int nodos(Link r, int &max_ruta, int &act, int &equipos) {
		//Si es vacio sale devolviendo el numero de excursionistas de esa rama hasta el momento
		if (r != nullptr){
			if (r->elem_ != 0) //Si el nodo actual tiene algun excursionista lo añadimos
			{
				act += r->elem_;
			}
			if (act > 0 && equipos == 0) equipos++;
			int auxI = act, auxR = act; //Variables que permitiran no modificar act en llamadas recursivas
			int rutaI = nodos(r->left_, max_ruta, auxI, equipos);
			int rutaR = nodos(r->right_, max_ruta, auxR, equipos);
			//Comprobacion para saber cuantos equipos mandar
			if (rutaI > act && rutaR > act) equipos++;
			//Saber cuantos excursiones hay en la mayor ruta
			if (rutaI > rutaR) act = rutaI;
			else act = rutaR;
			if (act > max_ruta) max_ruta = act;
		}
		return act;
	}

};

#endif