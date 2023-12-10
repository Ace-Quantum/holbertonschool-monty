#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char **make_array(char *buffer, char *del)
{
	char **return_array = malloc(sizeof(char*) * 100);
	char *current_token;
	int i = 0;
	memset(return_array, 0, sizeof(char*) * 100);

	current_token = strtok(buffer, del);

	while (current_token != NULL)
	{
		return_array[i] = malloc(strlen(current_token) + 1);
		strcpy(return_array[i], current_token);
		current_token = strtok(0, del);
		i++;
	}

	return_array[i] = NULL;

	i--;
	if (return_array[i][strlen(return_array[i]) - 1] == '\n')
		return_array[i][strlen(return_array[i]) - 1] = '\0';

	return(return_array);
}

int free_array(char **array)
{
	int i = 0;

	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}

	free(array);

	return (0);
}
