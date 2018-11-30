/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:12:28 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/17 17:32:48 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	len = 0;
	if (!dest)
		return (0);
	if (s)
	{
		while (s[len])
		{
			dest[len] = s[len];
			len++;
		}
	}
	dest[len] = '\0';
	return (dest);
}
