//I don't really know how to start this tbh
//Still feeling pretty demoralized
//But it'll be okay
//If anything this was an important lesson for me to learn
//Gotta mitigate damages
//And plan to rebuild

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


int main(int argc, char *argv[])
{
    size_t buffsize = 1024;
    char *buffer = malloc(buffsize * sizeof(char));
    FILE *file = fopen(argv[1], "r");
    char *token;
    char *command;
    int data;

    if (argc < 2)
    {
        printf("Insert error message here\n");
        return(-1);
    }

    if (file == NULL)
        fprintf(stderr, "Unable to open file\n");

    printf("assigned file to variable\n");

    printf("here's the file name: %s\n", argv[1]);
    
    while (fgets(buffer, buffsize, file) != NULL)
    {
        printf("started while loop\n");
        command = strtok(buffer, " ");
        printf("this is the command: %s\n", command);
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            printf("%s\n", token);
            data = atoi(token);
            printf("this is the number: %d\n", data);
        }
    }

    fclose(file);
    free(buffer);

    return(0);
}
