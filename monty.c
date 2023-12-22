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
    int data, line_count = 0;
    stack_t *head = NULL;
    if (buffer == NULL)
        return (0);

    if (argc < 2)
    {
        printf("Insert error message here\n");
        free(buffer);
	return(-1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
        fprintf(stderr, "Unable to open file\n");
    
    while (getline(&buffer, &buffsize, file) != -1)
    {
        buffer = spacing(buffer);
        token = strtok(buffer, " ");

        if (token != NULL)
	        command = strdup(token);

        if (strcmp(command, "push") == 0)
        {

            token = strtok(0, " \n");
            
            if (token == NULL)
            {
                printf("no second command found");
                free(command);
                command = NULL;
                
                exit (EXIT_FAILURE);
            }

            data = atoi(token);
            push(&head, data);
            line_count++;
	        free(command);
            command = NULL;
            continue;
        }
        line_count++;

        if (strcmp(command, "pall") == 0)
            pall(head);

        free(command);
        command = NULL;

    }
    free(buffer);
    free(command);
    free_stack(head);
    fclose(file);
    return(0);
}
