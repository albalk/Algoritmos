#include<iostream>
using namespace std;

int main(){
    int n=0;
    int r;
    int **matriz = new int*[10];
    int resultado=0;

    //reserva de memoria
    for(int i=0; i<10; i++){
        matriz[i] = new int[i];
    }

    //inicializar
    for(int i=0; i<10; i++){    //filas
        for(int j=0; j<(i+1); j++){ //columnas
            
            if(j==0){   //el primero de cada fila siempre es 1
                matriz[i][j]=1;
            }else if (j==i){    //el ultimo de cada fila siempre es 1
                matriz[i][j]=1;
            }else{
                matriz[i][j]=matriz[i-1][j] + matriz[i-1][j-1]; //suma los dos resultados por encima
            }
            
            //cout<<matriz[i][j]<<" ";
        }
        //cout<<endl;
    }

    while(n>=0){
        cin>>n;
        cin>>r;

        if(n>0){
           if(n<r){
                cout<<"ERROR"<<endl;
            }else{
                resultado=matriz[n][r];
                cout<<resultado<<endl;
            } 
        }
        
    }

    return 0;
}