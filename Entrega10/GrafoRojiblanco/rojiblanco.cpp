#include "iostream"
#include "Cola.h"
//#include "Nodo.h"
using namespace std;

bool colorear(int* color_nodo, bool** aristas, int n_aristas, int n_nodos);
void rellenarGrafo(int* color_nodo, bool** aristas, int n_aristas, int n_nodos);


int main(int argc, char const *argv[]){
    int n_nodos, n_aristas;
    cin>>n_nodos;

    while(n_nodos>0){
        cin>>n_aristas;

        bool** aristas;
        int* color_nodo;

        aristas= new bool*[n_nodos];
        color_nodo = new int[n_nodos];

        for(int i=0; i<n_nodos; i++){
            aristas[i]=new bool [n_nodos];
            color_nodo[i]=-1;
            for(int j=0; j<n_nodos; j++){
                aristas[i][j]=false;
            }
        }

        rellenarGrafo(color_nodo, aristas, n_aristas, n_nodos);
        bool esBipartito = colorear(color_nodo, aristas, n_aristas, n_nodos);

        delete[] color_nodo;
        for(int i=0; i<n_nodos; i++){
            delete[] aristas[i];
        }
        delete[] aristas;

        if(esBipartito==true){
            cout<<"SI"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

        cin>>n_nodos;

    }
}

bool colorear(int* color_nodo, bool** aristas, int n_aristas, int n_nodos){
    int origen=0;
    Cola cola;

    color_nodo[origen] =0;

    cola.encolar(origen);

    while(!cola.estaVacia()){
        origen=cola.desencolar();

        for(int destino=0; destino<n_nodos; destino++){
            if(aristas[origen][destino]){
                if(color_nodo[destino]==-1){
                    color_nodo[destino]=1- color_nodo[origen];
                    cola.encolar(destino);
                }else if(color_nodo[destino] == color_nodo[origen]){
                    return false;
                }
            }
        }
    }

    //no hace falta
    for(int i=0; i<n_nodos; i++){
        if(color_nodo[i]==-1){
            return false;
        }
    }

    return true;
}

void rellenarGrafo(int* color_nodo, bool** aristas, int n_aristas, int n_nodos){
    int a,b;

    for(int i=0; i<n_aristas; i++){
        cin>>a;
        cin>>b;

        aristas[a][b]=true;
        aristas[b][a]=true;
    }
}

