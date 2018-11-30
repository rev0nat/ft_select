/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:40:55 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 16:00:03 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

off_t	get_input_len(char **tab)
{
	off_t len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char	**ft_tabdup(char **tab)
{
	char	**new_tab;
	off_t	len;

	if (!tab)
		return (NULL);
	len = get_input_len(tab);
	if ((new_tab = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	new_tab[len] = NULL;
	len = 0;
	while (tab[len])
	{
		new_tab[len] = ft_strdup(tab[len]);
		len++;
	}
	return (new_tab);
}
