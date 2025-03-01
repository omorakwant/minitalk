/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:53:03 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/01 21:34:18 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0 || pid > 4194304)
		{
			ft_printf("The provided PID is outside the valid range!");
			exit(1);
		}
		sender(pid, av[2]);
	}
	else
		ft_printf("error number of arguments is invalid please provide 2 arguments only!!!");
}
