/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:52:16 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/06/02 10:54:00 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char const *s2)
{
	int		size;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((new = malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	new[size] = '\0';
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	ft_strdel(&s1);
	return (new);
}
