#include "minitalk.h"

int set_bit(int sig)
{
    if (sig == SIGUSR1)
        return (1);
    else if (sig == SIGUSR2)
        return (0);
}

int check_char(unsigned char *res, int *pos, pid_t id)
{
    *pos = 0;
    if (!*res)
    {
        printf("\n^ ^ ^ MESSAGE RECEIVED FROM CLIENT: %d ^ ^ ^\n\n\n\n", id);
        safe_kill(id, SIGUSR2);
        return (0);
    }
    write(1, res, 1);
    *res = 0;
    return (1);
}

void    signal_handler(int sig, siginfo_t *info, void *context)
{
    static int  pos = 0;
    static unsigned char  res = 0;
    int bit;
    static pid_t    client_id;

    (void)context;
    if (info->si_pid)
        client_id = info->si_pid;
    bit = set_bit(sig);
    if (bit)
        res |= 0b10000000 >> pos;
    else
        res &= (0b11111111 ^ (0b10000000 >> pos));
    pos++;
    if (pos == 8 && !check_char(&res, &pos, client_id))
        return ;
    safe_kill(client_id, SIGUSR1);
}

int main()
{
    printf("-------------------------\n");
    printf("| SERVER PID: %d     |\n", getpid());
    printf("| WAITING FOR CLIENT... |\n", getpid());
    printf("-------------------------\n\n\n\n");

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
