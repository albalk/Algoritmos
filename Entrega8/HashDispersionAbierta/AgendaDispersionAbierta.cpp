#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h"

Agenda::Agenda(int capacidad){
	assertdomjudge(capacidad>0);

	tabla = new ListaEnlazada[capacidad];
	this->capacidad = capacidad;
	this->n = 0;
}

Agenda::~Agenda(){
	delete[] tabla;
}

int Agenda::obtenerPosicion(long telefono){
	int posicion = telefono % capacidad;
	return posicion;
}

bool Agenda::existeContacto(long telefono){
	Contacto contacto;
	contacto.telefono = telefono;
	int posicion = obtenerPosicion(telefono);

	if (tabla[posicion].buscar(contacto) != -1){
		return true;
	}else{
		return false;
	}
		
}

string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	
	Contacto contacto;
	contacto.telefono = telefono;
	int posicionTabla = obtenerPosicion(telefono);
	int posicionLista = tabla[posicionTabla].buscar(contacto);

	if (posicionLista != -1){
		return (tabla[posicionTabla].getValor(posicionLista).nombre);
	}

}

void Agenda::introducirContacto(long telefono, string nombre){
	assertdomjudge(existeContacto(telefono) == false);
	Contacto contacto;
	contacto.telefono=telefono;
	contacto.nombre=nombre;

	int posicion = obtenerPosicion(telefono);
	this->tabla[posicion].insertar(0, contacto);
	this->n++;
}

void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono)==true);

	Contacto contacto;
	contacto.telefono=telefono;
	int posicionTabla=obtenerPosicion(telefono);
	int posicionLista=tabla[posicionTabla].buscar(contacto);

	if(posicionLista!=-1){
		tabla[posicionTabla].eliminar(posicionLista);
		this->n--;
		return;
	}
}



void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

