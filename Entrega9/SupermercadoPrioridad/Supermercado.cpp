#include "Supermercado.h"

Supermercado::Supermercado(int n){
	this->n_cajas = n;
	this->cajas = new ColaPrioridad[n];
}

void Supermercado::nuevoUsuario(int n, int id){
	this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
	int i = 0;
	while (this->cajas[n].estaVacia() == false){
		if ((i != n) && (cajas[i].estaVacia()==false)){
            this->cajas[i].encolar(this->cajas[n].desencolar());
        }
		i = (i + 1)%this->n_cajas;
	}
}

int Supermercado::atenderUsuario(int n){
	return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
	return this->cajas[n].estaVacia();
}