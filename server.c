/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:37:15 by odahriz           #+#    #+#             */
/*   Updated: 2025/02/24 16:53:15 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signum)
{
	printf("serve connect %d \n", signum);
	exit(0);
}

int main()
{
	pid_t dip = getpid();
	printf("%d\n",dip);
	signal(SIGUSR1, handler);
	while(1)
	{
		pause();
	}
	return 0;
}