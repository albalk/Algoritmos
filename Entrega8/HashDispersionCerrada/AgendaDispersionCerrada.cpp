#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

//constructor
Agenda::Agenda(int capacidad){
	this->capacidad=capacidad;
	this->n=0;
	//reserva de memoria
	nombres = new string [capacidad];
	telefonos = new long [capacidad];
	vacias = new bool [capacidad];
	borradas = new bool [capacidad];

	//inicializar que todas están disponibles
	for (int i = 0; i<this->capacidad; i++){
		vacias[i] = true;
		borradas[i] = false;
	}
}

//destructor
Agenda::~Agenda(){
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

int Agenda::obtenerPosicion(long telefono){
	int posicion = telefono%this->capacidad;
	return posicion;
}

int Agenda::buscarContacto(long telefono){
	int posicion = obtenerPosicion(telefono);
	bool encontrado = false;
	int numCasillas = this->capacidad;

	while (encontrado == false && numCasillas > 0 && (vacias[posicion] == false || borradas[posicion] == true)){
		if (vacias[posicion] == false && telefonos[posicion] == telefono){
			encontrado = true;
		}else{
			posicion=(posicion + 1)%capacidad;
			numCasillas--;
		}
	}

	if (encontrado == true){
		return posicion;
	}else{
		return -1;
	}
		
}

int Agenda::buscarHueco(long telefono){
	//si no está llena
	assertdomjudge(isLlena()==false);
	//busca una posición vacía
	int posicion = obtenerPosicion(telefono);
	while (vacias[posicion] == false){
		posicion=(posicion + 1) % capacidad;
	}
	//devuelve la nueva posición
	return posicion;
}

bool Agenda::isLlena(){
	if(this->n==this->capacidad){
		return true;
	}else{
		return false;
	}
}

bool Agenda::existeContacto(long telefono){
	int posicion = buscarContacto(telefono);

	if (posicion == -1){
		return false;
	}else{
		return true;
	}
}

string Agenda::getContacto(long telefono){
	int posicion = buscarContacto(telefono);
	//si existe
	assertdomjudge(existeContacto(telefono)==true);
	//se devuelve
	return this->nombres[posicion];
}

void Agenda::introducirContacto(long telefono, string contacto){
	assertdomjudge(isLlena()==false);	//si no está llena
	assertdomjudge(existeContacto(telefono)==false); //y el contacto que se va a introducir no existe
	//se introduce
	int posicion = buscarHueco(telefono);
	nombres[posicion] = contacto;
	vacias[posicion] = false;
	borradas[posicion] = false;
	telefonos[posicion] = telefono;
	this->n++;
}

void Agenda::eliminarContacto(long telefono){
	//si el contacto existe
	assertdomjudge(existeContacto(telefono)==true);
	//se elimina
	int posicion = buscarContacto(telefono);
	vacias[posicion] = true;
	borradas[posicion] = true;
	this->n--;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

