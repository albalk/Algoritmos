#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}



//Constructores
Matriz::Matriz(){
  this->n_filas=0;
  this->n_columnas=0;
  matriz=NULL;
}

Matriz::Matriz(int n_filas, int n_columnas){
  this->n_filas=n_filas;
  this->n_columnas=n_columnas;

  assertdomjudge((this->n_filas != 0)&&(this->n_columnas != 0));

  //reserva de memoria
  this->matriz = new double*[n_filas];
  for(int i=0; i<n_filas; i++){
    matriz[i] = new double [n_columnas];
  }

}

Matriz::Matriz(const Matriz &matrizOriginal){
  this->n_filas=matrizOriginal.n_filas;
  this->n_columnas=matrizOriginal.n_columnas;

  //assertdomjudge((this->matriz != NULL)&&(this->n_filas != 0)&&(this->n_columnas != 0));

  //reserva de memoria
  this->matriz = new double*[matrizOriginal.n_filas];
  for(int i=0; i<n_filas; i++){
    matriz[i] = new double [matrizOriginal.n_columnas];
  }

  //copiar elementos
  for(int i=0; i<this->n_filas; i++){
    for(int j=0; j<this->n_columnas; j++){
      matriz[i][j]=matrizOriginal.matriz[i][j];
    }
  }

}

//Destructor
Matriz::~Matriz(){

  assertdomjudge(this->matriz != NULL);

  for(int i=0; i<this->n_filas; i++){
    delete[] this->matriz[i];
  }
  delete[] matriz;
}

//Operador suma
Matriz& Matriz::operator + (Matriz matriz1){
  Matriz* resultado = new Matriz(n_columnas, n_filas);

  assertdomjudge((this->n_filas == matriz1.n_filas)&&(this->n_columnas == matriz1.n_columnas));
  
  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      resultado->matriz[i][j]=this->matriz[i][j] + matriz1.matriz[i][j];
    }
  }
  
  return *resultado;
}

//Operador resta
Matriz& Matriz::operator - (Matriz matriz1){
  Matriz* resultado = new Matriz(n_columnas, n_filas);

  assertdomjudge((this->n_filas == matriz1.n_filas)&&(this->n_columnas == matriz1.n_columnas));
    
  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      resultado->matriz[i][j]=this->matriz[i][j] - matriz1.matriz[i][j];
    }
  }
  
  return *resultado;
}

//Operador producto escalar
Matriz& Matriz::operator * (int num){
  Matriz* resultado = new Matriz(n_columnas, n_filas);

  assertdomjudge(this->matriz != NULL);

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      resultado->matriz[i][j]=this->matriz[i][j] * num;
    }
  }

  return *resultado;
}

//Operador producto por una matriz
Matriz& Matriz::operator * (Matriz &matriz1){
  Matriz *resultado = new Matriz(this->n_filas, matriz1.n_columnas);

  assertdomjudge(this->n_columnas == matriz1.n_filas);

  //si tienen dimensiones compatibles se opera
    for(int i=0; i<this->n_filas; i++){
      for(int j=0; j<matriz1.n_columnas; j++){
        resultado->matriz[i][j] = 0; //lo inicializo primero
        for(int k=0; k<this->n_columnas; k++){ //en cada casilla hace el sumatorio de los valores de la fila n por la columna n
          resultado->matriz[i][j] += this->matriz[i][k] * matriz1.matriz[k][j];
        }
      }
    }

  return *resultado;
}

//calcular traspuesta
Matriz& Matriz::calcularTraspuesta(){
  Matriz* traspuesta = new Matriz(n_columnas, n_filas);

  //assertdomjudge(this->matriz != NULL);

  for(int i=0; i<this->n_filas; i++){
    for(int j=0; j<this->n_columnas; j++){
      traspuesta->matriz[j][i]=this->matriz[i][j];
    }
  }

  return *traspuesta;
}

//es simetrica
bool Matriz::esSimetrica(){
  bool resultado=true;

  assertdomjudge(this->n_columnas == this->n_filas);

  //si es cuadrada puede ser simétrica
  //if(this->n_filas == this->n_columnas){
    //recorrer matriz
    for(int i=0; i<this->n_filas; i++){
      for(int j=0; j<this->n_columnas; j++){
        if(this->matriz[i][j] != matriz[j][i]){ //comprueba si son distintas
          resultado=false;
        }
      }
    }
  //}else{
    //resultado=false;
  //}

  return resultado;
}

double Matriz::obtenerMaximo(){
  
  assertdomjudge(this->matriz != NULL);
  
  double max=this->matriz[1][1]; //se inicializa al primer valor para coger uno por defecto
  //recorre la matriz
  for(int i=0; i<this->n_filas; i++){
      for(int j=0; j<this->n_columnas; j++){
        //si un valor es mayor a max, se actualiza con el valor nuevo
        if(this->matriz[i][j]>max){
          max=this->matriz[i][j];
        }
      }
  }

  return max;
}

double Matriz::obtenerMinimo(){

  assertdomjudge(this->matriz != NULL);

  double min=this->matriz[1][1]; //se inicializa al primer valor para coger uno por defecto
  //recorre la matriz
  for(int i=0; i<this->n_filas; i++){
      for(int j=0; j<this->n_columnas; j++){
        //si un valor es menor a min, se actualiza con el valor nuevo
        if(this->matriz[i][j]<min){
          min=this->matriz[i][j];
        }
      }
  }

  return min;
}


////////////////////////NO EDITAR///////////////////////////////////////////

//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    this->matriz[i][j]=m.matriz[i][j];
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
	  cout << "Elemento " << j  << endl;
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
      matriz[i][j]=rand();
  
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

