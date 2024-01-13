#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

Pila::Pila(string name){
  this->cima=NULL;
  this->name=name;
}

std::string Pila::nombrePila(){
  return name;
}

void Pila::apilar(int num){

  Nodo* siguienteNodo = NULL;
	string name = nombrePila();
	
  if (estaVacia()==true){
		Nodo* siguienteCima = new Nodo(num,siguienteNodo);
		cima = siguienteCima;
	}else{
		assertdomjudge(num<cima->valor);
		Nodo* anteriorCima = cima;  //enlazar nodos
		Nodo* siguienteCima = new Nodo(num,siguienteNodo);
		siguienteCima->siguiente = anteriorCima;
		cima = siguienteCima;
	}

  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}
  
int Pila::desapilar(){    

  assertdomjudge(estaVacia()!=true);
	int num = cima->valor;
	string name = nombrePila();

	Nodo* anteriorCima = NULL;
	Nodo *siguienteCima = cima->siguiente;
  //enlazar nodos
	anteriorCima = cima;
	delete(anteriorCima);
	cima = siguienteCima;

	cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;
	
  return num;
}

bool Pila::estaVacia(){
  if(cima==NULL){
	  return true;
	}else{
		return false;
  }
}

