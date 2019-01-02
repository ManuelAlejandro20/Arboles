#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

class ArbolBinario
{
public:
	ArbolBinario(int datoRaiz);
	bool agregarNodo(int dato);
	bool eliminarNodo(int dato);
	void imprimirInorden();
	void imprimirPreorden();
	void imprimirPostorden();

	~ArbolBinario();

private:

	//Eliminacion

	int ultimoNum(Nodo* nodo);
	bool remplazarDato(int nuevoDato, int dato, Nodo* nodo);
	bool eliminarNodo(int dato, Nodo*nodo);
	bool buscarNodo(int dato, Nodo *nodo);

	//Prints

	void imprimirPostorden(Nodo *nodo);
	void imprimirInorden(Nodo *nodo);
	void imprimirPreorden(Nodo *nodo);


	//Para agregar

	void agregarNodo(int dato, Nodo* nodo);
	bool estaCompleto();
	bool subarbolCompleto(Nodo *nodo);
	void ContarNodosSubArbol(int &num, Nodo *nodo);
	int nivelActual(Nodo *nodo);

	Nodo* raiz;
	int cantidad;

};

