#include <string.h>
#include <stdlib.h>

int conversionBinario(int *numero){
    char numeroBinario[1000];
    int a[1000],i=0,numeroBinarioEntero;

    while(*numero>0){
        a[i]=*numero%2;
        *numero /= 2;
        ++i;
    }

    for (int j = i-1; j >=0; --j) {
        printf("%d",a[j]);
        strcat(numeroBinario, a[j]);
        printf("numeroBinario = %s",numeroBinario);
    }

    printf("numeroBinario = %s",numeroBinario);

    numeroBinarioEntero = atoi(numeroBinario);
    printf("\n");
    printf("numeroBinarioEntero = %d",numeroBinarioEntero);
    return numeroBinarioEntero;

    //todo recibir un numero y convertirlo a binario.
}