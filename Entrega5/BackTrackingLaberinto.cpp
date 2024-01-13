#include <iostream>
#define TAM_LABERINTO 10
using namespace std;


bool comprobarFinal(char laberinto[][TAM_LABERINTO], int posX, int posY,int *checkX, int *checkY){
	if (laberinto[posX][posY] == 'T'){
		*checkX = posX;
		*checkY = posY;
		return true;
	}else{
		return false;
	}
}

bool comprobarMov(char laberinto[][TAM_LABERINTO], int inicioFila, int inicioColumna,char direccion){
	if (direccion == 'N'){			//arriba
		if (laberinto[inicioFila-1][inicioColumna] == '.' || laberinto[inicioFila-1][inicioColumna] == 'T'){
			return true;
		}else{
			return false;
		}
	}else if (direccion == 'E'){	//derecha
		if (laberinto[inicioFila][inicioColumna+1] == '.' || laberinto[inicioFila][inicioColumna+1] == 'T'){
			return true;
		}else{
			return false;
		}
	}else if (direccion == 'S'){	//abajo
		if (laberinto[inicioFila+1][inicioColumna] == '.' || laberinto[inicioFila+1][inicioColumna] == 'T'){
			return true;
		}else{
			return false;
		}
	}else if (direccion == 'W'){	//izquierda
		if (laberinto[inicioFila][inicioColumna-1] == '.' || laberinto[inicioFila][inicioColumna-1] == 'T'){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void imprimir(char laberinto[][TAM_LABERINTO]){
	for (int i = 0; i < TAM_LABERINTO; i++){
		for (int j = 0; j < TAM_LABERINTO; j++){
			cout<<laberinto[i][j];
		}
		cout<<endl;
	}
}

bool calcularCamino(char laberinto[][TAM_LABERINTO], int inicioFila, int inicioColumna, int *checkpointFila, int *checkpointColumna){
	if (comprobarFinal(laberinto, inicioFila, inicioColumna, checkpointFila, checkpointColumna)==true){
		return true;
	}

	laberinto[inicioFila][inicioColumna] = 'X';
	if (inicioFila - 1 < TAM_LABERINTO && inicioFila - 1 >= 0){			//arriba
		if (comprobarMov(laberinto, inicioFila, inicioColumna, 'N') && calcularCamino(laberinto, inicioFila-1, inicioColumna, checkpointFila, checkpointColumna)){
			return true;
		}	
	}

	if (inicioColumna + 1 < TAM_LABERINTO && inicioColumna + 1 >= 0){	//derecha
		if (comprobarMov(laberinto, inicioFila, inicioColumna, 'E') && calcularCamino(laberinto, inicioFila, inicioColumna+1, checkpointFila, checkpointColumna)){
			return true;	
		}
	}

	if (inicioFila + 1 < TAM_LABERINTO && inicioFila + 1 >= 0){			//abajo
		if (comprobarMov(laberinto, inicioFila, inicioColumna, 'S') && calcularCamino(laberinto, inicioFila+1, inicioColumna, checkpointFila, checkpointColumna)){
			return true;
		}
	}

	if (inicioColumna - 1 < TAM_LABERINTO && inicioColumna - 1 >= 0){	//izquierda
		if (comprobarMov(laberinto, inicioFila, inicioColumna, 'W') && calcularCamino(laberinto, inicioFila, inicioColumna-1, checkpointFila, checkpointColumna)){
			return true;
		}
	}

	laberinto[inicioFila][inicioColumna] = '.';
	return false;
}


int main(){
	int solX, solY;
	char laberinto[TAM_LABERINTO][TAM_LABERINTO];

	for (int i=0; i<TAM_LABERINTO; i++){
		for (int j=0; j<TAM_LABERINTO; j++){
			cin >> laberinto[i][j];
		}
	}

	if (calcularCamino(laberinto, 0, 0, &solX, &solY)){
		imprimir(laberinto);
		cout << "ENCONTRADO " << solX << " " << solY << endl;
	}else{
		cout << "INALCANZABLE" << endl;
	}
		
}