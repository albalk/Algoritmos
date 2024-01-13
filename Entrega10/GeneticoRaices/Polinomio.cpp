#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal est�ndar se puede calcular o bien con "normal_distribution" de la biblioteca "random" (versi�n 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego rest�ndole 6. M�s detalles sobre este m�todo en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no est�ndar recordemos que ser�a X = media + desviaci�n*Z, donde Z es la normal est�ndar

	float suma=0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i=0; i<12; i++) suma = suma + rand()/(float)RAND_MAX;
	return(suma-6);	
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {

	// Imprimimos el padre
        cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	// Calculamos la mutaci�n para cada hijo (10)  y evaluamos el polinomio para dicha mutaci�n
	// Imprimimos la solucion parcial encontrada para las mutaciones (hijo.imprimir()
	// Elegimos el mejor hijo de numeroHijos
	
	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado
	float mutacionHijos[10];
	SolucionParcial mutacionesHijos[10];
	SolucionParcial mejorHijo;

	for (int i=0; i<10; i++){
		mutacionHijos[i] = obtenerAleatorioNormalEstandar();//obtengo la mutaci�n de cada hijo
		mutacionesHijos[i].x = padre.x+mutacionHijos[i];
		mutacionesHijos[i].y = evaluar(mutacionesHijos[i].x);
		mutacionesHijos[i].imprimir();

		if (i==0){
			mejorHijo.x = mutacionesHijos[i].x;
			mejorHijo.y = mutacionesHijos[i].y;
		}

		if (i>0){
			if ((mutacionesHijos[i].y > 0) && (mejorHijo.y > 0) && (mutacionesHijos[i].y < mejorHijo.y)){
				mejorHijo.x = mutacionesHijos[i].x;
				mejorHijo.y = mutacionesHijos[i].y;
			}

			if ((mutacionesHijos[i].y > 0) && (mejorHijo.y < 0) && ((mutacionesHijos[i].y *(-1)) > mejorHijo.y)){
				mejorHijo.x = mutacionesHijos[i].x;
				mejorHijo.y = mutacionesHijos[i].y;
			}

			if ((mutacionesHijos[i].y < 0) && (mejorHijo.y > 0) && ((mutacionesHijos[i].y *(-1)) < mejorHijo.y)){
				mejorHijo.x = mutacionesHijos[i].x;
				mejorHijo.y = mutacionesHijos[i].y;
			}
			
			if ((mutacionesHijos[i].y < 0) && (mejorHijo.y < 0) && ((mutacionesHijos[i].y) > mejorHijo.y)){
				mejorHijo.x = mutacionesHijos[i].x;
				mejorHijo.y = mutacionesHijos[i].y;
			}
		}
	}

	if ((mejorHijo.y > 0) && (padre.y > 0) && (mejorHijo.y > padre.y)){
		return padre.x;
	}
		
	if ((mejorHijo.y > 0) && (padre.y < 0) && ((mejorHijo.y * (-1)) < padre.y)){
		return padre.x;
	}
		
	if ((mejorHijo.y < 0) && (padre.y > 0) && ((mejorHijo.y * (-1)) > padre.y)){
		return padre.x;
	}
		
	if ((mejorHijo.y < 0) && (padre.y < 0) && (mejorHijo.y < padre.y)){
		return padre.x;
	}
		
	return obtenerRaizRecursivo(mejorHijo);
	
}

Polinomio::Polinomio(int n, float *coeficientes) {
	assert(n>=0);
	this->n = n;
	this->coeficientes = new float[n+1];
	for (int i=0; i<n+1; i++){
		this->coeficientes[i] = coeficientes[i];
	}
		
}

float Polinomio::evaluar(float x) {
	float resultado = 0;
	for (int i=0; i<=n; i++){
		resultado += coeficientes[i] * pow(x,i);
	}
		
	return resultado;
}


float Polinomio::obtenerRaiz() {
	SolucionParcial padre;
	padre.x = 0;
	padre.y = evaluar(padre.x);
	return obtenerRaizRecursivo(padre);
}


Polinomio::~Polinomio() {
	delete coeficientes;
}
