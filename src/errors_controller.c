/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:37:55 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/30 15:40:09 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	print_usage(void)
{
	ft_putstr("usage: ft_select [file1] [file2] ...\n");
	ft_putstr("For more info: ft_select --help\n");
}

static void	print_user_help(void)
{
	print_usage();
	ft_ascii_art();
}

void		errors_controller(int errorno)
{
	if (g_select.arg_list)
		free_arg_list();
	if (errorno == USAGE)
		print_usage();
	else if (errorno == USER_HELP)
		print_user_help();
	else if (errorno == ERROR_INTERRUPT)
		ft_putstr("Interrupt signal received. Exiting..\n");
	else if (errorno == NO_TERM_ENV)
		ft_putstr("Could not retreive terminal name.\n");
	else if (errorno == NO_TERM_INFO)
		ft_putstr("Could not retreive terminal info.\n");
	else if (errorno == CANT_MODIFY_TERM)
		ft_putstr("Could not set terminal for program use.\n");
	else if (errorno == MALLOC_ERROR)
	{
		reset_term();
		ft_putstr("Malloc error. Not enough space.\n");
	}
	else if (errorno == MANUAL_TRANSMISSION_ERROR)
		ft_putstr("Ioctl couldn't communicate with kernel\n");
	if (g_select.arg_list)
		free_arg_list();
	exit(1);
}
