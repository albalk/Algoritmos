#include "ListaEnlazada.h"
#include "Nodo.h"
#include "assertdomjudge.h"
#include <stdlib.h>
#include <iostream>


ListaEnlazada::ListaEnlazada(){
    this->n=0;
    this->lista=NULL;
}

ListaEnlazada::~ListaEnlazada(){
    for(int i=0; i<this->n; i++){
        eliminar(i);
    }
}

Nodo* ListaEnlazada::getNodo (int posicion){
    assertdomjudge(this->n>0);
    assertdomjudge(posicion>=0 && posicion<=this->n-1);

    Nodo* aux=NULL;
    aux=this->lista;
    for (int i=0; i<posicion; i++){
        aux=aux->siguienteNodo;
    }

    return aux;
}

int ListaEnlazada::getValor(int posicion){
    assertdomjudge(n>0);
	assertdomjudge(posicion>=0 && posicion<=n-1);

    Nodo* valorNodo=getNodo(posicion);

    return valorNodo->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor){
    assertdomjudge(n>0);
	assertdomjudge(posicion>=0 && posicion<=n-1);

    this->getNodo(posicion)->elemento=nuevoValor;
}

int ListaEnlazada::getN(){
    return this->n;
}

void ListaEnlazada::insertar (int posicion, int nuevoValor){
    assertdomjudge(posicion>=0 && posicion<=this->n);

    Nodo* nuevoNodo=new Nodo;
    nuevoNodo->elemento=nuevoValor;

    if(this->n==0){ //si el tamaño es 0
        this->lista=nuevoNodo;
        nuevoNodo->siguienteNodo=NULL;  //no hay más nodos
    }else{
        if (posicion==0){   //si se inserta en la posición 0
			nuevoNodo->siguienteNodo = this->lista;
			this->lista=nuevoNodo;
		}else if(posicion==this->n){    //si se inserta en la ultima posición
			nuevoNodo->siguienteNodo = NULL;    //no hay más nodos
			getNodo(n-1)->siguienteNodo = nuevoNodo;    //se enlaza el nodo anterior con el añadido
		}else{  //si es un nodo del medio
			Nodo* nodoAnterior = getNodo(posicion-1);
			Nodo* nodoSiguiente = nodoAnterior->siguienteNodo;

			nodoAnterior->siguienteNodo = nuevoNodo;    //se enlazan el nodo anterior y el nuevo
			nuevoNodo->siguienteNodo = nodoSiguiente;   //se enlazan el nodo nuevo y el siguiente
		}
    }

    n++;    //aumenta el tamaño
}

void ListaEnlazada::eliminar (int posicion){
    assertdomjudge(this->n>0);
	assertdomjudge(posicion>=0 && posicion<=this->n-1);

	Nodo* nodoEliminado = NULL;

	if (posicion==0){   //si se elimina la primera posición
		nodoEliminado=lista;
		Nodo* nodoSiguiente = nodoEliminado->siguienteNodo;   //se enlaza el siguiente
		lista=nodoSiguiente;
	}else{  //si se elimina otra posición
		Nodo* nodoAnterior = getNodo(posicion-1);
		nodoEliminado = nodoAnterior->siguienteNodo;    //se enlazan el nodo anterior y el siguente
		Nodo* nodoSiguiente = nodoEliminado->siguienteNodo;
		nodoAnterior->siguienteNodo = nodoSiguiente;    //se enlazan el nodo siguiente y el anterior
	}

	delete(nodoEliminado);  //elimina el nodo

	n--;    //disminuye el tamaño
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
    assertdomjudge(listaAConcatenar != NULL);

	int n2=listaAConcatenar->getN();    //coge el tamaño de la lista a concatenar

	for (int i=0; i<n2; i++){
		int aux = listaAConcatenar->getValor(i);    //copia el valor de la posición de la lista a concatenar
		insertar(n, aux);   //lo añade a la lista original
	}
}

int ListaEnlazada::buscar(int elementoABuscar){
    
    int aux1=getN();    //tamaño de la lista
    int aux2=0;

    for(int i=0; i<aux1; i++){
        if(elementoABuscar==getValor(i)){
            return i;
        }else{
            aux2++;   //incrementa si no lo encuentra
        }
    }

    if(aux2==aux1){     //si son del mismo valor, el elemento no está en la lista
        return -1;
    }
    
}

