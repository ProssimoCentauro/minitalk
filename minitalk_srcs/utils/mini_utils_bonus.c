#include "../../minitalk_headers/minitalk_bonus.h"

void    safe_sigaction(int sig, const struct sigaction ac)
{
    if (sigaction(sig, &ac, NULL) == -1)
    {
        ft_printf("\n><><>SIGACTION ERROR!<><><\n");
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
