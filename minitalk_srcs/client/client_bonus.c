#include "../../minitalk_headers/minitalk_bonus.h"

int READY = 0;

static void    READY_handler(int sig)
{
    (void)sig;
    READY = 1;
}

static void    MESSAGE_handler(int sig)
{
    (void)sig;
    ft_printf("\n-------------------------------------------\n");
    ft_printf("server: MESSAGE RECEIVED! good work client!\n");
    ft_printf("-------------------------------------------\n");
    exit(EXIT_SUCCESS);
}

static void    send_character(pid_t server_id, char c)
{
    unsigned int position;
    unsigned int bit;

    position = 0;
    while (position < 8)
    {
        bit = c & (0b10000000 >> position);
        if (bit != 0)
            safe_kill(server_id, SIGUSR1);
        else
            safe_kill(server_id, SIGUSR2);
        position++;
        while (!READY)
            usleep(10);
        READY = 0;
    }
}


int main(int ac, char **av)
{             
    pid_t   server_id;

    if (ac != 3)
    {
        ft_printf("BAD ARGUMENTS NUMBER!\n");
        ft_printf("needed server PID and the MESSAGE\n");
        exit(EXIT_FAILURE);
    }
    server_id = atoi(av[1]);
    safe_signal(SIGUSR1, READY_handler);
    safe_signal(SIGUSR2, MESSAGE_handler);
    
    while (*av[2])
    {
        send_character(server_id, *av[2]);
        av[2]++;
    }
    send_character(server_id, *av[2]);

    return (0);
}
