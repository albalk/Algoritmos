#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;

 public:
	//constructores

/* Crea una matriz por defecto (0 filas y 0 columnas) 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: Ninguna
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(1)


*/

	Matriz();


/* Crea una matriz con las dimensiones solicitadas y reserva su memoria
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: el numero de filas y columnas debe ser >=0
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	Matriz(int n_filas, int n_columnas);


/* Crea una matriz con las dimensiones de otra matriz y copia sus elementos 
	   Parámetro: La matriz que quieres copiar
	   Retorno: Ninguno
	   Precondicion: La matriz copia no debe de estar vacía y el numero de filas y columnas debe ser >=0
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

	Matriz(const Matriz &matrizOriginal);
	
	//destructor
	
/* Libera la memoria reservada para una matriz 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz tiene que existir y el numero de filas debe ser >=0
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(1)


*/

	~Matriz();

	//operadores

/* Crea una matriz con la suma de los elementos de dos matrices  
	   Parámetro: La matriz que quieres sumar
	   Retorno: La matriz resultado
	   Precondicion: Las dos matrices tienen que tener las mismas dimensiones
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	Matriz& operator + (Matriz matriz1);

/* Crea una matriz con la resta de los elementos de dos matrices 
	   Parámetro: La matriz que quieres restar
	   Retorno: La matriz resultado
	   Precondicion: Las dos matrices tienen que tener las mismas dimensiones
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	Matriz& operator - (Matriz matriz1);


/* Crea una matriz con el resultado de multiplicar una matriz por un número 
	   Parámetro: El número por el que quieres multiplicar la matriz
	   Retorno: La matriz resultado
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

	Matriz& operator * (int num);


/* Crea una matriz con el resultado de multiplicar dos matrices 
	   Parámetro: La matriz que quieres multiplicar
	   Retorno: La matriz resultado
	   Precondicion: Las columnas de la matriz A deben ser igual a las filas de la matriz B
	   Complejidad Temporal: O(n_filas*n_columnas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

	Matriz& operator * (Matriz &matriz1);
	
	//traspuesta

/* Calcula la traspuesta de la matriz (cambia filas por columnas)  
	   Parámetro: Ninguno
	   Retorno: boolean (true=simetrica, false=no simetrica)
	   Precondicion: La matriz no debe de estar vacía (no hace falta que la matriz sea cuadrada)
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

	Matriz& calcularTraspuesta();

	//simetrica

/* Comprueba si la matriz es simétrica o no  
	   Parámetro: Ninguno
	   Retorno: boolean (true=simetrica, false=no simetrica)
	   Precondicion: La matriz debe ser cuadrada
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	bool esSimetrica();

	//maximo y minimo

/* Compara los elementos de la matriz para obtener el de mayor valor  
	   Parámetro: Ninguno
	   Retorno: El valor máximo
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	double obtenerMaximo();


/* Compara los elementos de la matriz para obtener el de menor valor  
	   Parámetro: Ninguno
	   Retorno: El valor mínimo
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

	double obtenerMinimo();


/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  Matriz& operator= (const Matriz &m);


/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();
  
};

#endif // MATRIZ_H
