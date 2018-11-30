/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:45:50 by aguillot          #+#    #+#             */
/*   Updated: 2017/11/29 13:39:06 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	if (*n == '\0')
		return (char*)(h);
	i = ft_strlen(n);
	while (*h && len-- >= i)
	{
		if (*h == *n && ft_memcmp(h, n, i) == 0)
			return ((char*)h);
		h++;
	}
	return (0);
}
