#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/header_files/ft_printf.h"
# include "../libft/header_files/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	safe_sigaction(int sig, struct sigaction sa);
void	safe_kill(pid_t id, int sig);
void	safe_signal(int sig, void (*handler)(int));
#endif
