/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finishes_by.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:00:10 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/21 16:00:50 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_finishes_by(char *str, char *end)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str || !end)
		return (-1);
	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	while (j >= 0)
	{
		if (str[i] != end[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
