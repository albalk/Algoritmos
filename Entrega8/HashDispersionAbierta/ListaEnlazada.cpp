#include "ListaEnlazada.h"
#include <stdlib.h>
#include "assertdomjudge.h"

Nodo* ListaEnlazada::getNodo(int pos){
	assertdomjudge(n > 0);
	assertdomjudge(pos >= 0 && pos <= n - 1);

	Nodo* resultado = NULL;
	resultado = lista;
	for (int i = 0; i < pos; i++){
        resultado = resultado->siguienteNodo;
    }
		
	return resultado;
}

ListaEnlazada::ListaEnlazada(){
	lista = NULL;
	posicionUltimoNodoAccedido = 0;
	punteroUltimoNodoAccedido = NULL;
	n = 0;
}

ListaEnlazada::~ListaEnlazada(){
	while (n > 0){
        eliminar(0);
    }
		
}

Contacto ListaEnlazada::getValor(int posicion){
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);
	Nodo* nodoresultado = getNodo(posicion);
	return nodoresultado->elemento;
}


void ListaEnlazada::setValor(int posicion, Contacto valor){
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);
	getNodo(posicion)->elemento = valor;
}

int ListaEnlazada::getN(){
	return n;
}


void ListaEnlazada::insertar(int posicion, Contacto valor){
	assertdomjudge(posicion >= 0 && posicion <= n);
	Nodo* nodo = new Nodo;
	nodo->elemento = valor;

	if (n == 0){
		lista = nodo;
		nodo->siguienteNodo = NULL;
		nodo->anteriorNodo = NULL;
	}else{
		if (posicion == 0){
			Nodo* prox = getNodo(0);

			nodo->siguienteNodo = prox;
			nodo->anteriorNodo = NULL;
			prox->anteriorNodo = nodo;
			lista = nodo;
		}else if(posicion==n){
			Nodo* anterior = getNodo(n - 1);

			nodo->siguienteNodo = NULL;
			nodo->anteriorNodo = anterior;
			anterior->siguienteNodo = nodo;
		}else{
			Nodo* anterior = getNodo(posicion - 1);
			Nodo* prox = getNodo(posicion);

			anterior->siguienteNodo = nodo;
			nodo->anteriorNodo = anterior;
			nodo->siguienteNodo = prox;
			prox->anteriorNodo = nodo;
		}
	}
	n++;
}

void ListaEnlazada::eliminar(int posicion){
	assertdomjudge(n > 0);
	assertdomjudge(posicion>=0 && posicion<=n-1);

	Nodo* eliminado = NULL;
	if (posicion == 0){
		eliminado = lista;
		Nodo* proximo = eliminado->siguienteNodo;
		lista = proximo;
	}else if (posicion == n - 1){
		eliminado = getNodo(posicion);
		Nodo* anterior = eliminado->anteriorNodo;
		anterior->siguienteNodo = NULL;
	}else{
		Nodo* anterior = getNodo(posicion-1);
		eliminado = anterior->siguienteNodo;
		Nodo* proximo = eliminado->siguienteNodo;
		anterior->siguienteNodo = proximo;
		proximo->anteriorNodo=anterior;
	}

	delete(eliminado);
	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada* listaConcat){
	assertdomjudge(listaConcat != NULL);

	int m = listaConcat->getN();
	for (int i = 0; i < m; i++){
		Contacto copia = listaConcat->getValor(i);
		insertar(n, copia);
	}
}


int ListaEnlazada::buscar(Contacto elem){
    int posicion = 0;
    bool encontrado = false;

    while (encontrado == false && posicion < n){
        if (getValor(posicion).telefono == elem.telefono)
            encontrado = true;
        posicion++;
    }

    if (encontrado == true){
        return posicion-1;
    }else{
        return -1;
    }
}