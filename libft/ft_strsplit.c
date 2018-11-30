/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:24:49 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/04 14:41:03 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int			valid(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (1);
		i++;
	}
	return (0);
}

static size_t		count_words(char const *s, char c)
{
	static int	i;
	size_t		wc;
	int			state;

	i = 0;
	wc = 1;
	state = 0;
	while (s[i])
	{
		if (s[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wc++;
		}
		i++;
	}
	i = valid(s, c);
	if (i == 1)
		return (wc - 1);
	return (wc);
}

static size_t		count_char(char const *s, char c, int i)
{
	size_t	charnbr;

	charnbr = 0;
	while (s[i] && s[i] != c)
	{
		charnbr++;
		i++;
	}
	return (charnbr);
}

static char			**split(char const *s, char **dest, char c)
{
	size_t	i;
	int		word;
	size_t	charnbr;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			charnbr = count_char(s, c, i);
			if (!(dest[word] = (char*)malloc(sizeof(char) * (charnbr + 1))))
				return (NULL);
			dest[word] = ft_strncpy(dest[word], s + i, charnbr);
			dest[word][charnbr] = '\0';
			i = i + charnbr;
			word++;
		}
		else
			i++;
	}
	dest[word] = 0;
	return (dest);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**dest;
	size_t	wc;

	if (s == NULL)
		return (NULL);
	wc = count_words(s, c);
	dest = (char**)malloc(sizeof(char*) * (wc + 1));
	if (!dest)
		return (NULL);
	return (split(s, dest, c));
}
