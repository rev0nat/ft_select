/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:08:53 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:06:47 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	key_left_fn(void)
{
	t_arg_node	*arg_node;

	arg_node = get_underlined();
	arg_node->underline = 0;
	arg_node->prev->underline = 1;
	view_controller();
}

static void	key_right_fn(void)
{
	t_arg_node	*arg_node;

	arg_node = get_underlined();
	arg_node->underline = 0;
	arg_node->next->underline = 1;
	view_controller();
}

static void	key_down_fn(void)
{
	t_arg_node	*arg_node;
	int			disp_cols;
	int			i;

	arg_node = get_underlined();
	disp_cols = g_select.term_info.max.ws_col /\
	(g_select.arg_list->max_node_len + 1);
	i = -1;
	arg_node->underline = 0;
	while (++i < disp_cols)
	{
		if (arg_node == g_select.arg_list->tail)
		{
			arg_node->underline = 1;
			view_controller();
			return ;
		}
		arg_node = arg_node->next;
	}
	arg_node->underline = 1;
	view_controller();
}

static void	key_up_fn(void)
{
	t_arg_node	*arg_node;
	int			disp_cols;
	int			i;

	arg_node = get_underlined();
	disp_cols = g_select.term_info.max.ws_col /\
	(g_select.arg_list->max_node_len + 1);
	i = -1;
	arg_node->underline = 0;
	while (++i < disp_cols)
	{
		if (arg_node == g_select.arg_list->head)
		{
			arg_node->underline = 1;
			view_controller();
			return ;
		}
		arg_node = arg_node->prev;
	}
	arg_node->underline = 1;
	view_controller();
}

void		movement_manager(int keynum)
{
	if (keynum == KEY_UP)
		key_up_fn();
	else if (keynum == KEY_DOWN)
		key_down_fn();
	else if (keynum == KEY_RIGHT)
		key_right_fn();
	else if (keynum == KEY_LEFT)
		key_left_fn();
}
