#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Para compilar:

gcc -o demo2 demo2.c -Wall -Werror

NOTA: Este programa tiene un BUG!!! mirar como corregirlo...
*/


// Defines para test

//#define TEST

#define MAIN_PROGRAM

// Declaraciones de las funciones
void generarAsteriscos(int num);

// Abriendo el archivo
int main(int argc, char **argv) {
    if(argc != 2) {
        printf("ERROR: \n\n");
        printf("USO: ./demo1 file\n");
        exit(1);
    }    
    else {

        #ifdef TEST
        generarAsteriscos(10); 
        #endif

        #ifdef MAIN_PROGRAM

        // Abriendo el archivo
        FILE *in_file;
        in_file = fopen(argv[1],"r");
        // Volviendo los argumentos necesarios a enteros
        // Leyendo el archivo
        int num;
        while(!feof(in_file)) {
            fread(&num, sizeof(int), 1, in_file);
            fprintf(stdout,"%d ",num); // printf("%d ",num);
            generarAsteriscos(num);
        }
        // Cerrando el archivo
        fclose(in_file);
        #endif
        exit(0);
    }
}


// Definiciones de las funciones

void generarAsteriscos(int num) {
    // Cambiarlo para un archivo luego
    for(int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
}