#ifndef MINITALK_H
#define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/header_files/libft.h"
#include "../libft/header_files/ft_printf.h"

void    safe_sigaction(int sig, struct sigaction sa);
void    safe_kill(pid_t id, int sig);
#endif
