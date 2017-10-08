// Ruben Martin Acebedo 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

// funcio?n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(int diaAct, int mesAct, int AnAct, int diaNa, int mesNa, int anNa)
{
	int mes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int acum = 0;
	int diasNan = 0;
	if (mesAct == mesNa && diaAct == diaNa) return 0;
	acum += ((AnAct - anNa) - 1) * 364; //Quitamos el cumple

	//Dias del año actual
	if (mesAct > mesNa || (mesAct == mesNa && diaAct >= diaNa)) acum--;
	for (int i = 0; i < mesAct - 1; i++)
	{
		acum += mes[i];
	}
	acum += diaAct;
	//Dias del año en el que nacio
	for (int i = 0; i < mesNa - 1; i++)
	{
		diasNan += mes[i];
	}
	acum += 365 - (diasNan + diaNa);
	return acum;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int diaAct, mesAct, AnAct, diaNa, mesNa, anNa;
	cin >> diaNa;
	cin >> mesNa;
	cin >> anNa;
	cin >> diaAct;
	cin >> mesAct;
	cin >> AnAct;
	if (diaAct == 0 && mesAct == 0 && AnAct == 0 && diaNa == 0 && mesNa == 0 && anNa == 0)
		return false;

	int sol = resolver(diaAct, mesAct, AnAct, diaNa, mesNa, anNa);

	cout << sol << endl;
	return true;

}

int main() {
	// Para la entrada por fichero.



	while (resuelveCaso())
		;



	return 0;
}