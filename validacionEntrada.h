
#ifndef PROYECTOLFYA_VALIDACIONENTRADA_H
#define PROYECTOLFYA_VALIDACIONENTRADA_H

// Funciones de validación de entrada
//si la entrada es correcta regresa un 0 y si es incorrecta regresa un -1
//3x2x5x3x2x1x3
//siempre que la entrada es correcta es un numero impar.
// Si la entrada es incorrecta de entrada es un numero para (longitud)

#include <stdio.h>

int contChar = 0;

int estado0(const char entrada[]);
int estado1(const char entrada[]);
int estado2(const char entrada[]);
int estado3(const char entrada[]);

int validacionEntrada(const char entrada[], int longitud){
    contChar = 0;
    estado0(entrada);
    /*
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
     */
}

int estado0(const char entrada[]){
    for (int i = 0; i < strlen(entrada)+1; ++i) {
        printf("i[%d] = %c\n",i,entrada[i]);
    }

    bool entero = true;
    if(entrada[contChar] >= '0' && entrada[contChar] <= '9'){
        contChar++;
        //estado1(entrada);
        while(entero) {
            if (entrada[contChar] == 'x') {
                entero = false;
                estado1(entrada);
            }
            else{
                if(entrada[contChar] >= '0' && entrada[contChar] <= '9'){
                    contChar++;
                }
                else{
                    entero = false;
                }
            }
        }
    }
    else{
        return -1;
    }
}

int estado1(const char entrada[]){
    if(entrada[contChar] == 'x' ){
        contChar++;
        estado2(entrada);
    }
    else{
        return -1;
    }
}

int estado2(const char entrada[]){
    if(entrada[contChar] == 'x'){
        return -1;//entrada invalida.
    }else if(entrada[contChar] >= '0' && entrada[contChar] <= '9'){
        contChar++;
        estado3(entrada);
    }
    else{
        return -1;
    }


}

int estado3(const char entrada[]){
    if(entrada[contChar] == 'x' ){
        contChar++;
        estado2(entrada);
    }
    else if(entrada[contChar] == 0){
        return 0;
    }
    else {
        return -1;
    }
}

#endif //PROYECTOLFYA_VALIDACIONENTRADA_H
