/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:41:27 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 11:14:49 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	d;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	tmp = ft_strdup(s);
	if (!(dest) || !(tmp))
		return (NULL);
	d = 0;
	while (len--)
	{
		dest[d] = tmp[start];
		d++;
		start++;
	}
	dest[d] = '\0';
	free(tmp);
	return (dest);
}
