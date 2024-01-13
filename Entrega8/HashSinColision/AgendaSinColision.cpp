#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

//constructor
Agenda::Agenda(int capacidad){
	this->capacidad=capacidad;

	//reserva de memoria
	nombres = new string [capacidad];
	telefonos = new long [capacidad];
	ocupados = new bool [capacidad];

	//inicializar que todos están vacíos
	for (int i = 0; i < capacidad; i++){
		ocupados[i] = false;
	}
		
}

//destructor
Agenda::~Agenda(){
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupados;
}

int Agenda::obtenerPosicion(long telefono){
	int posicion = telefono%this->capacidad;
	return posicion;
}

bool Agenda::existeContacto(long telefono){
	int posicion = obtenerPosicion(telefono);

	if((this->ocupados[posicion]==true)&&(this->telefonos[posicion]==telefono)){
		return true;
	}else{
		return false;
	}

}

string Agenda::getContacto(long telefono){
	int posicion = obtenerPosicion(telefono);
	//si existe
	assertdomjudge(existeContacto(telefono)==true);
	//se devuelve
	return this->nombres[posicion];
}

void Agenda::introducirContacto(long telefono, string contacto){
	int posicion = obtenerPosicion(telefono);
	//si no está ocupado
	assertdomjudge(ocupados[posicion]==false);
	//se introduce
	this->telefonos[posicion]=telefono;
	this->nombres[posicion]=contacto;
	this->ocupados[posicion]=true;
}

/*int pos = obtenerPosicion(telefono);
	assertdomjudge(!ocupados[pos]);
	nombres[pos] = contacto;
	ocupados[pos] = true;
	telefonos[pos] = telefono;*/

void Agenda::eliminarContacto(long telefono){
	//si existe
	assertdomjudge(existeContacto(telefono));
	//se elimina
	int posicion = obtenerPosicion(telefono);
	this->ocupados[posicion]=false;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}


