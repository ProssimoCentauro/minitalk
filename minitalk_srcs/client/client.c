#include "../../minitalk_headers/minitalk.h"

int			g_ready = 0;

static void	ready_handler(int sig)
{
	(void)sig;
	g_ready = 1;
}

static void	message_handler(int sig)
{
	(void)sig;
	ft_printf("\n-------------------------------------------\n");
	ft_printf("server: MESSAGE RECEIVED! good work client!\n");
	ft_printf("-------------------------------------------\n");
	exit(EXIT_SUCCESS);
}

static void	send_character(pid_t server_id, char c)
{
	unsigned int	position;
	unsigned int	bit;

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

int	main(int ac, char **av)
{
	pid_t	server_id;

	if (ac != 3)
	{
		ft_printf("BAD ARGUMENTS NUMBER!\n");
		ft_printf("needed server PID and the MESSAGE\n");
		exit(EXIT_FAILURE);
	}
	server_id = ft_atoi(av[1]);
	safe_signal(SIGUSR1, ready_handler);
	safe_signal(SIGUSR2, message_handler);
	while (*av[2])
	{
		send_character(server_id, *av[2]);
		av[2]++;
	}
	send_character(server_id, *av[2]);
	return (0);
}
