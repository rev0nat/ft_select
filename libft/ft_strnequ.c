/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:57:12 by aguillot          #+#    #+#             */
/*   Updated: 2018/01/03 11:00:09 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 != NULL && s2 != NULL)
	{
		if (n == 0)
			return (1);
		if (!s1 || !s2)
			return (0);
		i = 0;
		while (s1[i] && s2[i] && i <= n - 1)
		{
			if (s1[i] != s2[i] || i > n - 1)
				return (0);
			i++;
		}
	}
	return (1);
}
