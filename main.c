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
    printf("Este programa realiza una multiplicaci%cn de dos n%cmeros naturales\na trav%cs", 162, 163, 130);
    printf(" del algoritmo de Maquina de Turing\n\n");
    printf("Se debe ingresar la multiplicaci%cn a realizar\ncon el formato \"nxn\", donde \"n\" ser%c un n%cmero\n", 162,
           160, 163);
    printf("entero y \"x\" funcionar%c como s%cmbolo de multiplicaci%cn\n\n", 160, 161, 162);

        do{
            contador = 0;
            contadorAux = 0;
            strcpy(entradaFinal,"");
            printf("Ingrese la multiplicaci%cn que desea realizar\n", 162);
            fflush(stdin);
            scanf("%s", entrada);
            //Concatenamos la entrada a entradaFinal para imprimirlo en la salida.
            strcat(entradaFinal, entrada);
            if(validacionEntrada(entrada, strlen(entrada)) == -1){
                printf("La entrada no es correcta\n");
                validacionCadena = true;
                continue;
            }
            //Con el token se realiza el intercambio de la entrada
            //y se divide en numeros y simbolos.
            char *token = strtok(entrada, simbolo);
            printf("Numero = %s\n", token);

            //el token (los numeros) se convierten de string a enteros con la función atoi.
            //Para poder asignarlos al arreglo de Enteros para realizar las operaciones
            arregloEnteros[contador] = atoi(token);
            //Ya una vez realizado la conversión y almacenados en el arreglo
            //se crea un arreglo de binarios con ayuda de la funcion conversion binario.
            //que crea un arreglo de binarios (con los numeros escritos por el usuario)
            arregloBinario[contador] = conversionBinario(atoi(token));
            //aumentamos el contador para que se almacenen en indices distintos.
            contador++;

            while ((token = strtok(NULL, simbolo)) != NULL) {
                //mientras el simbolo contenido dentro de simbolos sea igual a x.
                //Se seguira usando para separar los numeros del token.
                //Así hasta terminar con todos los números

                printf("Numero = %s\n", token); // coconut
                arregloEnteros[contador] = atoi(token);
                arregloBinario[contador] = conversionBinario(atoi(token));
                contador++;
            }
            //se comprueba que el código funciona correctamente al
            //hacer las conversiones de los numeros y almacenarlos en indices distintos.
            for (int i = 0; i < contador/*longitud arreglo*/; i++) {
                printf("Binario [ %ld ] (%ld) = %ld\n", i + 1, arregloEnteros[i], arregloBinario[i]);
            }
            //Se realiza la multiplicación de manera recursiva para poder obtener el resultado.
            // que es una llamada a la función de la multiplicación binario de manera recursiva
            // ya que podemos admitir muchos numeros distintos.
            resultado = multiplicacionRecursiva(0,0);
            /*
             * Como la función recibe una cadena hay que
             * convertir el número long a una cadena de
             * caracteres usando sprintf()
             */
            sprintf(resultadoString, "%ld", resultado);
            //Si la cadena es valida se imprime el resultado de la multiplicación
            if(validacionCadena == true){
                printf("\nEl resultado de la multiplicacion de %s = %ld = %ld\n",entradaFinal,resultado,conversionEntero(resultadoString, strlen(resultadoString)));
            }


            //Le preguntamos al usuario si quiere continuar
            // para volver a realizar todo el procedimiento antes mencionado
            printf("Desea continuar?\n1) Si\n2) No\n");
            scanf("%d",&continuar);
            //Si el usuario no quiere continuar se saldrá del programa
            if(continuar == 2){
                validacionCadena = false;
                printf("Gracias por usar el Programa\n");
            }

        }while(validacionCadena == true);

        return 0;
    }


    //Función de multiplicación recursiva.
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
