/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:32:39 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:56:49 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = i;
	if (size != 0)
	{
		while (src[i - j] && i < size - 1)
		{
			dest[i] = src[i - j];
			i++;
		}
		if (j < size)
			dest[i] = '\0';
	}
	return (ft_strlen(src) + j);
}
