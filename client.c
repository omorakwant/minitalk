/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:53:03 by odahriz           #+#    #+#             */
/*   Updated: 2025/02/27 10:19:47 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	pid_t	pid;
	
	if (ac == 3)
	{
		signal(SIGUSR1,pid);
		kill(SIGUSR1, pid);
	}
	else 
		ft_printf("error number of arguments low!!!");
	exit;
}