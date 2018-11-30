/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:37:31 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/02 21:40:53 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

off_t	count_words(char *str)
{
	off_t	i;
	off_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9 && str[i] != 13 && str[i] != 10 &&\
				(str[i + 1] == 32 || str[i + 1] == 9 || str[i + 1] == 13\
				|| str[i + 1] == '\0' || str[i + 1] == 10))
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

off_t	count_letters(char *str, off_t i)
{
	off_t	word_len;

	word_len = 0;
	while (str[i] && str[i] != 32 && str[i] != 13 && str[i] != 10 &&\
			str[i] != 9)
	{
		word_len++;
		i++;
	}
	return (word_len);
}

void	split(char **tab, char *str, int nb_of_words)
{
	off_t	i;
	off_t	j;
	off_t	word_len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == 13 || str[i] == 10 || str[i] == 9)
			i++;
		word_len = count_letters(str, i);
		if (j < nb_of_words)
		{
			if ((tab[j] = ft_strsub(str, i, word_len)) == NULL)
			{
				free(tab);
				return ;
			}
		}
		i += word_len;
		j++;
	}
}

char	**ft_splitwhitespaces(char *str)
{
	char	**tab;
	off_t	nb_of_words;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	nb_of_words = count_words(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_of_words + 1))))
		return (NULL);
	tab[nb_of_words] = NULL;
	split(tab, str, nb_of_words);
	while (tab[i])
		i++;
	return (tab);
}
