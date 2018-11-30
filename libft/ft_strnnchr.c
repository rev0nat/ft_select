/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:27:13 by aguillot          #+#    #+#             */
/*   Updated: 2018/02/07 17:57:56 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnnchr(char const *str, char c, int n, int l)
{
	int	i;

	i = 0;
	if (str && c && n > 0 && i < l)
	{
		while (str[i])
		{
			if (str[i] == c)
				n--;
			i++;
		}
		if (n == 0)
			return (1);
	}
	return (0);
}
