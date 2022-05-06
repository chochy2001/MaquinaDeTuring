#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "conversionBinario.h"

int main() {

    bool sesion = true;
    char entrada[20] = "", simbolo = 'xX';
    printf("Este programa realiza una multiplicaci%cn de dos n%cmeros naturales a trav%cs ", 162, 163, 130);
    printf("del algoritmo de Maquina de Turing\n");
    printf("Se debe ingresar la multipolicaci%cn a realizar con el formato \"nxn\", donde n ser%c un n%cmero ", 162, 160, 163);
    printf("entero y \"x\" funcionar%c como s%cmbolo de multiplicaci%cn\n", 160, 161, 162);

    printf("Conversion de 5 a binario = %d", conversionBinario((int *) 5));
   /* while(sesion){
        printf("Ingrese la multiplicaci%cn que desea realizar\n", 162);
        scanf("%s", entrada);
        char *token = strtok(entrada, simbolo);
        



    }*/

    return 0;
}

