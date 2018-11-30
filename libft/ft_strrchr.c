/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:17:57 by aguillot          #+#    #+#             */
/*   Updated: 2017/12/01 15:00:45 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	while (str_len != 0 && str[str_len] != ((unsigned char)c))
		str_len--;
	if (str[str_len] == ((unsigned char)c))
		return ((char*)&str[str_len]);
	return (0);
}
