/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:27:50 by aguillot          #+#    #+#             */
/*   Updated: 2018/08/31 13:21:11 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strlink(char **over, char *buff)
{
	int		over_s;
	int		buff_s;
	char	*tmp;

	over_s = 0;
	buff_s = 0;
	if (*over)
		over_s = ft_strlen(*over);
	if (buff)
		buff_s = ft_strlen(buff);
	if (!(tmp = (char*)malloc(sizeof(char) * (buff_s + over_s + 1))))
	{
		free(*over);
		return (NULL);
	}
	ft_memcpy(tmp, *over, over_s);
	ft_memcpy(tmp + over_s, buff, buff_s);
	tmp[over_s + buff_s] = '\0';
	if (over)
		free(*over);
	return (tmp);
}
