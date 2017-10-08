//E11 Marco Desantes Gutierrez
//E33 Ruben Martin Acebedo

#ifndef _Complejos
#define _Complejos

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>  // invalid_argument

class Complejo {
private:
	//Atributos
	float _real;
	float _imaginaria;
	/*static bool check(float real, float imaginaria)
	{
		return real <= 2.00 && real >= -2.00 && imaginaria <= 2.00 && imaginaria >= -2.00;
	}*/
public:
	//Constructora
	Complejo(float real, float imaginaria)
	{
		/*if (check(real, imaginaria))
		{*/
			_real = real;
			_imaginaria = imaginaria;
		/*}
		else throw std::invalid_argument("argumentos incorrectos para el numero complejo perteneciente a los fractales de Mandelbrot");*/
	}

	//Metodos
	float mod() const {
		//mod(a+bi) = sqrt(a2 + b2).
		return sqrt(pow(_real,2) + pow(_imaginaria,2));
	}


	Complejo operator+(Complejo const& complejo2) const {
		//(a+bi) + (c+di) = (a+c) + (b+d)i 
		return Complejo(_real + complejo2._real, _imaginaria + complejo2._imaginaria);
	}

	Complejo operator*(Complejo const& complejo2) const {
		//(a+bi) * (c+di) = (a*c-b*d) + (a*d+c*b)i 
		return Complejo(((_real*complejo2._real)-(_imaginaria*complejo2._imaginaria)),((_real*complejo2._imaginaria)+(complejo2._real*_imaginaria )));
	}

};
#endif
