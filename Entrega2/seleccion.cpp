#include<iostream>
using namespace std;

/* Recorre el array, encuentra el menor valor y lo pone en la posición x[i], incrementa x y busca el siguiente 
	   Precondicion: 
     Complejidad temporal: T(n)=n^2 +1
	   Complejidad Temporal: O(n^2)
	   Complejidad Espacial: O(1)

*/

void ordenarSeleccion(int x[],int len)
{
  int aux1=0;
  int aux2=0;

  for(int i=0;i<len;i++){
    /*Añadir código de ordenar mediante selección */
    aux1=x[i];  //valor de la posición
    aux2=i;     //posición

    for(int j=i+1; j<len; j++){ //recorre el array
      //encuentra el valor menor posible
      if(x[j]<aux1){  //si el valor de la posición actual es menor que la inicial
        aux1=x[j];  //se actualiza el valor menor
        aux2=j;     //y su posición
      }
    }
    //intercambia los valores
    x[aux2]=x[i];
    x[i]=aux1;

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
 ordenarSeleccion(x,n);
}

