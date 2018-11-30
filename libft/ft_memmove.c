/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:43:30 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:44:35 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	if (src < dest)
	{
		while (n-- > 0)
			pdest[n] = psrc[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
