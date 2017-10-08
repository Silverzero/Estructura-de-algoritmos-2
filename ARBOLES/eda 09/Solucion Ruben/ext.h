//Eda 09 Rubén Martin E33 && Marco Desantes E11

#ifndef ext_h
#define ext_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
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

	size_t altura() const {
		return altura(this->root_);
	}

	size_t nodos() const {
		int i = 0;
		return nodos(this->root_, i);
	}

	size_t hojas() const {
		if (this->root_ == nullptr) return 0;
		int i = 0;
		return hojas(this->root_, i);
	}

private:
	static size_t altura(Link r) {
		//Si es el arbol vacio
		if (r == nullptr) {
			return 0;
		}
		//Si no comprobamos la altura maxima de cada bifurcacion sumando la unidad propia de la raiz
		else {
			return 1 + std::max(altura(r->left_), altura(r->right_));
		}
	}

	static size_t nodos(Link r, int &i) {
		if (r == nullptr) { //Si el arbol es vacio el numero de nodos no aumenta
			return i; 
		}
		else { //Si no es vacio, aumentamos el numero de nodos y hacemos llamadas a sus hijos de forma recursiva
			i++;
			nodos(r->left_, i);
			nodos(r->right_, i);
		}
		return i;
	}

	static size_t hojas(Link r, int &i) {
		if (r != nullptr){ //chequeamos que no sea vacio
			//Si sus hijos son vacios es que es una hoja
			if (r->left_ == nullptr &&  r->right_ == nullptr) {
				i++;
			}
			else{
				//De tener hijos, chequeamos recursivamente esto mismo hacia abajo
				hojas(r->left_, i);
				hojas(r->right_, i);
			}
		}
		return i;
	}
};

#endif