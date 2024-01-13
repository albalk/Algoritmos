#include <stdlib.h>
#include "assertdomjudge.h"
#include "ListaCircular.h"

//constructor sin parametros
ListaCircular::ListaCircular(){
	lista = NULL;
	n = 0;
}

//destructor
ListaCircular::~ListaCircular(){
	while (n > 0){
        eliminar(0);
    }
}

//devuelve string de una posición
string ListaCircular::getValor(int posicion){
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo* nodoresultado = getNodo(posicion);
	return nodoresultado->elemento;
}

//asigna un string a una posicion
void ListaCircular::setValor(int posicion, string nuevoValor){
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);
	getNodo(posicion)->elemento = nuevoValor;
}

//devuelve el numero de elementos
int ListaCircular::getN(){
	return n;
}

//funcion insertar de la entrega de listaEnlazada modificada
void ListaCircular::insertar(int posicion, string nuevoValor){
    assertdomjudge(posicion>=0 && posicion<=this->n);

    Nodo* nuevoNodo=new Nodo;
    nuevoNodo->elemento=nuevoValor;

    if(this->n==0){ //si el tamaño es 0
        this->lista=nuevoNodo;
        nuevoNodo->siguienteNodo=NULL;  //no hay más nodos
    }else{
        if (posicion==0 || posicion==n){   //si se inserta en la primera o ultima posición
			Nodo* nodoAnterior = getNodo(posicion-1);
			Nodo* nodoSiguiente = getNodo(0);

            nodoAnterior->siguienteNodo = nuevoNodo;
            nuevoNodo->siguienteNodo = nodoSiguiente;
            nuevoNodo->anteriorNodo = nodoAnterior;
            nodoSiguiente->anteriorNodo = nuevoNodo;

		}else{  //si es un nodo del medio
			Nodo* nodoAnterior = getNodo(posicion-1);
			Nodo* nodoSiguiente = getNodo(posicion);

			nodoAnterior->siguienteNodo = nuevoNodo;    //se enlazan el nodo anterior y el nuevo
			nuevoNodo->anteriorNodo = nodoAnterior;
            nuevoNodo->siguienteNodo = nodoSiguiente;   //se enlazan el nodo nuevo y el siguiente
            nodoSiguiente->anteriorNodo = nuevoNodo;

		}
    }

    n++;    //aumenta el tamaño
}

//funcion eliminar de la entrega de listaEnlazada modificada
void ListaCircular::eliminar (int posicion){
    assertdomjudge(this->n>0);
	assertdomjudge(posicion>=0 && posicion<=this->n-1);

	Nodo* nodoEliminado = NULL;

	if (posicion==0){   //si se elimina la primera posición
		nodoEliminado=lista;
        Nodo* nodoAnterior = nodoEliminado->anteriorNodo;   //se enlaza al anterior
		Nodo* nodoSiguiente = nodoEliminado->siguienteNodo;   //se enlaza el siguiente
        nodoAnterior->siguienteNodo = nodoSiguiente;
		nodoSiguiente->anteriorNodo=nodoAnterior;
        lista=nodoSiguiente;

	}else{  //si se elimina otra posición
		Nodo* nodoAnterior = getNodo(posicion-1);
		nodoEliminado = nodoAnterior->siguienteNodo;    //se enlazan el nodo anterior y el siguente
		Nodo* nodoSiguiente = nodoEliminado->siguienteNodo;
		nodoAnterior->siguienteNodo = nodoSiguiente;    //se enlazan el nodo siguiente y el anterior
        nodoSiguiente->anteriorNodo = nodoAnterior;

    }

	delete(nodoEliminado);  //elimina el nodo

	n--;    //disminuye el tamaño
}

//funcion getNodo de la entrega de listaEnlazada
Nodo* ListaCircular::getNodo (int posicion){
    assertdomjudge(this->n>0);
    assertdomjudge(posicion>=0 && posicion<=this->n-1);

    Nodo* aux=NULL;
    aux=this->lista;
    for (int i=0; i<posicion; i++){
        aux=aux->siguienteNodo;
    }

    return aux;
}

//girar
void ListaCircular::girar(int p){   //p es el num de posiciones que avanza
	if (p >= n){    //gira a la derecha con más de una vuelta completa
		if (p == n){    //una vuelta completa asi que se quedan igual
			lista = getNodo(0);
		}else{      //gira a la derecha menos de una vuelta completa
			int j = p / n;
			lista = getNodo(j);
		}
	}else if(p<n && p>=0){  //gira a la derecha menos de una vuelta completa
		lista = getNodo(p);
	}else if(p<0 && p>(-n)){    //gira a la izquiera más de una vuelta completa
		lista = getNodo(n + p);
	}else{  //gira a la izquiera 
		if (p == (-n)){ //una vuelta completa así que se queda igual
			lista = getNodo(0);
		}else{  //gira a la izquiera menos de una vuelta completa
			int j = p / n;
			lista = getNodo(n+j);
		}
	}
}