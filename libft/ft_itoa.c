/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:31 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 15:25:45 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_itoa_neg(int n, int i)
{
	char	*dest;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = -n;
	nb = n;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	if (!(dest = (char*)malloc(sizeof(char) * (i + 2))))
		return (0);
	dest[0] = '-';
	dest[i + 1] = '\0';
	while (i > 0)
	{
		dest[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (dest);
}

char			*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*dest;

	nb = n;
	i = 0;
	if (nb < 0)
		return (ft_itoa_neg(nb, i));
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		dest[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (dest);
}
