#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// Funcion principal
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    int i = 1;

    FILE *pInFile;


    pInFile = fopen(argv[i],"r");
    if (pInFile == NULL){
        printf ( "Could not open file" ) ;
        return 1;
    }

    
    int count = 0;

    char current=fgetc(pInFile);

    char previous= current;

    while(current != EOF){
        if(previous == current){
            count++;
        }else{
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&previous, sizeof(char), 1, stdout);
            // printf("%d%c-",count, previous);
            previous = current;
            count = 1;
        }
        current =fgetc(pInFile);
    }
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&previous, sizeof(char), 1, stdout);
    // printf("%d%c-",count, previous);
    
    // while((aux=fgetc(pInFile)) != EOF){

    //     if(first){

    //     }
    //     if(last == aux){ //aumentar cuenta 
    //         count++;
    //     }else{ //cambio de caracter, imprima
    //         // printf("\n%hx-",aux);
    //         fwrite(&count, sizeof(int), 1, stdout);
    //         fwrite(&aux, sizeof(char), 1, stdout);
    //         count = 0;
    //     }
    //     last = aux;
        
    // }
    fclose(pInFile);

        //        FILE *fp ;
        //    char c ;
        //    printf( "Opening the file test.c in read mode" ) ;
        //    fp = fopen ( "test.c", "r" ) ; // opening an existing file
        //    if ( fp == NULL )
        //    {
        //      printf ( "Could not open file test.c" ) ;
        //      return 1;
        //    }
        //    printf( "Reading the file test.c" ) ;
        //    while ( 1 )
        //    {
        //      c = fgetc ( fp ) ; // reading the file
        //      if ( c == EOF )
        //      break ;
        //      printf ( "%c", c ) ;
        //    }
        //    printf("Closing the file test.c") ;
        //    fclose ( fp ) ; // Closing the file
        //    return 0;

        // while(i < argc){
        //     pInFile = fopen(argv[i],"r");
        //     if (pInFile == NULL){
        //         printf ( "Could not open file test.c" ) ;
        //         return 1;
        //     }
        //     int aux;
        //     do{
        //         aux = fgetc(pInFile);
        //         // if(feof(pInFile)){
        //         //     break;
        //         // }
        //         printf("%c \n",aux);
        //     }while(aux != EOF);
        //     // }while(1);

        //     // Volviendo los argumentos necesarios a enteros
        //     // int numbers = atoi(argv[2]);
        //     // int max_num = atoi(argv[3]);
        //     // // Escribiendo en el archivo
        //     // for(int i = 0;i < numbers; i++) {
        //     //     int num = generarNumero(max_num);
        //     //     fwrite(&num, sizeof(int), 1, out_file);
        //     // }

        // fclose(pInFile);
        // }
        return 0;
}