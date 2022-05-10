#ifndef PROYECTOLFYA_MULTIPLICACIONBINARIO_H
#define PROYECTOLFYA_MULTIPLICACIONBINARIO_H

//reglas de multiplicación binaria
// 0x0 = 0
// 0x1 = 0
// 1x0 = 0
// 1x1 = 1

//Reglas de Sumas en binario
// 0+0 =  0
// 0+1 =  1
// 1+0 =  1
// 1+1 = 10     Hay un acarreo
#include <stdio.h>

long productoBinario(long binario1,long binario2);

long multiplicacionBinario(long binario1,long binario2){

    long multiplicar = 0;
    long digito, factor = 1;


    while (binario2 != 0)
    {
        digito = binario2 % 10;
        if (digito == 1)
        {
            binario1 = binario1 * factor;
            multiplicar = productoBinario(binario1, multiplicar);
        }
        else
            binario1 = binario1 * factor;
        binario2 = binario2 / 10;
        factor = 10;
    }
     //printf("%ld x %ld = %ld",binario1,binario2, multiplicar);
    return multiplicar;
}



long productoBinario(long binario1,long binario2)
{
    long i = 0, residuo = 0, sum[20];
    long productoBinario = 0;

    while (binario1 != 0 || binario2 != 0)
    {
        sum[i++] = (binario1 % 10 + binario2 % 10 + residuo) % 2;
        residuo = (binario1 % 10 + binario2 % 10 + residuo) / 2;
        binario1 = binario1 / 10;
        binario2 = binario2 / 10;
    }
    if (residuo != 0)
        sum[i++] = residuo;
    --i;
    while (i >= 0)
        productoBinario = productoBinario * 10 + sum[i--];
    return productoBinario;
}

#endif //PROYECTOLFYA_MULTIPLICACIONBINARIO_H
