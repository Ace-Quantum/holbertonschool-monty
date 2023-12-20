#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *spacing(char *str)
{
	int x = 0;
	int y = 0;
	int trackspace = 0;
	int trackstr = strlen(str);
	char *trimstr = NULL;

	trimstr = calloc(trackstr, sizeof(char));
	if(!trimstr)
	{
		perror("Memory allocation failed.");
		exit(1);
	}
	while (str[x] != '\0')
	{
		if (str[x] == ' ' && trackspace == 0)
		{
			trackspace++;
			trimstr[y] = str[x];
			y++;
			x++;
		}
		else if (str[x] == '\n')
		{
			break;
		}
		else if (str[x] == ' ' && trackspace != 0)
		{
			trackspace++;
			x++;
		}
		else
		{
			trackspace = 0;
			trimstr[y] = str[x];
			y++;
			x++;
		}
	}
	return (trimstr);
}
