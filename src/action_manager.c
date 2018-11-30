/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:29:49 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:15:19 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		key_esc_fn(void)
{
	free_arg_list();
	reset_term();
	exit(0);
}

static void	key_ret_fn(void)
{
	t_arg_node	*arg_node;

	arg_node = g_select.arg_list->head;
	reset_term();
	while (1)
	{
		if (arg_node->rv == 1)
		{
			ft_putstr(arg_node->name);
			ft_putchar(' ');
		}
		arg_node = arg_node->next;
		if (arg_node == g_select.arg_list->head)
			break ;
	}
	exit(0);
}

void		action_manager(int keynum)
{
	if (keynum == KEY_ESC)
		key_esc_fn();
	else if (keynum == KEY_DEL || keynum == KEY_ERASE)
		remove_node();
	else if (keynum == KEY_RET)
		key_ret_fn();
}
