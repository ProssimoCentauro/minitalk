#include "../../minitalk_headers/minitalk_bonus.h"

static int	set_bit(int sig)
{
	int	bit;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	return (bit);
}

static int	check_char(unsigned char *res, int *pos, pid_t id)
{
	*pos = 0;
	if (!*res)
	{
		ft_printf("\n^ ^ ^ MESSAGE RECEIVED FROM CLIENT: %d ^ ^ ^\n\n\n\n", id);
		safe_kill(id, SIGUSR2);
		return (0);
	}
	write(1, res, 1);
	*res = 0;
	return (1);
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				pos = 0;
	static unsigned char	res = 0;
	int						bit;
	static pid_t			client_id;

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

int	main(void)
{
	struct sigaction	ac;

	ft_printf("-------------------------\n");
	ft_printf("| SERVER PID: %d     |\n", getpid());
	ft_printf("| WAITING FOR CLIENT... |\n", getpid());
	ft_printf("-------------------------\n\n\n\n");
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
