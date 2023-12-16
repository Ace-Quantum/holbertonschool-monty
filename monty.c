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
    char *command = malloc(buffsize * sizeof(char));
    int data, line_count = 0;
    stack_t *head = NULL;

    if (buffer == NULL || command == NULL)
        return (0);
    
    if (argc < 2)
    {
        printf("Insert error message here\n");
        return(-1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
        fprintf(stderr, "Unable to open file\n");
    //printf("assigned file to variable\n");
    //printf("here's the file name: %s\n", argv[1]);
    
    while (fgets(buffer, buffsize, file) != NULL)
    {
        printf("started while loop\n");
        token = strtok(buffer, " ");
        strcpy(command, token);
        printf("Command: %s\n", command);
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            data = atoi(token);
            printf("Number: %d\n", data);
            push(&head, data);
            line_count++;
            continue;
            //Better call pall
                //That joke actually applies elsewhere in the code
        }
        line_count++;
        printf("Line count: %d\n", line_count);
        //temporary if statement for the purposes of testing function
        if (strcmp(command, "pall\n") == 0)
            pall(head);
        else
            printf("well fam idk what to tell you\n");
    }

    fclose(file);
    free(buffer);
    free(command);

    return(0);
}