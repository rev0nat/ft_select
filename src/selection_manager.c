/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:19:12 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:16:12 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	key_u_fn(void)
{
	t_arg_node *arg_node;
	t_arg_node *tmp;

	arg_node = g_select.arg_list->head;
	tmp = arg_node;
	while (1)
	{
		arg_node->rv = 0;
		arg_node = arg_node->next;
		if (arg_node == tmp)
			break ;
	}
	view_controller();
}

static void	key_a_fn(void)
{
	t_arg_node *arg_node;
	t_arg_node *tmp;

	arg_node = g_select.arg_list->head;
	tmp = arg_node;
	while (1)
	{
		arg_node->rv = 1;
		arg_node = arg_node->next;
		if (arg_node == tmp)
			break ;
	}
	view_controller();
}

static void	key_sp_fn(void)
{
	t_arg_node *arg_node;

	arg_node = get_underlined();
	arg_node->rv = !arg_node->rv;
	arg_node->underline = 0;
	arg_node->next->underline = 1;
	view_controller();
}

void		selection_manager(int keynum)
{
	if (keynum == KEY_SP)
		key_sp_fn();
	else if (keynum == KEY_A)
		key_a_fn();
	else if (keynum == KEY_U)
		key_u_fn();
}
