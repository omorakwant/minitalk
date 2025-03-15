/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:37:15 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/09 17:05:08 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *none)
{
	static int	a;
	static char	msg;
	static int	actual_pid;

	if (actual_pid != info->si_pid)
	{
		a = 0;
		msg = 0;
		actual_pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		msg = (msg << 1) | 1;
	else if (signal == SIGUSR2)
		msg = (msg << 1);
	a++;
	if (a == 8)
	{
		if (msg == 0)
		{
			kill(info->si_pid, SIGUSR1);
		}
		ft_printf("%c", msg);
		a = 0;
		msg = 0;
	}
}

int	main(void)
{
	char				*str;
	int					i;
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
