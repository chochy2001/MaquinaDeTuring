#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "conversionBinario.h"
#include "multiplicacionBinario.h"
#include "conversionEntero.h"
#include "validacionEntrada.h"

static long arregloBinario[100];
int contador = 0, contadorAux = 0;
long multiplicacionRecursiva( long a, long b);

int main() {
    //todo hacer maquina de turing para verificar que es correcta la entrada.
    //todo diseñar la multiplicación de binarios con respecto a el retorno de conversiónBinario.h

    bool sesion = true,validacionCadena = true;
    char entrada[20], simbolo[] = "x",resultadoString[100] = "",entradaFinal[100] = "";
    int arregloEnteros[100],continuar;
    long resultado = 0;
    printf("Este programa realiza una multiplicaci%cn de dos n%cmeros naturales a trav%cs ", 162, 163, 130);
    printf("del algoritmo de Maquina de Turing\n");
    printf("Se debe ingresar la multiplicaci%cn a realizar con el formato \"nxn\", donde \"n\" ser%c un n%cmero ", 162,
           160, 163);
    printf("entero y \"x\" funcionar%c como s%cmbolo de multiplicaci%cn\n", 160, 161, 162);


    //todo diseñar la maquina de Turing para que antes de evaluar
    // los números verifique si la entrada es correcta

        //todo verificar que la entrada sea correcta aquí
        //todo si la entrada no es correcta no se debe pasar de aqui.
        do{
            contador = 0;
            contadorAux = 0;
            strcpy(entradaFinal,"");
            printf("Ingrese la multiplicaci%cn que desea realizar\n", 162);
            fflush(stdin);
            scanf("%s", entrada);
            strcat(entradaFinal, entrada);
            if(validacionEntrada(entrada, strlen(entrada)) == -1){
                printf("La entrada no es correcta\n");
                validacionCadena = true;
                continue;
            }
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

            resultado = multiplicacionRecursiva(0,0);
            sprintf(resultadoString, "%ld", resultado);
            if(validacionCadena == true){
                printf("\nEl resultado de la multiplicacion de %s = %ld = %ld\n",entradaFinal,resultado,conversionEntero(resultadoString, strlen(resultadoString)));
            }


            /*
             * Como la función recibe una cadena hay que
             * convertir el número long a una cadena de
             * caracteres usando sprintf()
             */
            printf("Desea continuar?\n1) Si\n2) No\n");
            scanf("%d",&continuar);
            if(continuar == 2){
                validacionCadena = false;
                printf("Gracias por usar el Programa\n");
            }

        }while(validacionCadena == true);

        return 0;
    }

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
            //printf("Valor de a = %ld \n", a);
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
