//Recorrido Inorden recursivo
void inorden(Nodo *nodo){
	if(nodo != nullptr){
		inorden(nodo->hijoIzq);
		cout << nodo->dato << endl;
		inorden(nodo->hijoDer);
	}
}


//Recorrido Inorden iterativo 
void inorden(Nodo *raiz){
	stack<Nodo*> nodoStack;
	Nodo *aux = raiz;
	while(!stack.empty() || aux != nullptr){
		if(aux != nullptr){
			stack.push(aux);
			aux = aux->hijoIzq;
		}
		else{
			aux = stack.top();
			stack.pop();
			cout << aux->data << endl;
			aux = aux->hijoDer;
			
		}
		
	}
}


//Insertar recursivo

void insertarNodo(int dato){
	if(!buscarNodo(this->raiz, dato)){
		insertarNodo(this->raiz, dato);
		return;
	}
	cout << "El nodo que intentas agregar ya existe " << endl;
}

void insertarNodo(Nodo *& nodo, int dato){
	if(nodo == nullptr){
		Nodo *nuevoNodo = new Nodo(dato);
		nodo = nuevonodo;
		return;
	}
	if(dato < nodo->dato) {
		insertarNodo(nodo->hijoIzq, dato);		
	}
	else{
		insertarNodo(nodo->hijoDer, dato);
			
	}
}

//Insertar Iterativo

void insertarNodoIT(Nodo *& nodo, int dato){
	Nodo * aux = nodo;
	Nodo * padre = nullptr;
	if(nodo == nullptr){
		nodo = new Nodo(dato);
		return;
	}
	while(aux != nullptr){
		padre = aux;
		if(dato < aux->dato){
			aux = aux->hijoIzq;
		}
		else{
			aux = aux->hijoDer;
		}
	}
	if(dato < padre->dato){
		padre->hijoIzq = new Nodo(dato);
	}
	else{
		padre->hijoDer = new Nodo(dato);
	}
	
	
}

//Eliminar Recursivo

void eliminarNodo(int dato){
	
	eliminarNodo(this->raiz, dato);
}

void eliminarNodo(Nodo *&nodo, int dato){
	if(nodo == nullptr){
		cout << "El nodo que quieres eliminar no existe" << endl;
		return;
	}
	
	if(dato < nodo->dato){
		eliminarNodo(nodo->hijoIzq, dato);
	}
	else if(dato > nodo->dato){
		eliminarNodo(nodo->hijoDer, dato);
		
	}
	else{
		if(nodo->hijoIzq == nullptr && nodo->hijoDer == nullptr){
			nodo = nullptr;
			delete nodo;			
		}
		else if(nodo->hijoIzq && nodo->hijoDer){
			Nodo *pred = nodoMax(nodo->hijoIzq);
			nodo->data = pred->data;
			eliminarNodo(nodo->hijoIzq, pred->data);
			
		}
		else{
			Nodo* hijo = nullptr;
			if(nodo->hijoIzq == nullptr){
				hijo = nodo->hijoDer;
			}
			else{
				hijo = nodo->hijoIzq;
			}
			Nodo* aux = nodo;
			nodo = hijo;
			delete aux;	
		}
	}
}

Nodo* nodoMax(Nodo* nodo){
	while(nodo->hijoDer != nullptr){
		nodo = nodo->hijoDer;
	}
	return nodo;
}

//Elminrar iterativo

void ABB::eliminarNodoIT(NodoABB *nodo, int dato) {

	if (nodo == nullptr) {
		cout << "El nodo que estas intentando eliminar no existe " << endl;
		return;
	}
	NodoABB* hijo = nodo;
	NodoABB* padre = nullptr;
	bool caso2 = false;
	bool raiz = false;
	while (true) {
		while (true) {
			if (dato != hijo->dato) {
				padre = hijo;
				if (dato < hijo->dato) {
					hijo = hijo->hijoIzq;
				}
				else if (dato > hijo->dato) {
					hijo = hijo->hijoDer;
				}
				continue;
			}
			if (caso2) {
				if (raiz) {
					this->raiz->dato = dato;
				}
				else {
					padre->dato = dato;
				}
			}
			break;
		}

		while (true) {
			if (hijo->hijoIzq == nullptr && hijo->hijoDer == nullptr) {
				if (padre->hijoDer == hijo) {
					padre->hijoDer = nullptr;
				}
				else {
					padre->hijoIzq = nullptr;
				}
				delete hijo;
				return;
			}
			else if (hijo->hijoIzq && hijo->hijoDer) {
				NodoABB * pred = nodoMax(hijo->hijoIzq);
				if (hijo == this->raiz) {
					raiz = true;
				}
				hijo = nodo;
				dato = pred->dato;
				caso2 = true;
				break;
			}
			else {

				if (padre->hijoDer == hijo) {
					padre->hijoDer = hijo->hijoDer;
				}
				else {
					padre->hijoIzq = hijo->hijoIzq;
				
				}
				return;
			}
		}
	}
}


bool buscarNodo(int dato){
	return buscarNodo(this->raiz,dato);
	
}

bool buscarNodo(Nodo* nodo, int dato){
	if (nodo != nullptr){
		if(nodo->dato == dato){
			return true;
		}
		if(dato > nodo->dato){
			return buscarNodo(nodo->hijoDer, dato);
			
		}
		return buscarNodo(nodo->hijoIzq, dato);
	}
	return false;
}

