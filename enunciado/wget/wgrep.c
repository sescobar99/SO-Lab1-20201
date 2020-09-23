#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *buffer = NULL;
    size_t length = 0;
    ssize_t nread;
    ;

    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    else if (argc == 2)
    {
        while ((nread = getline(&buffer, &length, stdin)) != -1)
        {
            if (strstr(buffer, argv[1]) != NULL)
            {
                fwrite(buffer, nread, 1, stdout);
            }
        }
    }
    else
    {

        FILE *pInFile = NULL;
        int i = 1;
        char *pFileName = NULL;

        while (i + 1 < argc)
        {
            pFileName = (char *)argv[i + 1];
            pInFile = fopen(pFileName, "r");
            if (pInFile == NULL)
            {
                // printf("wgrep: cannot open filen");
                perror("wgrep: cannot open filen");
                return 1;
            }
            while ((nread = getline(&buffer, &length, pInFile)) != -1)
            {
                if (strstr(buffer, argv[1]) != NULL)
                {
                    fwrite(buffer, nread, 1, stdout);
                }
            }
            i++;
            fclose(pInFile);
        }
    }

    free(buffer);

    return 0;
}
