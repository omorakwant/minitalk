/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by odahriz           #+#    #+#             */
/*   Updated: 2025/01/03 15:55:05 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char c)
{
	char	*s;
	int		count;

	count = 0;
	s = "0123456789abcdef";
	if (c == 'X')
		s = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthexa(n / 16, c);
	count += ft_putchar(s[n % 16]);
	return (count);
}
