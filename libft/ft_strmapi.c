/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:12:51 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 10:54:14 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	c;
	char			*rep;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	c = ft_strlen(s);
	rep = malloc(sizeof(char) * (c + 1));
	if (!rep)
		return (NULL);
	while (i < c)
	{
		rep[i] = (*f)(i, *s);
		s++;
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
