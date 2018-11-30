/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:06:47 by aguillot          #+#    #+#             */
/*   Updated: 2018/10/22 14:53:18 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	tmp = (char*)malloc(sizeof(char) * (buff_s + over_s + 1));
	ft_memcpy(tmp, *over, over_s);
	ft_memcpy(tmp + over_s, buff, buff_s);
	tmp[over_s + buff_s] = '\0';
	free(*over);
	return (tmp);
}

int		fill_line(char **over, char **line)
{
	int		i;
	char	*bn;
	char	*tmp;

	if (*over)
	{
		i = 0;
		if ((bn = ft_strchr(*over, '\n')) != 0)
		{
			while ((*over)[i] != '\n')
				i++;
			*line = ft_strsub(*over, 0, i);
			tmp = *over;
			*over = ft_strsub(*over, i + 1, ft_strlen(*over) - i);
			ft_strdel(&tmp);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*over[15000];
	char		buff[BUFF_SIZE + 1];
	int			rd;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (!over[fd])
		if (!(over[fd] = ft_strnew(0)))
			return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		over[fd] = ft_strlink(&over[fd], buff);
		if (fill_line(&over[fd], line) == 1)
			return (1);
	}
	if (fill_line(&over[fd], line) == 1)
		return (1);
	if (over[fd][0])
	{
		*line = ft_strdup(over[fd]);
		ft_strdel(&over[fd]);
		return (1);
	}
	return (0);
}
