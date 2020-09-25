#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *openFileR(char *);
void zip(FILE *fp,int *count, char *previous, int first, int last);

// Funcion principal
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    int i = 1;
    FILE *pInFile;
    int count = 0;
    char previous = EOF;

    while(i < argc){
        pInFile = openFileR(argv[i]);
        zip(pInFile,&count, &previous, !(i-1), !(i-argc+1));
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


void zip(FILE *fp,int *count, char *previous, int first, int last){
    
    char current=fgetc(fp);
    if(first){
        *previous = current;
    }
    while(current != EOF){
        if(*previous == current){
            (*count)++;
        }else{
            fwrite(count, sizeof(int), 1, stdout);
            fwrite(previous, sizeof(char), 1, stdout);
            // printf("%d%c-",count, previous);
            *previous = current;
            *count = 1;
        }
        current =fgetc(fp);
    }
    if(last){
        fwrite(count, sizeof(int), 1, stdout);
        fwrite(previous, sizeof(char), 1, stdout);
        // printf("%d%c-",count, previous);
    }
    return ;
}