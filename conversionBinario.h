#include <string.h>
#include <stdlib.h>

int conversionBinario(int numero){
    char numeroBinarioChar[100],numeroBinarioCharFinal[100];
    int a[100],i,numeroBinarioEntero;
    for(i=0; numero > 0; i++){
        a[i]= numero % 2;
        numero = numero / 2;
    }

    for(i=i-1;i>=0;i--){
        sprintf(numeroBinarioChar, "%d",a[i]);
        strcat(numeroBinarioCharFinal,numeroBinarioChar);
    }
    numeroBinarioEntero = atoi(numeroBinarioCharFinal);
    //todo hacer que el numero ingresado se pueda almacenar en un arreglo y
    // despues sacarlo del mismo para ponerlo en un solo numero para poder hacer la
    // multiplicación de binarios
    return numeroBinarioEntero;


    //todo recibir un numero y convertirlo a binario.
}