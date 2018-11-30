/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:42:44 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 14:55:47 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int c;

	if (s != NULL && f != NULL)
	{
		i = 0;
		c = ft_strlen(s);
		while (i < c)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
