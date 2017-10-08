#ifndef listaexamen_h
#define listaexamen_h
#include <iostream>
#include "queue_eda.h"
using namespace std;


template <class T>
class listaexamen : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:
	void borrarpares()
	{
		Nodo* nodoLinkar = this->prim;
		Nodo* nodoaux = this->prim;
		Nodo* nodoABorrar;
		int i = 1;
		while (nodoaux != nullptr){
			if (i % 2 == 1)
			{
				nodoLinkar = nodoaux;
				nodoaux = nodoaux->sig;
				i++;
			}
			else
			{
				nodoABorrar = nodoaux;
				nodoaux = nodoaux->sig;
				delete [] nodoABorrar;
				nodoLinkar->sig = nodoaux;
				--this->nelems;
				i++;
			}
		}
	}

	void print()
	{
		Nodo* act = this->prim;
		for (int i = 0; i < this->nelems; i++)
		{
			cout << act->elem << " ";
			act = act->sig;
		}
		cout << endl;
	}

};

#endif