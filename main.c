#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "conversionBinario.h"
#include "multiplicacionBinario.h"
#include "conversionEntero.h"

static long arregloBinario[100];
long contador = 0;
long multiplicacionRecursiva( long a, long b);

int main() {
    //todo hacer maquina de turing para verificar que es correcta la entrada.
    //todo diseñar la multiplicación de binarios con respecto a el retorno de conversiónBinario.h

    bool sesion = true;
    char entrada[20] = "", simbolo[] = "x";
    int arregloEnteros[100];
    long resultado = 0;
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
        arregloEnteros[contador] = atoi(token);
        arregloBinario[contador] = conversionBinario(atoi(token));
        contador++;

        while ((token = strtok(NULL, simbolo)) != NULL) {
            printf("Numero = %s\n", token);
            //todo transformarlo a binario
            //todo almacenamos en el arreglo (si lo usamos)
            arregloEnteros[contador] = atoi(token);
            arregloBinario[contador] = conversionBinario(atoi(token));
            contador++;
        }
        for (int i = 0; i < contador/*longitud arreglo*/; i++) {
            printf("Binario [ %ld ] (%ld) = %ld\n", i + 1, arregloEnteros[i], arregloBinario[i]);
        }


        // Todo prueba de multiplicación binaria.
        printf("\n%dx%d = %ld",arregloEnteros[0],arregloEnteros[1],multiplicacionBinario(arregloBinario[0],arregloBinario[1]));
        //todo prueba de conversión de binario a decimal
        /*
         * Como la función recibe una cadena hay que
         * convertir el número long a una cadena de
         * caracteres usando sprintf()
         */
        char numeroBinarioFinal[100];
        sprintf(numeroBinarioFinal,"%d",multiplicacionBinario(arregloBinario[0],arregloBinario[1]));
        printf("\nEl resultado de la multiplicacion de %ldx%ld = %s = %ld\n",arregloEnteros[0],arregloEnteros[1],numeroBinarioFinal,conversionEntero(numeroBinarioFinal, strlen(numeroBinarioFinal)));


        // todo Multiplicarlo
        for (int i = 0; i < contador; ++i) {
            //todo mandar por parejas los datos del arreglo
            /*
             * num1 = a[0] = 101
             * num2 = a[1] = 111
             * arreglo[]= funcionMultiplicación(a[i],a[i++]); // no c puede con impares
             * num1  = return multiplicacion
             * num2 = a[2];
             *
            */
        }

        resultado = multiplicacionRecursiva(0,0);
        printf("Resultado = %ld\n" , resultado);
        sesion = false;
        return 0;
    }

}



/*
 * multiplicación(a,b){
 *
 *
 *
 * if(contador == 0){
 *      a = arreglo[contador]      //(global)
 *      b = arreglo[contador++]    //(global)
 *      a = a x b; // llamada a la función de multiplicar
 *      multiplicación(a, arreglo[contador++]);
 * }else{
 *      a = a x b;
 * }
 *
 *
 *
 * if(contador != lim){
 *
 *      multiplicación(a, arreglo[contador++]);
 *                     // a = resultado anterior
 *
 * }
 * else{
 *
 *      return a;
 * }
 *
 *
 *
 *}
 * */

int contadorAux = 0;

long multiplicacionRecursiva(long a, long b){
    //printf("contadorAux = %d\n",contadorAux);
    if(contadorAux < 2){
        a = arregloBinario[contadorAux];
        b = arregloBinario[contadorAux+=1];
        a = multiplicacionBinario( a, b );
        // todo imprimir a = contador[Aux-1] x contador[Aux]
        multiplicacionRecursiva(a, arregloBinario[contadorAux+=1]);
    }
    else {
        if(contadorAux == contador){
            printf("Valor de a = %ld \n", a);
            /*
             * printf("Entra 1 \n");
            printf("Valor de a = %ld \n", a);
            a = multiplicacionBinario(a,b);
            multiplicacionRecursiva(a, arregloBinario[contadorAux-1]);
            contadorAux+=1;
             */
            return a;
        }
        else if( contadorAux < contador ){
            //printf("Valor de a = %ld \n", a);
            a = multiplicacionBinario(a,b);
            // todo imprimir a = contador[Aux-1] x contador[Aux]
            multiplicacionRecursiva(a, arregloBinario[contadorAux+=1]);
        }
    }

}
