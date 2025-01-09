#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int READY = 0;

void    READY_handler(int pid)
{
    if (pid == SIGUSR1)
    {
        printf();
    }
    READY = 1;
}

void    send_chars(pid_t server_id, char *str)
{
    int i;
    int bit;

    i = 8;  
    while (i--)
    {
        bit = (num >> i & 1);
        //printf("%c\n" , bit + '0');
        if (bit == 1)
            kill(server_id, SIGUSR1);
        else
            kill(server_id, SIGUSR2);
    }
    READY = 0;
    while (READY == 0)
        usleep(10);

}

int main(int ac, char **av)
{
    int num;
    pid_t   server_id;

    server_id = atoi(av[1]);
    send_chars(server_id, av[2]);
    
    signal(SIGUSR1, )
    printf("%d\n", num);
    return (0);
}
