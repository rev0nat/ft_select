/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:49:41 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:07:49 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	stop_received(void)
{
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	signal(SIGTSTP, SIG_DFL);
	reset_term();
}

static void	window_modif(void)
{
	if ((ioctl(STDERR_FILENO, TIOCGWINSZ, &g_select.term_info.max)) == -1)
		errors_controller(NO_TERM_INFO);
	view_controller();
}

static void	cont_received(void)
{
	init_signals();
	modify_term();
	window_modif();
}

void		signal_handler(int signo)
{
	if (signo == SIGWINCH)
		window_modif();
	else if (signo == SIGTERM || signo == SIGINT || signo == SIGQUIT ||\
			signo == SIGABRT)
	{
		reset_term();
		exit(1);
	}
	else if (signo == SIGTSTP)
		stop_received();
	else if (signo == SIGCONT)
		cont_received();
}
