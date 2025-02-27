/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:45 by odahriz           #+#    #+#             */
/*   Updated: 2025/01/05 14:56:31 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	s;
	int				count;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	s = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthexa(s, 'x');
	return (count);
}
