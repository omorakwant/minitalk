/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:26:49 by odahriz           #+#    #+#             */
/*   Updated: 2024/11/17 11:07:01 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
		}
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	split_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	split_puts(char *d, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
}

static char	**split_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i--]);
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		word_len;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		word_len = split_len((char *)s, c);
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (split_free(result, i - 1));
		split_puts(result[i++], (char *)s, c);
		s = s + word_len;
	}
	result[i] = 0;
	return (result);
}
