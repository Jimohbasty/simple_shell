#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    char *buffer;
    size_t bufsize = 30;

    buffer = malloc(sizeof(char) * bufsize);
    if (buffer == NULL)
        exit(EXIT_FAILURE);
        
    printf("$ ");
    getline(&buffer, &bufsize, stdin);
}