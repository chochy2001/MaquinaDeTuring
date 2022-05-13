
#ifndef PROYECTOLFYA_VALIDACIONENTRADA_H
#define PROYECTOLFYA_VALIDACIONENTRADA_H

// Funciones de validacion de entrada
//si la entrada es correcta regresa un 0 y si es incorrecta regresa un -1
//3x2x5x3x2x1x3
//siempre que la entrada es correcta es un numero impar.
// Si la entrada es incorrecta de entrada es un numero para (longitud)

#include <stdio.h>

int contChar = 0;
int validacionEntrada(const char entrada[], int longitud){
    int contadorX = 0,contadorNum = 0;
    if(entrada[0] == 'x' || entrada[longitud-1]== 'x'){
        return -1;//si la entrada es incorrecta
    }else{
        for(int i = 0; i < longitud; i++){
            if(entrada[i] == 'x'){
                contadorX++;
            }
            if(entrada[i] >= '0' && entrada[i] <= '9'){
                contadorNum++;
            }
        }
        if(contadorX >= contadorNum){
            return -1;//si la entrada es incorrecta
        }
        if(contadorNum > contadorX && contadorNum == 1){
            return -1;
        }
        if(contadorNum == contadorX){
            return -1;
        }

    }
    return 0;//si la entrada es correcta regresa un 0
}

/*int estado0(const char entrada[]){
    if(entrada[contChar] >= '0' && entrada[contChar] <= '9'){
        contChar+=1;
        estado1(entrada);
    }
    else{
        return -1;
    }
}*/

int estado1(){
    
}

#endif //PROYECTOLFYA_VALIDACIONENTRADA_H
