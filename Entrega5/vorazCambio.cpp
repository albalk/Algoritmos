#include<iostream>
using namespace std;

int main(){
    int inicial=0;
    int resultado[8]= {0,0,0,0,0,0,0,0};
    int pesetas[8]={500, 200, 100, 50, 25, 10, 5, 1};
    
    while(inicial>=0){
        cin>>inicial;

        for(int i=0; i<8; i++){
            resultado[i]=0;
        }

        for(int i=0; i<8; i++){ //8 tipos de moneda
            //mientras el valor dado sea mayor que el valor de las pesetas
            while(inicial>=pesetas[i]){ 
                inicial-=pesetas[i]; //resta el valor de la posición de las pesetas
                resultado[i]+=1;    //incrementa el número de la moneda utilizada
            }
        }

        if(inicial==0){
            for(int i=0; i<8; i++){
                cout<<resultado[i]<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}