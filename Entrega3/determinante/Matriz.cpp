#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
//#include "..\..\..\..\Downloads\Matriz.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//constructor por defecto:
Matriz::Matriz()
{
    this->n_filas = 0;
    this->n_columnas = 0;
    matriz = NULL;
}

//Constructor por parametros:
Matriz::Matriz(int n_filas, int n_columnas)
{
    this->n_columnas = n_columnas;
    this->n_filas = n_filas;

    //Reserva de memoria
    this->matriz = new double* [n_filas];

    for (int i = 0; i < n_filas; i++)
    {
        matriz[i] = new double[n_columnas];
    }
}

//Borrar matriz
Matriz::~Matriz() {
    for (int i = 0; i < n_filas; i++)
    {
        delete[] this->matriz[i];
    }

    delete[]  matriz;
}

//Constructor matrizCopia:

Matriz::Matriz(const Matriz& OriginalMatriz)
{
    this->n_columnas = OriginalMatriz.n_columnas;
    this->n_filas = OriginalMatriz.n_filas;

    //Reserva de memoria
    this->matriz = new double* [OriginalMatriz.n_filas];

    for (int i = 0; i < n_filas; i++)
    {
        matriz[i] = new double[OriginalMatriz.n_columnas];
    }

    //copia de matrices
    for (int i = 0; i < this->n_filas; i++) {
        for (int j = 0; j < this->n_columnas; j++) {
            matriz[i][j] = OriginalMatriz.matriz[i][j];
        }
    }
}

//Operador de suma de matrices
Matriz& Matriz::operator+ (const Matriz& matrizEntrada)
{
    Matriz* solucion = new Matriz(n_columnas, n_filas);

    assertdomjudge((matrizEntrada.n_filas == this->n_filas) && (matrizEntrada.n_columnas == this->n_columnas));

    if ((matrizEntrada.n_filas == this->n_filas) || (matrizEntrada.n_columnas == this->n_columnas))
    {
        for (int i = 0; i < n_filas; i++) {
            for (int j = 0; j < n_columnas; j++) {
                solucion->matriz[i][j] = matrizEntrada.matriz[i][j] + this->matriz[i][j];
            }
        }
    }

    return *solucion;
}

//Operador de resta de matrices
Matriz& Matriz::operator- (const Matriz& matrizEntrada)
{
    Matriz* solucion = new Matriz(n_columnas, n_filas);

    assertdomjudge((matrizEntrada.n_filas == this->n_filas) && (matrizEntrada.n_columnas == this->n_columnas));

    if ((matrizEntrada.n_filas == this->n_filas) || (matrizEntrada.n_columnas == this->n_columnas))
    {
        for (int i = 0; i < n_filas; i++) {
            for (int j = 0; j < n_columnas; j++) {
                solucion->matriz[i][j] = this->matriz[i][j] - matrizEntrada.matriz[i][j];
            }
        }
    }

    return *solucion;
}

//Operador producto escalar de matrices
Matriz& Matriz::operator* (const double num)
{
    static Matriz solucion;

    solucion.n_columnas = n_columnas;
    solucion.n_filas = n_filas;

    //Reserva de memoria
    solucion.matriz = new double* [n_filas];

    for (int i = 0; i < n_filas; i++)
    {
        solucion.matriz[i] = new double[n_columnas];
    }


    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++) {
            solucion.matriz[i][j] = this->matriz[i][j] * num;
        }
    }

    return solucion;
}

//Operador producto de dos matrices
Matriz& Matriz::operator* (const Matriz& matrizEntrada)
{
    Matriz* solucion = new Matriz(this->n_filas, matrizEntrada.n_columnas);

    assertdomjudge(this->n_columnas == matrizEntrada.n_filas);


    for (int i = 0; i < this->n_filas; i++) {
        for (int j = 0; j < matrizEntrada.n_columnas; j++) {
            solucion->matriz[i][j] = 0;
            for (int k = 0; k < this->n_columnas; k++) {
                solucion->matriz[i][j] += this->matriz[i][k] * matrizEntrada.matriz[k][j];
            }
        }
    }



    return *solucion;
}

