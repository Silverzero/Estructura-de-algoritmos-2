// Ruben Martin Acebedo 2ºE software
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool buscar(vector<int> const si, int n, int &pos);
void insertarOrdenado(vector<int> &si, int n, int pos);

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool cubifinito(int n, vector<int> &v)
{
	int rest, sum = 0, pos = 0;
	if (n == 1) { 
		cout << n << " -";
		return true;
	}
	else
	{
		if (!buscar(v, n, pos))
		{
			cout << n << " - ";
			insertarOrdenado(v, n, pos);
		}
		else{
			cout << n << " -";
			return false;
		}
	}
	while (n / 10 != 0)
	{
		rest = n % 10;
		sum += rest * rest * rest;
		n = n / 10;
	}
	sum += n*n*n;
	if (cubifinito(sum, v)) return true;
	else return false;
}

void resolver(int datos) 
{
	vector<int> n;
	bool comprobar = cubifinito(datos, n);
	if (comprobar) cout << "> cubifinito.\n";
	else cout << "> no cubifinito.\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (n == 0)
        return false;
    
   resolver(n);
    
    // escribir sol
    
    return true;
    
}
bool buscar(vector<int> const si, int n, int &pos)
{
	int ini = 0, fin = si.size() - 1, medio;
	bool encontrado = false;
	while (!encontrado && (ini <= fin))
	{
		medio = (fin + ini) / 2;
		if (si[medio] == n) encontrado = true;
		else if (si[medio] > n) fin = medio - 1;
		else if (si[medio] < n) ini = medio + 1;
	}
	if (encontrado) pos = medio;
	else pos = ini;
	return encontrado;
}

void insertarOrdenado(vector<int> &si, int n, int pos)
{
	si.push_back(0);
	for (int i = si.size() - 1; i > pos; i--)
	{
		si[i] = si[i - 1];
	}
	si[pos] = n;
}

int main() {
    while (resuelveCaso()) ;
    return 0;
}