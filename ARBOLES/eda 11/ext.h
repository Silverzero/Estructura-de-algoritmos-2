//Eda 11 Rubén Martin E33 && Marco Desantes E11

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
	T nodos(T i)const{
		if (this->root_ == nullptr) return i; //Si el arbol inicial es vacio devuelvo el parametro tal cual
		else {
			return nodos(this->root_, this->root_->elem_);
		}
	}

private:
	

	static T nodos(Link r, T &i) {
		if (r == nullptr) { //Si el arbol es vacio devuelvo la i que llevase en ese momento
			return i;
		}
		else { //Si no es vacio, comparamos para ver si actualizamos i y hacemos la consulta recursiva
			
			if (r->elem_ < i)
			{
				i = r->elem_;
			}
			nodos(r->left_, i);
			nodos(r->right_, i);
		}
		return i;
	}

};

#endif