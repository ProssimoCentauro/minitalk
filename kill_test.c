#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("bad args number!\n");
        return (0);
    }
    kill(atoi(av[1]), SIGTERM);
    return (0);
}
