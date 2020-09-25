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

FILE *openFileR(char *);
void zip(FILE *fp, char *previous,int *count, int first);


// Funcion principal
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    int i = 1;
    FILE *pInFile;
    char previous = EOF;
    int count = 1;
    pInFile = openFileR(argv[i]);

    while(i < argc){
        int first = !(i-1);
        zip(pInFile,&previous, &count, first);

        fclose(pInFile);
        i++;
        if(i < argc){
            pInFile = openFileR(argv[i]);
        }
    }
    // fwrite(&count,sizeof(int),1 ,stdout);
    // fwrite(&previous,sizeof(char),1 ,stdout);
    printf("%d:%c/",count, previous);
    
    return 0;
}


FILE *openFileR(char *file){
    FILE *fp;
    fp = fopen(file,"r");
    if (fp == NULL){
        printf ( "Could not open file" ) ;
        exit (1);
    }
    return fp;
}

void zip(FILE *fp, char *previous,int *count, int first){
    char current;
    if(first){
        *previous = fgetc(fp);
    }

    while((current = fgetc(fp)) != EOF){
        if(*previous == current){
            (*count)++;
        }else{
            // fwrite(&count,sizeof(int),1 ,stdout);
            // fwrite(&previous,sizeof(char),1 ,stdout);
            printf("%d:%c/",*count, *previous);
            *previous = current;
            *count = 1;
        }
    }
    return ;
}