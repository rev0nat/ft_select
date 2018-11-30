/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:18:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:02:49 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static char	*get_color(int color_id)
{
	if (color_id == C_FILE)
		return (PURPLE);
	else if (color_id == O_FILE)
		return (CYAN);
	else if (color_id == RB_FILE)
		return (BLUE);
	else if (color_id == PY_FILE)
		return (YELLOW);
	else if (color_id == SH_FILE)
		return (GREEN);
	else if (color_id == HTML_FILE)
		return (RED);
	else if (color_id == LIB_FILE)
		return (B_RED);
	else if (color_id == ISO_FILE)
		return (B_GREEN);
	else if (color_id == PDF_FILE)
		return (B_YELLOW);
	return (0);
}

void		colors_printer(t_arg_node *arg_node)
{
	char *cm_cap;

	cm_cap = tgetstr("cm", NULL);
	tputs(tgoto(cm_cap, arg_node->x_pos, arg_node->y_pos), 1, ft_putchar_int);
	ft_putstr_fd(get_color(arg_node->type), STDERR_FILENO);
	if (arg_node->underline == 1)
		tputs(tgetstr("us", NULL), 1, ft_putchar_int);
	if (arg_node->rv == 1)
		tputs(tgetstr("so", NULL), 1, ft_putchar_int);
	ft_putstr_fd(arg_node->name, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	tputs(tgetstr("ue", NULL), 1, ft_putchar_int);
	tputs(tgetstr("se", NULL), 1, ft_putchar_int);
}
