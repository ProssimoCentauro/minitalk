#include "../../minitalk_headers/minitalk.h"

void    safe_sigaction(int sig, const struct sigaction ac)
{
    if (sigaction(sig, &ac, NULL) == -1)
    {
        ft_printf("\n><><>SIGACTION ERROR!<><><\n");
        exit(EXIT_FAILURE);
    }
}

void    safe_signal(int sig, void (*handler)(int))
{
    if (signal(sig, handler) == SIG_ERR)
    {
        ft_printf("\n><><>SIGNAL ERROR!<><><\n");
        exit(EXIT_FAILURE);
    }
}

void    safe_kill(pid_t id, int sig)
{
    if (kill(id, sig) == -1)
    {
        ft_printf("\n><><>KILL ERROR!<><><\n");
        exit(EXIT_FAILURE);
    }
}
