#include "ListaEnlazada.h"
#include<string>
#include<iostream>
using namespace std;

class Agenda{
    private:
    int capacidad;
	int n;
	ListaEnlazada* tabla;

    public:
    Agenda(int capacidad);
	~Agenda();
	int obtenerPosicion(long telefono);
	bool existeContacto(long telefono);
	string getContacto(long telefono);
	void introducirContacto(long telefono, string contacto);
	void eliminarContacto(long telefono);
	void imprimir();

};