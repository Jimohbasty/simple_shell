#include <stdio.h>

int main(int ac, char **av)
{
    int i;

    for (i = 1; av[i] != NULL; i++)
        printf("%d = %s\n", i, av[i]);
    return (0);
}