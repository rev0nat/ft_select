/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:34:48 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/02 18:35:50 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strichr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != ((unsigned char)c))
		i++;
	if (str[i] == (unsigned char)c)
		return (i);
	return (-1);
}
