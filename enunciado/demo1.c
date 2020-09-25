#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Para compilar:

gcc -o demo1 demo1.c -Wall -Werror


Para visualizar un archivo generado

Ejemplo:

hexdump file1.txt 
0000000 0003 0000 0007 0000 0006 0000          
000000c

file1.txt -C
00000000  03 00 00 00 07 00 00 00  06 00 00 00              |............|
0000000c

hexdump file1.txt -x
0000000    0003    0000    0007    0000    0006    0000                
000000c

Para mas opciones ver en google...
*/


// Defines para test

//#define TEST_1
#define MAIN_PROGRAM

// Declaraciones de las funciones
void inicializarSemilla(void);
int generarNumero(int maxNum);

// Funcion principal
int main(int argc, char **argv) {
    // Abriendo el archivo
    if(argc <= 3) {
        printf("ERROR: \n\n");
        printf("USO: ./demo1 file numbers max_num\n");
        exit(1);
    }    
    else {
        inicializarSemilla();

        #ifdef TEST_1
        int num = generarNumero(20);
        printf("Numero generado: %d\n",num);
        #endif

        #ifdef MAIN_PROGRAM

        // Cerrando el archivo
        FILE *out_file;
        out_file = fopen(argv[1],"w");
        // Volviendo los argumentos necesarios a enteros
        int numbers = atoi(argv[2]);
        int max_num = atoi(argv[3]);
        // Escribiendo en el archivo
        for(int i = 0;i < numbers; i++) {
            int num = generarNumero(max_num);
            fwrite(&num, sizeof(int), 1, out_file);
        }
        // Cerrando el archivo
        fclose(out_file);
        #endif
        exit(0);
    }
}


// Definiciones de las funciones

void inicializarSemilla(void) {
    srand(time(NULL)); // Inicializacion de la semilla
}

int generarNumero(int maxNum) {
    return rand()%maxNum; //Generando un aleatorio entre 0 y MaxNum
}
