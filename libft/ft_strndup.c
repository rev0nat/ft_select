/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:14:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/05/31 10:10:55 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	int		i;
	int		a;
	char	*dup;

	i = 0;
	a = 0;
	while (src[i] && i < n)
		i++;
	if ((dup = malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	while (a < i)
	{
		dup[a] = src[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}
