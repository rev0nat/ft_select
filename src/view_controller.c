/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:59:45 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:08:39 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	calculate_pos(t_arg_node *arg_node, int *y)
{
	int max_node_len;

	max_node_len = g_select.arg_list->max_node_len + 1;
	if (arg_node == g_select.arg_list->head)
	{
		arg_node->x_pos = 0;
		arg_node->y_pos = 0;
		return ;
	}
	if ((arg_node->x_pos = arg_node->prev->x_pos + max_node_len) >\
		(g_select.term_info.max.ws_col - max_node_len - 1))
	{
		arg_node->x_pos = 0;
		*y += 1;
	}
	arg_node->y_pos = *y;
}

static void	print_list(void)
{
	t_arg_node	*arg_node;
	int			y;

	arg_node = g_select.arg_list->head;
	y = 0;
	while (arg_node)
	{
		calculate_pos(arg_node, &y);
		colors_printer(arg_node);
		arg_node = arg_node->next;
		if (arg_node == g_select.arg_list->head)
			break ;
	}
}

static int	check_conditions(void)
{
	int	nb_char;
	int	disp_cols;

	nb_char = g_select.term_info.max.ws_col * g_select.term_info.max.ws_row;
	disp_cols = g_select.term_info.max.ws_col /\
				(g_select.arg_list->max_node_len + 1);
	disp_cols *= g_select.term_info.max.ws_row;
	if (g_select.arg_list->max_node_len > g_select.term_info.max.ws_col ||\
		g_select.arg_list->total_node_len > nb_char ||\
		disp_cols < g_select.arg_list->len)
		return (-1);
	return (1);
}

static void	clean_screen(void)
{
	char	*cm_cap;
	int		i;

	cm_cap = tgetstr("cm", NULL);
	tputs(tgoto(cm_cap, 0, 0), 1, ft_putchar_int);
	i = -1;
	while (++i < g_select.term_info.max.ws_row)
		tputs(tgetstr("dl", NULL), 1, ft_putchar_int);
}

void		view_controller(void)
{
	clean_screen();
	if (check_conditions() > -1)
		print_list();
}
