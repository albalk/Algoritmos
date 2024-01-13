#include<iostream>
using namespace std;

/* Compara el valor de x[i] y lo compara con el siguiente valor, si es menor, los intercambia y repite el proceso
	   Precondicion: Ninguna
     Complejidad temporal: T(n)=n^2 + n/2 +1
	   Complejidad Temporal: O(n^2)
	   Complejidad Espacial: O(1)

*/

void ordenarInsercion(int x[],int len)
{
  int aux=0;
  int j=0;

  for(int i=1;i<len;i++){
    /*Añadir código de ordenación mediante inserción*/
    aux=x[i];
    j=i-1; //la posición anterior del array

    while((j>=0)&&(x[j]>aux)){ //se desplaza a la izquierda y busca el valor menor
      x[j+1]=x[j];  //
      j-=1;  //decrece j en 1
    }

    x[j+1]=aux; //actualiza el valor
    
    /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
      cout<<endl;
  }  
}


int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarInsercion(x,n);
}


