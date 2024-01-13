#include "Supermercado.h"
#include <iostream>

Supermercado::Supermercado(int n){
	n_cajas = n;
	cajas = new Cola[n_cajas];
}

void Supermercado::nuevoUsuario(int n, int id){
	cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
	int i;
	bool vacia = cajaVacia(n);
	while (vacia != true){  //si no está vacía
		i = 0;
		while (i < n_cajas-1){
			if (i != n){
				cajas[i].encolar(cajas[n].desencolar());
				i++;
				vacia = cajaVacia(n);
			}
		}		  
	}
}

int Supermercado::atenderUsuario(int n){
	int siguienteUsuario = cajas[n].desencolar();
    return siguienteUsuario;
}

bool Supermercado::cajaVacia(int n){
	if(cajas[n].estaVacia()){
        return true;
    }else{
		return false;
    }
}