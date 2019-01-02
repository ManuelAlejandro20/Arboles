#include "pch.h"
#include "ArbolBinario.h"
#include <math.h>


ArbolBinario::ArbolBinario(int datoRaiz)
{
	this->cantidad = 1;
	this->raiz = new Nodo(datoRaiz);
}

bool ArbolBinario::agregarNodo(int dato)
{
	if (!buscarNodo(dato, this->raiz)) {
		agregarNodo(dato, this->raiz);
		return true;
	}
	return false;
}

bool ArbolBinario::eliminarNodo(int dato)
{
	if (buscarNodo(dato, this->raiz)) {
		int ultimoElemento = ultimoNum(this->raiz);
		eliminarNodo(ultimoElemento, this->raiz);
		this->cantidad--;
		return (remplazarDato(ultimoElemento, dato, this->raiz));
	
	}
	return false;
}

void ArbolBinario::imprimirInorden()
{
	imprimirInorden(this->raiz);
}

void ArbolBinario::imprimirPreorden()
{
	imprimirPreorden(this->raiz);
}

void ArbolBinario::imprimirPostorden()
{
	imprimirPostorden(this->raiz);
}

bool ArbolBinario::buscarNodo(int dato, Nodo * nodo)
{
	if (nodo) {
		if (nodo->dato == dato) return true;
		if (buscarNodo(dato, nodo->hijoIzq)) return true;
		if (buscarNodo(dato, nodo->hijoDer)) return true;
	}
	return false;
}

int ArbolBinario::ultimoNum(Nodo * nodo)
{
	if (nodo->hijoIzq == nullptr && nodo->hijoDer == nullptr) return nodo->dato;
	int largo = nivelActual(nodo);
	int nodosIdeales = pow(2,largo) - 1;
	int cantNodos = 0;
	ContarNodosSubArbol(cantNodos, nodo);
	int nodosFaltantes = abs(nodosIdeales - cantNodos);
	int nodosDelNivel = pow(2,largo - 1);
	int nodosActuales = abs(nodosFaltantes - nodosDelNivel);
	int mitad = nodosDelNivel / 2;
	if (nodosActuales > mitad) {
		return ultimoNum(nodo->hijoDer);
	}
	return ultimoNum(nodo->hijoIzq);
}

bool ArbolBinario::remplazarDato(int nuevoDato, int dato, Nodo * nodo)
{
	if (nodo) {
		if (nodo->dato == dato) {
			nodo->dato = nuevoDato;
			return true;
		}
		if (remplazarDato(nuevoDato, dato, nodo->hijoIzq)) return true;
		if (remplazarDato(nuevoDato, dato, nodo->hijoDer)) return true;
	}
	return false;
}

bool ArbolBinario::eliminarNodo(int dato, Nodo * nodo)
{
	if (nodo) {
		if (nodo->hijoIzq->dato == dato) {
			nodo->hijoIzq = nullptr;
			return true;
		}
		if (nodo->hijoDer->dato == dato){
			nodo->hijoDer = nullptr;
			return true;
		}
		if (eliminarNodo(dato, nodo->hijoIzq)) return true;
		if (eliminarNodo(dato, nodo->hijoDer)) return true;
	}
	return false;
}

void ArbolBinario::imprimirPostorden(Nodo * nodo)
{
	if (nodo != nullptr) {
		imprimirPostorden(nodo->hijoIzq);
		imprimirPostorden(nodo->hijoDer);
		cout << nodo->dato << endl;
	}
}

void ArbolBinario::imprimirInorden(Nodo * nodo)
{
	if (nodo != nullptr) {
		imprimirInorden(nodo->hijoIzq);
		cout << nodo->dato << endl;
		imprimirInorden(nodo->hijoDer);
	}
}

void ArbolBinario::imprimirPreorden(Nodo *nodo)
{
	if (nodo != nullptr) {
		cout << nodo->dato << endl;
		imprimirPreorden(nodo->hijoIzq);
		imprimirPreorden(nodo->hijoDer);
	}
}


ArbolBinario::~ArbolBinario()
{
}

void ArbolBinario::agregarNodo(int dato, Nodo * nodo)
{
	if (nodo == nullptr || nodo->hijoIzq == nullptr || nodo->hijoDer == nullptr) {
		if (nodo->hijoIzq == nullptr) {
			nodo->hijoIzq = new Nodo(dato);
		}
		else if (nodo->hijoDer == nullptr) {
			nodo->hijoDer = new Nodo(dato);
		}
		this->cantidad++;
		return;
	}
	if (estaCompleto() || !nodo->hijoIzq->estaLleno()) {
		agregarNodo(dato, nodo->hijoIzq);
		return;
	}
	else if (subarbolCompleto(nodo->hijoIzq)) {
		agregarNodo(dato, nodo->hijoDer);
	}
	else {
		agregarNodo(dato, nodo->hijoIzq);
	}
}

bool ArbolBinario::estaCompleto()
{
	int niveles = nivelActual(this->raiz);
	int cantidadIdeal = pow(2, niveles) - 1;
	if (cantidadIdeal == this->cantidad) return true;
	return false;
}

bool ArbolBinario::subarbolCompleto(Nodo * nodo)
{
	int niveles = nivelActual(nodo);
	int cantidadNodos = 0;
	ContarNodosSubArbol(cantidadNodos, nodo);
	int cantidadIdeal = pow(2, niveles) - 1;
	if (cantidadIdeal == cantidadNodos) return true;
	return false;
}

void ArbolBinario::ContarNodosSubArbol(int & num, Nodo* nodo)
{
	if (nodo == nullptr) return;
	num++;
	ContarNodosSubArbol(num, nodo->hijoIzq);
	ContarNodosSubArbol(num, nodo->hijoDer);

}

int ArbolBinario::nivelActual(Nodo * nodo)
{
	int niveles = 0;
	while (nodo) {
		niveles++;
		nodo = nodo->hijoIzq;
	}
	return niveles;
}
