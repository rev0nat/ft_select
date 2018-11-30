/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:57:39 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:08:03 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_arg_node	*get_underlined(void)
{
	t_arg_node *arg_node;

	arg_node = g_select.arg_list->head;
	while (1)
	{
		if (arg_node->underline == 1)
			return (arg_node);
		arg_node = arg_node->next;
	}
}

void		free_arg_list(void)
{
	t_arg_node	*arg_node;
	t_arg_node	*tmp;

	tmp = NULL;
	arg_node = g_select.arg_list->head->next;
	while (arg_node != g_select.arg_list->head)
	{
		ft_strdel(&arg_node->name);
		tmp = arg_node;
		arg_node = arg_node->next;
		free(tmp);
	}
	ft_strdel(&g_select.arg_list->head->name);
	free(g_select.arg_list->head);
	g_select.arg_list->head = NULL;
	free(g_select.arg_list);
	g_select.arg_list = NULL;
}

static void	free_node_and_display(t_arg_node *arg_node)
{
	arg_node->prev->next = arg_node->next;
	arg_node->next->prev = arg_node->prev;
	ft_strdel(&arg_node->name);
	free(arg_node);
	g_select.arg_list->len -= 1;
	view_controller();
}

void		remove_node(void)
{
	t_arg_node	*arg_node;
	t_arg_node	*tmp;

	arg_node = get_underlined();
	tmp = NULL;
	if (arg_node == g_select.arg_list->head)
	{
		if (arg_node == g_select.arg_list->tail)
			key_esc_fn();
		g_select.arg_list->head = arg_node->next;
		g_select.arg_list->tail->next = g_select.arg_list->head;
	}
	else if (arg_node == g_select.arg_list->tail)
	{
		tmp = g_select.arg_list->tail;
		g_select.arg_list->tail = arg_node->prev;
		g_select.arg_list->head->prev = g_select.arg_list->tail;
		g_select.arg_list->tail->underline = 1;
	}
	if (arg_node != tmp)
		arg_node->next->underline = 1;
	free_node_and_display(arg_node);
}
