#include "ListaContigua.h"
#include "assertdomjudge.h"
#include "cstdlib"
#include "cstring"
#include <iostream>

//constructor
ListaContigua::ListaContigua(int incremento){
    this->incremento=incremento;
    this->capacidad=0;
    this->capacidad+=this->incremento;
    this->vector=NULL;

    //reserva de memoria
    this->vector=new int[this->incremento];

}

//destructor
ListaContigua::~ListaContigua(){
    delete this->vector;
}

int ListaContigua::getValor(int posicion){
    assertdomjudge(posicion>=0 && posicion<=n-1);

    return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor){
    assertdomjudge(posicion>=0 && posicion<=n-1);

    this->vector[posicion]=nuevoValor;
}

int ListaContigua::getN(){
    return this->n;
} 

int ListaContigua::getCapacidad(){
    return this->capacidad;
} 

void ListaContigua::insertar(int posicion, int nuevoValor){

    assertdomjudge(posicion>=0 && posicion<=this->n);

    //si todo está lleno, reserva más memoria
	if(n==capacidad){
		vector = (int*)realloc(vector, sizeof(int)*(capacidad+incremento));
		capacidad += incremento;
	}

    
	memmove(&vector[posicion + 1], &vector[posicion], sizeof(int) * (n - posicion));

	n++;
	setValor(posicion,nuevoValor);  //asigna el valor nuevo a la posición donde se ha insertado

}

void ListaContigua::eliminar(int posicion){

    assertdomjudge(posicion>=0 && posicion<=n-1);

    //desplaza los valores a la izquierda
	memmove(&vector[posicion], &vector[posicion + 1], sizeof(int)*(n-posicion-1));
	n--;

    //si hay demasiada memoria libre la disminuye
	if(capacidad-n == 2*incremento){
		vector = (int*)realloc(vector, sizeof(int)*(capacidad - incremento));
		capacidad -= incremento;
	}

}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar){
    
    assertdomjudge(listaAConcatenar != NULL);

	int n2 = listaAConcatenar->getN();  //numero de elementos de la segunda lista

	this->vector = (int*)realloc(this->vector, sizeof(int) * (this->capacidad + n2));     //amplia la memoria para poder añadir todos los elementos de la segunda lista 
	this->capacidad += n2;    //aumenta la capacidad

    //concatena
	for (int i = 0; i < n2; i++){
        insertar(n,listaAConcatenar->getValor(i));
    }
		
}

int ListaContigua::buscar(int elementoABuscar){
    int aux=0;

    for(int i=0; i<this->n; i++){
        if(elementoABuscar==this->vector[i]){
            return i;
        }else{
            aux++;  //incrementa si no lo encuentra
        }
    }

    //si es del mismo valor que n, no está en el array
    if(aux==this->n){
        return -1;
    }

}


