#include <stdio.h>
#include <stdlib.h>
#define LINE 1000

int main(int argc, char const *argv[])
{
    FILE *pInFile = NULL;

    int i = 1;
    char *pFileName = NULL;
    char buffer[LINE];

    while(i < argc){
        //read
        pFileName = argv[i];
        pInFile = fopen(pFileName,"r");

        if(pInFile == NULL){
            //  printf("wcat cannot open file %s\n", pFileName);
             printf("wcat: cannot open file\n");
            return 1;
        }

        // printf("\nStart of file %s\n", pFileName);

        while(fgets(buffer, LINE,pInFile) != NULL){
            printf("%s", buffer);
        }

        // printf("\nEnd of file %s\n", pFileName);
        i++;

        fclose(pInFile);
    }

    return 0;
}
