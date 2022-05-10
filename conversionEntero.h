#ifndef PROYECTOLFYA_CONVERSIONENTERO_H
#define PROYECTOLFYA_CONVERSIONENTERO_H


unsigned long long conversionEntero(const char *numeroBinario,int longitud){
    unsigned long long decimal = 0;
    int multiplicador = 1;
    char caracterActual;
    for (int i = longitud - 1; i >= 0; i--) {
        caracterActual = numeroBinario[i];
        if (caracterActual == '1') {
            decimal += multiplicador;
        }
        multiplicador = multiplicador * 2;
    }
    return decimal;
}

#endif //PROYECTOLFYA_CONVERSIONENTERO_H
