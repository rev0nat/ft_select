/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:58:34 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 10:48:53 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rep;
	int		i;
	int		p;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	p = ft_strlen(s);
	rep = malloc(sizeof(char) * (p + 1));
	if (!rep)
		return (NULL);
	while (i < p)
	{
		rep[i] = (*f)(*s);
		s++;
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
