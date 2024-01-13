#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){
    
    int num=0;
    int resultado=0;

    num=atoi(argv[1]);  //pasa de una cadena a int

    if((num%2)!=0){   //si el numero es impar
        for(int i=1; i<=num; i+2){  //incremenda de 2 en 2
            resultado+=i;   //le suma al resultado el valor del incremento
        }
    }else if((num%2)==0){  //si es par hace lo mismo que impar pero el incremento empieza en 0
        for(int i=0; i<=num; i+2){
            resultado+=i;
        }
    }

    printf("%d\n", resultado);

    return 0;
}