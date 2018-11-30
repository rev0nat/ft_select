/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:12:39 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:02:27 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int	get_file_type(char *name)
{
	if (ft_finishes_by(name, ".c") == 1)
		return (C_FILE);
	else if (ft_finishes_by(name, ".o") == 1)
		return (O_FILE);
	else if (ft_finishes_by(name, ".rb") == 1)
		return (RB_FILE);
	else if (ft_finishes_by(name, ".py") == 1)
		return (PY_FILE);
	else if (ft_finishes_by(name, ".sh") == 1)
		return (SH_FILE);
	else if (ft_finishes_by(name, ".html") == 1 ||\
			ft_finishes_by(name, ".htm") == 1)
		return (HTML_FILE);
	else if (ft_finishes_by(name, ".a") == 1)
		return (LIB_FILE);
	else if (ft_finishes_by(name, ".iso") == 1)
		return (ISO_FILE);
	else if (ft_finishes_by(name, ".pdf") == 1)
		return (PDF_FILE);
	return (0);
}

static void	append_to_arg_list(t_arg_node *arg_node)
{
	if (!g_select.arg_list->head)
	{
		g_select.arg_list->head = arg_node;
		g_select.arg_list->tail = arg_node;
	}
	else
	{
		g_select.arg_list->tail->next = arg_node;
		arg_node->prev = g_select.arg_list->tail;
		g_select.arg_list->tail = arg_node;
	}
	g_select.arg_list->head->prev = g_select.arg_list->tail;
	g_select.arg_list->tail->next = g_select.arg_list->head;
	arg_node->next = g_select.arg_list->head;
	g_select.arg_list->len += 1;
}

void		create_node(char *name)
{
	t_arg_node	*arg_node;
	int			len;

	if (!(arg_node = (t_arg_node*)malloc(sizeof(t_arg_node))))
		errors_controller(MALLOC_ERROR);
	if (!(arg_node->name = ft_strdup(name)))
		errors_controller(MALLOC_ERROR);
	if ((len = ft_strlen(name)) > g_select.arg_list->max_node_len)
		g_select.arg_list->max_node_len = len;
	g_select.arg_list->total_node_len += len + 1;
	arg_node->x_pos = 0;
	arg_node->y_pos = 0;
	arg_node->underline = 0;
	arg_node->rv = 0;
	arg_node->type = get_file_type(name);
	arg_node->len = len;
	append_to_arg_list(arg_node);
}

t_arg_list	*new_arg_list(void)
{
	t_arg_list *arg_list;

	if (!(arg_list = (t_arg_list*)malloc(sizeof(t_arg_list))))
		errors_controller(MALLOC_ERROR);
	arg_list->head = NULL;
	arg_list->tail = NULL;
	arg_list->len = 0;
	arg_list->max_node_len = 0;
	arg_list->total_node_len = 0;
	return (arg_list);
}
