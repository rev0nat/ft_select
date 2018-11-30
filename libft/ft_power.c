/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:57:12 by aguillot          #+#    #+#             */
/*   Updated: 2018/02/05 16:46:28 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int pow)
{
	int n;
	int neg;

	if (nb > 45000)
		return (0);
	if (pow == 0)
		return (1);
	n = nb;
	if (nb < 0)
	{
		neg = 1;
		n = -n;
		nb = -nb;
	}
	while (pow > 1)
	{
		nb = nb * n;
		pow--;
	}
	if (neg == 1)
	{
		return (-nb);
	}
	return (nb);
}
