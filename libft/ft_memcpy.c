/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:55:03 by odahriz           #+#    #+#             */
/*   Updated: 2024/11/16 13:39:31 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	const char		*s;

	p = dest;
	s = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}
