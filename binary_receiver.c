#include "minitalk.h"

void    signal_handler(int sig, siginfo_t *info, void *context)
{
    static int  i = 0;
    static unsigned char  res = 0;
    static int bit;
    static pid_t    client_id;

    if (info->si_pid)
        client_id = info->si_pid;
    //ft_putnbr(client_id);
    (void)context;
    if (sig == SIGUSR1)
        bit = 1;
    else if (sig == SIGUSR2)
        bit = 0;
    //res |= (bit << i);
    if (bit == 1)
        res |= 0b10000000 >> i;
    else
        res &= (0b11111111 ^ (0b10000000 >> i));
    //printf("%d\n", bit);
    i++;
    //write (1, "arrivato ", 9);
    //printf ("%d\n", i);
    if (i == 8)
    {
        //write (1, "arrivato", 8);
        if (res == '\0')
        {
            printf("\n");
            safe_kill(client_id, SIGUSR2);
            return ;
        }
        //printf("normale: %d\n", res);
        //printf("diviso 2: %d\n", res / 2);
        //res = res / 2;
        write(1, &res, 1);
        i = 0;
        res = 0;
    }
    safe_kill(client_id, SIGUSR1);
}

int main()
{
    printf("PID: %d\n", getpid());

    struct sigaction ac;

    ac.sa_sigaction = signal_handler;
    ac.sa_flags = SA_SIGINFO;
    sigemptyset(&ac.sa_mask);
    sigaddset(&ac.sa_mask, SIGUSR1);
    sigaddset(&ac.sa_mask, SIGUSR2);

    safe_sigaction(SIGUSR1, ac);
    safe_sigaction(SIGUSR2, ac);

    while (1)
    {
        pause();
    }
    return (0);
}
