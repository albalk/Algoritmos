#include "Cola.h"
#include<iostream>

Cola::Cola(){
	principio = NULL;
	final = NULL;
}

void Cola::encolar(int num){
	Nodo* nodoSiguiente = NULL;

	if(principio == NULL){
		Nodo* aux=new Nodo(num,nodoSiguiente);
		this->principio = aux;
		this->final = aux;
	}else{
		Nodo* nodoAnterior = this->final;
		Nodo* ultimoNodo = new Nodo(num,nodoSiguiente);
		nodoAnterior->siguiente = ultimoNodo;
		this->final = ultimoNodo;
	}
}

int Cola::desencolar(){
	int idPrimero = principio->valor;

	if(principio->siguiente==NULL){ //si no hay siguiente en la cola
		Nodo* primerPuesto = this->principio;
		delete(primerPuesto);   //elimina el primer puesto de la cola
		this->principio = NULL;
		this->final = NULL;
	}else{
		Nodo* siguientePuesto = this->principio;
		Nodo* siguienteNodo = siguientePuesto->siguiente;
		delete(siguientePuesto);
		this->principio = siguienteNodo;	
	}

	return idPrimero;
}

bool Cola::estaVacia(){
	if(this->principio == NULL && this->final == NULL){
        return true;
    }else{
		return false;
    }
}