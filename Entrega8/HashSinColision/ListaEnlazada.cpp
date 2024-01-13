#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <stdlib.h>
#include <iostream>


ListaEnlazada::ListaEnlazada(){
    this->n=0;
    this->lista=NULL;
    this->posicionUltimoNodoAccedido=0;
    this->punteroUltimoNodoAccedido=NULL;
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

    if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido != -1){
        aux = punteroUltimoNodoAccedido;
    }else if (posicion == posicionUltimoNodoAccedido + 1 && posicionUltimoNodoAccedido != -1){
        aux = punteroUltimoNodoAccedido->siguienteNodo;
    }else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1){
        aux = punteroUltimoNodoAccedido->anteriorNodo;
    }else if (posicion <= n / 2){
        aux=this->lista;
        for (int i=0; i<posicion; i++){
            aux=aux->siguienteNodo;
        }
    }else{
		aux = lista->anteriorNodo;
		for (int i = n - 1; 1 > posicion; i--)
			aux = aux->anteriorNodo;
	}

    return aux;

}

Contacto ListaEnlazada::getValor(int posicion){
    assertdomjudge(n>0);
	assertdomjudge(posicion>=0 && posicion<=n-1);

    Nodo* valorNodo=getNodo(posicion);

    return valorNodo->elemento;
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor){
    assertdomjudge(n>0);
	assertdomjudge(posicion>=0 && posicion<=n-1);

    this->getNodo(posicion)->elemento=nuevoValor;
}

int ListaEnlazada::getN(){
    return this->n;
}

void ListaEnlazada::insertar (int posicion, Contacto nuevoValor){
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

void ListaEnlazada::concatenar(ListaEnlazada* listaAConcatenar){
    assertdomjudge(listaAConcatenar != NULL);

	int n2=listaAConcatenar->getN();    //coge el tamaño de la lista a concatenar

	for (int i=0; i<n2; i++){
		Contacto aux = listaAConcatenar->getValor(i);    //copia el valor de la posición de la lista a concatenar
		insertar(n, aux);   //lo añade a la lista original
	}
}

int ListaEnlazada::buscar(Contacto elementoABuscar){
    
    int posicion = 0;
	bool encontrar = false;

	while ((encontrar==false) && (posicion<this->n)){
		if (getValor(posicion).nombre == elementoABuscar.nombre && getValor(posicion).telefono==elementoABuscar.telefono){
            encontrar = true;
        }
		posicion++;
	}

	if (encontrar == true){
        return posicion-1;
    }else{
        return -1;
    }
	
}