#include "ColaPrioridad.h"
#include "assertdomjudge.h"
#include "iostream"
using namespace std;

ColaPrioridad::ColaPrioridad(){
	this->vector= ListaContigua();
}

void ColaPrioridad::encolar(int nuevoElemento){
    //inserta el cliente al final de la cola
    this->vector.insertar(vector.getN(), nuevoElemento);

	int posicion = vector.getN();
    //mientras no lleguemos a la raiz y sea mayor que su padre
	while (posicion>1 && vector.getValor(posicion-1)<vector.getValor(posicion/2-1)){
		int aux = vector.getValor(posicion / 2 - 1);
		vector.setValor(posicion / 2 - 1, vector.getValor(posicion - 1));   //intercambiar con el padre
		vector.setValor(posicion - 1, aux);
		posicion/= 2;
	}
}

int ColaPrioridad::desencolar(){
    assertdomjudge(vector.getN() > 0);

	int primerElemento = vector.getValor(0);
	int ultimoElemento = vector.getValor(vector.getN() - 1);  

	vector.setValor(0, ultimoElemento); //cambia el primer elemento por el último
	vector.eliminar(vector.getN() - 1); //eliminar el ultimo elemento de la cola

	if (vector.getN() >= 2){
        reestructurar();
    }

	return primerElemento;
}

bool ColaPrioridad::estaVacia(){
    if(this->vector.getN() == 0){
        return true;
    }else{
        return false;
    }
}

void ColaPrioridad::reestructurar(){
    int n = vector.getN();

	assertdomjudge(n >= 2);

	bool reestructurado = false;
	int posicionPadre = 1;

	while (reestructurado==false){
		int valorHijo;
		int posicionHijo;
		int valorPosicion = vector.getValor(posicionPadre-1);

		if ((posicionPadre*2 +1) > n){
            posicionHijo = posicionPadre * 2;
        }else{
			int valorHijoIzq = vector.getValor(posicionPadre * 2 - 1);
			int valorHijoDer = vector.getValor(posicionPadre * 2);

			if (valorHijoIzq < valorHijoDer){
                posicionHijo = posicionPadre*2;
            }else{
                posicionHijo = posicionPadre*2 + 1;
            }
		}

		valorHijo=vector.getValor(posicionHijo-1);

		if (valorPosicion > valorHijo){
			vector.setValor(posicionPadre-1, valorHijo);
			vector.setValor(posicionHijo-1, valorPosicion);

			posicionPadre = posicionHijo;

			if (posicionPadre > n/2){
                reestructurado = true;
            }
		}else{
            reestructurado = true;
        }
			
	}
}