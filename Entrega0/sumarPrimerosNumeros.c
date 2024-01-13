#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){

    int sumatorio=0;
    int num=0;
    num=atoi(argv[1]); //pasa de cadena a int

    for(int i=0; i<=num; i++){
        sumatorio+=i;
    }

    printf("%d \n", sumatorio);

    return 0;
}