//Obetener el maximo de la matriz
double Matriz::obtenerMaximo()
{
    double resultado = 0.0;

    for (int i = 0; i < n_filas; i++)
    {
        for (int j = 0; j < n_columnas; j++)
        {
            if (resultado < matriz[i][j])
            {
                resultado = this->matriz[i][j];
            }
        }
    }
    return resultado;
}

//Obetener el maximo de la matriz
double Matriz::obtenerMinimo()
{
    double resultado = 0.0;

    resultado = this->matriz[0][0];

    for (int i = 0; i < n_filas; i++)
    {
        for (int j = 0; j < n_columnas; j++)
        {
            if (resultado > matriz[i][j])
            {
                resultado = this->matriz[i][j];
            }
        }
    }
    return resultado;
}


// Calcular determinante
double Matriz::calcularDeterminante() {
    double resultado = 0;

    if (n_filas == 1) {
        return matriz[0][0];
    } 

    assertdomjudge(n_columnas == n_filas);
    Matriz* matriz1 = new Matriz(n_filas - 1, n_columnas - 1);

    for (int aux=0; aux < n_columnas; aux++){
        for (int j = 0; j<matriz1->n_filas; j++){
            for (int k=0; k < matriz1->n_columnas; k++){
                if (k < aux){
                    matriz1->matriz[j][k] = matriz[j + 1][k];
                }else{
                    matriz1->matriz[j][k] = matriz[j + 1][k + 1];
                }
            }
        }

        if ((aux % 2) == 0) {
            resultado += matriz[0][aux] * matriz1->calcularDeterminante();
        }else {
            resultado -= matriz[0][aux] * matriz1->calcularDeterminante();
        }
    }

    return resultado;
}





//Devuelve un bool en funcion de que sea simetrica o no
bool Matriz::esSimetrica()
{
    bool resultado = true;
    for (int i = 0; i < n_filas; i++)
    {
        for (int j = 0; j < n_columnas; j++)
        {
            if (matriz[i][j] != matriz[j][i])
            {
                return false;
            }
        }
    }

    return resultado;
}

Matriz& Matriz::calcularTraspuesta()
{
    Matriz* resultado = new Matriz(n_columnas, n_filas);

    for (int i = 0; i < this->n_filas; i++)
    {
        for (int j = 0; j < this->n_columnas; j++)
        {
            resultado->matriz[j][i] = this->matriz[i][j];
        }
    }
    return *resultado;
}

//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz& m)
{
    if (matriz != NULL)
    {
        for (int i = 0; i < n_filas; i++)
            delete[] matriz[i];

        delete[] matriz;
        matriz = NULL;
    }

    this->n_filas = m.n_filas;
    this->n_columnas = m.n_columnas;
    this->matriz = NULL;
    if (n_filas > 0 && n_columnas > 0)
    {
        matriz = new double* [n_filas];

        for (int i = 0; i < n_filas; i++)
        {
            matriz[i] = new double[n_columnas];
            for (int j = 0; j < n_columnas; j++)
                matriz[i][j] = m.matriz[i][j];
        }
    }

    return(*this);
}


// Leer matriz
void Matriz::rellenarManual()
{
    double elemento;
    for (int i = 0; i < n_filas; i++)
    {
        cout << "Fila " << i << endl;
        for (int j = 0; j < n_columnas; j++)
        {
            cout << "Elemento " << j << endl;
            cin >> elemento;
            matriz[i][j] = elemento;
        }
        cout << endl;
    }

}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
    srand(seed);
    for (int i = 0; i < n_filas; i++)
        for (int j = 0; j < n_columnas; j++)
            matriz[i][j] = rand();

}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
    for (int i = 0; i < n_filas; i++)
    {
        for (int j = 0; j < n_columnas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}


/*double Matriz::calcularDeterminante()
{
    int resultado = 0;

    return resultado;
}*/