#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "conversionBinario.h"

int main() {
    //todo hacer maquina de turing para verificar que es correcta la entrada.
    //todo diseñar la multiplicación de binarios con respecto a el retorno de conversiónBinario.h

    bool sesion = true;
    char entrada[20] = "", simbolo[] = "x";
    unsigned int arregloBin[100];
    unsigned int index = 0;
    unsigned int int1 = 0, int2 = 0;
    printf("Este programa realiza una multiplicaci%cn de dos n%cmeros naturales a trav%cs ", 162, 163, 130);
    printf("del algoritmo de Maquina de Turing\n");
    printf("Se debe ingresar la multiplicaci%cn a realizar con el formato \"nxn\", donde \"n\" ser%c un n%cmero ", 162,
           160, 163);
    printf("entero y \"x\" funcionar%c como s%cmbolo de multiplicaci%cn\n", 160, 161, 162);


    //todo diseñar la maquina de Turing para que antes de evaluar
    // los números verifique si la entrada es correcta
    while (sesion) {
        printf("Ingrese la multiplicaci%cn que desea realizar\n", 162);
        scanf("%s", entrada);
        char *token = strtok(entrada, simbolo);
        printf("Numero = %s\n", token);
        arregloBin[index] = conversionBinario(atoi(token));
        index++;

        while ((token = strtok(NULL, simbolo)) != NULL) {
            printf("Numero = %s\n", token);
            //todo transformarlo a binario
            //todo almacenamos en el arreglo (si lo usamos)
            arregloBin[index] = conversionBinario(atoi(token));
            index++;
            //printf("Token %s\n",token);
            //token = strtok(NULL, simbolo);
            //printf("Numero = %s\n", token);
            //int2 = atoi(token);
        }
        for (int i = 0; i < index/*longitud arreglo*/; i++) {
            printf("Binario [ %d ] = %d\n", i + 1, arregloBin[i]);
        }
        // todo Multiplicarlo
        for (int i = 0; i < index; ++i) {
            //todo mandar por parejas los datos del arreglo
            /*
             * num1 = a[0] = 101
             * num2 = a[1] = 111
             * arreglo[]= funcionMultiplicación(a[i],a[i++]); // no c puede con impares
             * num1  = return multiplicacion
             * num2 = a[2];
             * */
        }

        sesion = false;

        return 0;
    }

}