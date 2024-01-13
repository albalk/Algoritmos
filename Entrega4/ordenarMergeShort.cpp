#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ]){
  /*Añadir código que permite combinar dos arrays */
  int i_a=0;
  int i_b=0;
  int i_c=0;

  while((i_a < len_a)&&(i_b < len_b)){
    if(a[i_a] <= b[i_b]){
      c[i_c]=a[i_a];
      i_c++;
      i_a++;
    }else{
      c[i_c]=b[i_b];
      i_c++;
      i_b++;
    }
  }

  //si a[] se termina antes que b
  while(i_b < len_b){
    c[i_c]=b[i_b];
    i_c++;
    i_b++;
  }

  //si b[] se termina antes que a
  while(i_a < len_a){
    c[i_c]=a[i_a];
    i_c++;
    i_a++;
  }

}


void ordenarMergeSort (int x[], int len){
  int *temp= new int[len];
  if(len<=1){ /*caso básico */
    return;
  }else{
    int mitad=len/2;

    /*int *izquierda = new int[mitad];
    int *derecha = new int [len-mitad];

    //copia los datos en dos mitades
    for(int i=0; i<mitad; i++){
      izquierda[i]=x[i];
    }
    
    for(int i=0; i<len-mitad; i++){
      derecha[i]=x[i+mitad];
      
    }*/

    /*Ordenar dos mitades */
    ordenarMergeSort(&x[0], mitad);
    ordenarMergeSort(&x[mitad], len-mitad);

    /*Combinar ambas mitades y guardarlo en temp */
    combinar(&x[0], mitad, &x[mitad], len-mitad, temp);


    /*Copiar del array temporal al array resultado */
    for (int k = 0; k < len; k++){
      x[k] = temp[k];
      cout<<x[k]<<" ";
    }
    cout<<endl;
  }
}



int main(){
  int n; //len
  cin>>n;
  int *x=new int[n];
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  ordenarMergeSort(x,n); //array y len
}