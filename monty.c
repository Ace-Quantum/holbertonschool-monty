#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    size_t buffsize = 1024;
    char *buffer = malloc(buffsize * sizeof(char));
    FILE *file;
    char *token = NULL;
    char *command = NULL;
    int data;

    if (argc < 2)
    {
        printf("Insert error message here\n");
        return(-1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
        fprintf(stderr, "Unable to open file\n");
    printf("assigned file to variable\n");
    printf("here's the file name: %s\n", argv[1]);
    
    while (fgets(buffer, buffsize, file) != NULL)
    {
        printf("started while loop\n");
        token = strtok(buffer, " ");
        strcpy(command, token);
        printf("Command: %s\n", command);
        if (token = strtok(NULL, " ") != NULL)
        {
            data = atoi(token);
            printf("Number: %d\n", data);
        }
    }

    fclose(file);
    free(buffer);

    return(0);
}