/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:20:59 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:43:08 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned char	d;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	d = (unsigned char)c;
	while (n-- > 0)
	{
		if (*psrc == d)
		{
			*pdest = c;
			return (pdest + 1);
		}
		*pdest++ = *psrc++;
	}
	return (NULL);
}
