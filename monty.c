//I don't really know how to start this tbh
//Still feeling pretty demoralized
//But it'll be okay
//If anything this was an important lesson for me to learn
//Gotta mitigate damages
//And plan to rebuild

#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


int main(int argc, char *argv[])
{
    size_t buffsize = 1024;
    char *buffer = malloc(buffsize * sizeof(char));

    if (argc < 2)
    {
        printf("Insert error message here");
        return(-1);
    }

    printf("here's the file name: %s\n", argv[0]);
    printf("and the path? %s\n", argv[1]);
     getline(&buffer, &buffsize, stdin);
        
}
