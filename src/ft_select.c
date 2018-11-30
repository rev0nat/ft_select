/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:54:09 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:04:52 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	parse_av(char **av)
{
	int i;

	i = 0;
	while (av[++i])
		create_node(av[i]);
	g_select.arg_list->head->underline = 1;
}

void		ft_select(char **av)
{
	g_select.arg_list = new_arg_list();
	parse_av(av);
	view_controller();
	get_input();
}
