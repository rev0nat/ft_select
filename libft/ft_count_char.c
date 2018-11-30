/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:11:35 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/07 16:11:44 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				count++;
			i++;
		}
	}
	else
		ft_putstr("Str empty\n");
	return (count);
}
