#include<iostream>
using namespace std;

/* Compara lod valores x[i] y x[i+1], si el segundo es menor que el primero, los intercambia
	   Precondicion: Ninguna
     Complejidad temporal: T(n)= n^2 +1
	   Orden complejidad Temporal: O(n^2)
	   Complejidad Espacial: O(1)

*/

void ordenarBurbuja(int x[],int len)
{
  int aux=0;

  for(int i=1;i<len;i++){
    /*Añadir código de ordenación usando algoritmo de burbuja*/
    for(int j=0; j<len-1; j++){
      if(x[j] > x[j+1]){
        aux=x[j]; //guarda el valor mayor en la auxiliar
        x[j]=x[j+1];  //intercambia los valores de x[i](mayor) e x[i+1](menor)
        x[j+1]=aux;
      }
    }

  /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
      cout<<endl;
  }  
}


int main(){
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarBurbuja(x,n);
}
