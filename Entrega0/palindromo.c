#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CADENA 20

int main (int argc, char** argv){
    
    char* palabra=argv[1];
    int tam=strlen(palabra);
    int resultado;

    if(tam>TAM_CADENA){
        printf("Error: la palabra supera el límite de carácteres");
    }else{
        for(int i=0; i<tam/2; i++){
            if(palabra[i]==palabra[tam-i-1]){
                resultado=1;
            }else{
                resultado=0;
                break;
            }
        }
    }

    printf("%d \n", resultado);

    /*for(int i=0; i<strlen(palabra); i++){
        printf("%c", palabra[i]);
    }*/

    return 0;
}