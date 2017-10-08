/*

Problema 06 juez 2 cuatri EDA

Rubén Martín Acebedo
Marco Desantes Gutierrez

*/

#ifndef lista_h
#define lista_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <stdexcept>
#include "queue_eda.h"
using namespace std;

template <class T>
class lista : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;
public:
	void doblar()
	{
		if (this->nelems == 0) return;
		Nodo* act = new Nodo(this->prim->elem); //Creo un nuevo nodo con mismo elemento que prim
		Nodo* aux = new Nodo();
		aux->sig = this->prim->sig; //Guardo la direccion del nodo que apunta prim para no perderla cuando la modifique
		this->prim->sig = act; //Hago que apunte al nuevo nodo creado
		act->sig = aux->sig; //Y que el nuevo nodo creado apunte donde apuntaba en el principio prim

		//El bucle repite esta operacion hasta encontrar el ultimo elemento que apunta a null
		while (act->sig != nullptr)
		{
			act = act->sig;
			aux->sig = act->sig;
			act->sig = new Nodo(act->elem);
			act = act->sig;
			act->sig = aux->sig;
		}
		this->nelems = 2 * this->nelems;
		this->ult = act;
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