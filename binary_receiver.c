#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int signal_handler(int sig)
{
    if (sig == SIGUSR1)
        return(1);
    if (sig == SIGUSR2)
        return(0);
}

void    bin_to_dec(int bit)
{
    static int  i;
    static unsigned int  res;

   /* i = 0;
    res = 0;*/
    res = (res << 1) | bit;
    printf("%d\n", res);
    if (i == 23)
    {
        printf("%d\n", res);
        i = 0;
        res = 0;
    }
    else
        i++;
}

int main()
{
    printf("PID: %d\n", getpid());

    sigaction ac;

    sigaction()
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
    {
        pause();
    }
    return (0);
}
