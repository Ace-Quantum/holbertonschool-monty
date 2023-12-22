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
	
	command = strdup(token);

        strcpy(command, token);
        //token = strtok(NULL, " ");
        if (strcmp(command, "push") == 0)
        {
            token = strtok(NULL, " ");
            //check if num here
            if (token == NULL)
            {
                //return error code
		free(buffer);
		free(command);
		free_stack(head);
		fclose(file);
                return (-1);
            }
            data = atoi(token);
            push(&head, data);
            line_count++;
	    free(command);
            continue;
        }
        line_count++;
//temp if statement just to test the command
        if (strcmp(command, "pall") == 0)
            pall(head);
        //else
            //printf("well fam idk what to tell you\n");
    }
    free(buffer);
    free(command);
    free_stack(head);
    fclose(file);
    return(0);
}
