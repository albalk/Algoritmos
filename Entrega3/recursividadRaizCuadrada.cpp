#include<iostream>
#include<math.h>
using namespace std;

void raizCuadrada(double cuadrado, double error, double inicio, double original){
  double media=(cuadrado+inicio)/2;  //la mitad de la raiz (media)
  double raiz=media;  /*Este es el valor que se debe imprimir en cada llamada a la funcion. Teneis que calcularlo*/
  cout<<raiz<<endl;
  double resultado=raiz*raiz;  //el resultado de la mitad de la raiz al cuadrado

  if((abs(resultado-original))>error){
    if(resultado>original){
      raizCuadrada(media, error, inicio, original);
    }else if(resultado<original){
      raizCuadrada(cuadrado, error, media, original);
    }
  }  

}


int main(){
  double cuadrado;
  double error;
  double inicio=0;
  cin>>cuadrado;
  double original=cuadrado; //como el valor de cuadrado cambia por la recursividad, me guardo el valor original
  cin>>error;
  if(cuadrado>0 && error>0)
    raizCuadrada(cuadrado, error, inicio, original);
  else
    cout<<"ERROR"<<endl;
  
  return 0;
  
}
