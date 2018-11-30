/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:52:19 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 10:56:29 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	a;
	size_t	b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + \
				ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[b])
		dest[a++] = s1[b++];
	b = 0;
	while (s2[b])
		dest[a++] = s2[b++];
	dest[a] = '\0';
	return (dest);
}
