/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:53:03 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/15 07:09:48 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	last_send(int pid)
{
	int		error;
	int		counter;
	char	c;

	error = 0;
	counter = 7;
	c = '\0';
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep(100);
		counter--;
		if (error == -1)
		{
			ft_printf("error");
			exit(1);
		}
	}
}

void	sender(int pid, char *str)
{
	int		error;
	int		counter;
	char	c;

	error = 0;
	while (*str)
	{
		counter = 7;
		c = *str;
		while (counter >= 0)
		{
			if ((c >> counter) & 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			usleep(100);
			counter--;
			if (error == -1)
			{
				ft_printf("error");
				exit(1);
			}
		}
		str++;
	}
}

void	acknowledge(int pid)
{
	ft_printf("message received");
}

int	main(int ac, char **av)
{
	long	pid;
	int		i;

	i = 0;
	signal(SIGUSR1, acknowledge);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (ft_strlen(av[1]) > 7 || pid <= 0 || pid > 4194304)
		{
			ft_printf("The provided PID is outside the valid range!");
			exit(1);
		}
		sender(pid, av[2]);
	}
	else
		ft_printf("error please provide 2 arguments only!!!");
	last_send(pid);
}
