/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlinktochar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:46:27 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/24 11:57:46 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlinktochar(char **str, char c)
{
	size_t	str_s;
	char	*tmp;

	str_s = 0;
	if (*str)
		str_s = ft_strlen(*str);
	if (!c)
		return (*str);
	if (!(tmp = (char*)malloc(sizeof(char) * (str_s + 2))))
	{
		free(*str);
		return (NULL);
	}
	ft_memcpy(tmp, *str, str_s);
	tmp[str_s] = c;
	tmp[str_s + 1] = '\0';
	if (*str)
		free(*str);
	return (tmp);
}
