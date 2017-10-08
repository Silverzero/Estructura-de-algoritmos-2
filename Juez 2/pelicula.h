//E11 Marco Desantes Gutierrez
//E33 Ruben Martin Acebedo

#ifndef _PELICULA
#define _PELICULA

#include <iostream>
#include <iomanip>
#include <stdexcept>  
#include <algorithm>
#include "horas.h"
#include <string>
using namespace std;

class pelicula {
private:
	horas inicio;
	horas fin;
	horas duracion;
	string nombre;
	
public:
	// constructoras
	pelicula()
	{
		horas ini;
		horas dur;
		this->inicio = ini;
		this->duracion = dur;
		this->fin = dur+ini;
		this->nombre ="";
	}
	pelicula(horas ini, horas tiempo, string name)
	{
		this->inicio = ini;
		this->duracion = tiempo;
		this->fin = ini + tiempo;
		this->nombre = name;
	}

	bool operator<(pelicula const&h) const
	{
		if (fin < h.fin)return true;
		else if (h.fin < fin) return false;
		else return  nombre < h.nombre;
	}

	void read(std::istream & input = std::cin) 
	{
		cin >> this->inicio;
		cin >> this->duracion;
		getline(input, nombre);
		this->fin = this->inicio + this->duracion;
	}
	
	void print(std::ostream& o = std::cout) const {
		cout << fin;
		o << setfill('0') << setw(2) << nombre;
	}
};
inline ostream & operator<<(ostream & salida, pelicula const& h) {
	h.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, pelicula & h) {
	h.read(entrada);
	return entrada;
}


#endif