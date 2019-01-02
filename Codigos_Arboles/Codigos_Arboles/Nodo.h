#pragma once
class Nodo
{
public:
	Nodo(int dato);
	bool estaLleno();
	~Nodo();

private:
	int dato;
	Nodo* hijoIzq;
	Nodo* hijoDer;

	friend class ArbolBinario;
};

