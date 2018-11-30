/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:39:39 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:43:47 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	ptr1 = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (n-- > 1 && ptr1[i] == ptr2[i] && ptr1 && ptr2)
		i++;
	return (ptr1[i] - ptr2[i]);
}
