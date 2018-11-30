/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:45:16 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:43:32 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*sptr;

	sptr = (unsigned char*)str;
	while (n-- > 0)
	{
		if (*sptr == (unsigned char)c)
			return (sptr);
		++sptr;
	}
	return (NULL);
}
