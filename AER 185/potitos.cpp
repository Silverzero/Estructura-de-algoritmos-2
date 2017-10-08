// Grupo E33, Rubén Martin Acebedo
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool buscar(vector<string> const si, string alimento, int &pos);
void insertarOrdenado(vector<string> &si, string alimento, int pos);

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(vector<string> si, vector<string> no, int n)
{
	string c, alimento;
	for (int i = 0; i < n; i++)
	{
		bool encontrado = false;
		cin >> c;
		int pos = 0;
		if (c == "SI:")
		{
			cin >> alimento;
			while (alimento != "FIN")
			{
				encontrado = buscar(si, alimento, pos);
				if(!encontrado)	insertarOrdenado(si, alimento, pos);
				cin >> alimento;
			}
		}
		else
		{
			cin >> alimento;
			while (alimento != "FIN")
			{
				encontrado = buscar(no, alimento, pos);
				if(!encontrado) insertarOrdenado(no, alimento, pos);
				cin >> alimento;
			}
		}
	}
	int posb;
	int cont = 0;
	for (int i = 0; i < no.size(); i++)
	{
		posb = 0;
		if (!buscar(si, no[i], posb))
		{
			if (cont == 0) cout << no[i];
			else cout <<" "<< no[i];
			cont++;
		}
	}
	cout << '\n';
}

//Deberia hacer un buscar y otra para insertar
bool buscar(vector<string> const si, string alimento, int &pos)
{
	int ini = 0, fin = si.size()-1, medio;
	bool encontrado = false;
	while (!encontrado && (ini <= fin))
		{
			medio = (fin + ini) / 2;
			if (si[medio] == alimento)
			{
				encontrado = true;
			}
			else if (si[medio] > alimento)
			{
				fin = medio - 1;
			}
			else if (si[medio] < alimento)
			{
				ini = medio + 1;
			}
		}
	if (encontrado)
		pos = medio;
	else pos = ini;
	
	return encontrado;
}

void insertarOrdenado(vector<string> &si, string alimento, int pos)
{
	si.push_back("");
	for (int i = si.size()-1; i > pos; i--)
	{
		si[i] = si[i - 1];
	}
	si[pos] = alimento;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
	vector<string> si, no;
    if (n == 0) return false; 
    resolver(si, no, n);
    return true;
}

int main() {


	while (resuelveCaso())
		;


    
    return 0;
}