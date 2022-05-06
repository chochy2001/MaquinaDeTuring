#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "conversionBinario.h"

int main() {
    //todo hacer maquina de turing para verificar que es correcta la entrada.

    bool sesion = true;
    char entrada[20] = "", simbolo[] = "xX*";
    int int1 = 0, int2 = 0;
    printf("Este programa realiza una multiplicaci%cn de dos n%cmeros naturales a trav%cs ", 162, 163, 130);
    printf("del algoritmo de Maquina de Turing\n");
    printf("Se debe ingresar la multipolicaci%cn a realizar con el formato \"nxn\", donde n ser%c un n%cmero ", 162, 160, 163);
    printf("entero y \"x\" funcionar%c como s%cmbolo de multiplicaci%cn\n", 160, 161, 162);


    printf("Conversion de 5 a binario = %d\n", conversionBinario( 123));
    //todo diseñar la maquina de Turing para que antes de evaluar los números verifique si la entrada es correcta
    while(sesion){
        printf("Ingrese la multiplicaci%cn que desea realizar\n", 162);
        scanf("%s", entrada);
        char *token = strtok(entrada, simbolo);
        printf("Numero = %s\n", token);
        int1 = atoi(token);
        //printf("Numero almacenado: %d\n" , int1);
        //todo hacer int1 = token;
        //todo mandar el numero para transformarlo a binario
        token = strtok(NULL, simbolo);
        printf("Numero = %s\n", token);
        //todo en lugar de imprimirlo, almacenarlo y transformarlo a Bin
        // Multiplicarlo
        
        sesion = false;

    }

    return 0;
}

