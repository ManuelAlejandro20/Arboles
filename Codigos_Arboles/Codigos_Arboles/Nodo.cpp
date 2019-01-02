#include "pch.h"
#include "Nodo.h"


Nodo::Nodo(int dato)
{
	this->dato = dato;
	this->hijoDer = this->hijoIzq = nullptr;
}

bool Nodo::estaLleno() {
	if (this->hijoDer != nullptr && this->hijoIzq != nullptr) return true;
	return false;
}




Nodo::~Nodo()
{
}
