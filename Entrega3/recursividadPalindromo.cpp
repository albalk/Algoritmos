#include<iostream>
#include<string.h>
using namespace std;

int i=0;
int j=0;

bool esPalindromo(char palabra[], int tam, int j){

    if(palabra[j] == palabra[tam-1-j]){
        i++;
        if(i==tam/2){
            return 1;
        }
        return(esPalindromo(palabra,tam,j+1));
    }else{
        return 0;
    }

    return false;
}


int main(){
  char palabra[20];
  int tam;
  cin>>palabra;
  tam=strlen(palabra);
  
    if(tam>0){
        cout<< esPalindromo(palabra, tam, j)<< endl;
    }

    return 0;
  
}