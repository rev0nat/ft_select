/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:43:04 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/05 13:39:08 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		++start;
	if (!s[start])
	{
		if (!(trim = ft_strnew(1)))
			return (0);
		return (trim);
	}
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		--len;
	len = len - start + 1;
	if (!(trim = ft_strsub(s, start, len)))
		return (NULL);
	return (trim);
}
