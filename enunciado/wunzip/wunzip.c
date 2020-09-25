#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *openFileR(char *);
void unzip(FILE *fp);

// Funcion principal
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    int i = 1;
    FILE *pInFile;
    while(i < argc){
        pInFile = openFileR(argv[i]);
        unzip(pInFile);   
        fclose(pInFile);
        i++;
    }
        return 0;
}

FILE *openFileR(char *file){ //open file and manage error
    FILE *fp;
    fp = fopen(file,"r");
    if (fp == NULL){
        printf ("Could not open file\n" ) ;
        exit (1);
    }
    return fp;
}


void unzip(FILE *fp){
    char current;
    int num;
    while((fread(&num, sizeof(int), 1, fp)) != 0){
        fread(&current, sizeof(char), 1, fp);
        for(int k=0;k<num;k++){
            printf("%c", current);
        }
    }       
    return ;
}