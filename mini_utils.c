#include "minitalk.h"

void    safe_sigaction(int sig, const struct sigaction ac)
{
    if (sigaction(sig, &ac, NULL) == -1)
    {
        printf("\n><><>SIGACTION ERROR!<><><\n");
        exit(EXIT_FAILURE);
    }
}

void    safe_kill(pid_t id, int sig)
{
    if (kill(id, sig) == -1)
    {
        printf("\n><><>KILL ERROR!<><><\n");
        exit(EXIT_FAILURE);
    }
}

void    ft_putchar(char c)
{
    write(1, &c , 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

