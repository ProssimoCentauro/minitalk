#include "minitalk.h"

int READY = 0;

void    READY_handler(int sig)
{
    READY = 1;
}

void    MESSAGE_handler(int sig)
{
    printf("MESSAGE RECEIVED!");
    exit(EXIT_SUCCESS);
}

void    send_character(pid_t server_id, char c)
{
    int i;
    int bit;

    i = 8;
    while (i--)
    {
        bit = (c >> i & 1);
        if (bit == 1)
            safe_kill(server_id, SIGUSR1);
        else
            safe_kill(server_id, SIGUSR2);
        while (READY == 0)
            usleep(10);
        READY = 0;
    }
}

int main(int ac, char **av)
{             
    int num;
    pid_t   server_id;

    server_id = atoi(av[1]);
    signal(SIGUSR1, READY_handler);
    signal(SIGUSR2, MESSAGE_handler);
    
    while (*av[2])
    {
        send_character(server_id, *av[2]);
        av[2]++;
    }
    send_character(server_id, '\0');

    return (0);
}
