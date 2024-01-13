#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

void Hanoi(int n,Pila *origen,Pila *destino,Pila *temporal) {
    
    if(n==0){ //si no hay discos
      return;
    }

    Hanoi(n - 1, origen, temporal, destino);
    destino->apilar(origen->desapilar());
    Hanoi(n - 1, temporal, destino, origen);
  
}


int main()
{  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;

  assertdomjudge(n!=0);

  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,C,B);
  
  for(int i=0;i<n;i++)
    C->desapilar();

  return 0;
  
}

