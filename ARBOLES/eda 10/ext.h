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

	vector<int> hojas() const {
		vector<int> n; //Declaras un vector vacio
		if (this->root_ == nullptr) return n; //Si es un arbol vacio se puede devolver el vector vacio
		return hojas(this->root_, n);
	}

private:

	static vector<int> hojas(Link r,vector<int> &i) {
		if (r != nullptr){ //chequeamos que no sea vacio
			//Si sus hijos son vacios es que es una hoja
			if (r->left_ == nullptr &&  r->right_ == nullptr) {
				i.push_back(r->elem_); //Incluimos el elemento al final
			}
			else{
				//De tener hijos, chequeamos recursivamente esto mismo hacia abajo
				//Siempre primero hacia la izquierda
				hojas(r->left_, i);
				hojas(r->right_, i);
			}
		}
		return i;
	}
};

#endif