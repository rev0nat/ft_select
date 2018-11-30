/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:25:47 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:15:41 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		init_signals(void)
{
	signal(SIGTERM, &signal_handler);
	signal(SIGABRT, &signal_handler);
	signal(SIGINT, &signal_handler);
	signal(SIGQUIT, &signal_handler);
	signal(SIGWINCH, &signal_handler);
	signal(SIGTSTP, &signal_handler);
	signal(SIGCONT, &signal_handler);
}

static void	init_term(void)
{
	char		*term;
	t_term_info	term_info;
	int			ret;

	if (!(term = getenv("TERM")))
		errors_controller(NO_TERM_ENV);
	if ((ret = tgetent(NULL, term)) == -1)
		errors_controller(NO_TERM_INFO);
	if (tcgetattr(STDERR_FILENO, &term_info.origin) == -1 ||\
		tcgetattr(STDERR_FILENO, &term_info.capa) == -1 ||\
		ioctl(STDERR_FILENO, TIOCGWINSZ, &term_info.max) == -1)
		errors_controller(NO_TERM_INFO);
	g_select.term_info = term_info;
}

void		reset_term(void)
{
	if ((tcsetattr(STDERR_FILENO, TCSADRAIN, &g_select.term_info.origin)) == -1)
		errors_controller(CANT_MODIFY_TERM);
	tputs(tgetstr("te", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
}

void		modify_term(void)
{
	g_select.term_info.capa.c_lflag &= ~(ICANON | ECHO);
	g_select.term_info.capa.c_cc[VMIN] = 1;
	g_select.term_info.capa.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSADRAIN, &g_select.term_info.capa);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
}

int			main(int ac, char **av)
{
	init_signals();
	if (ac <= 1)
		errors_controller(USAGE);
	else
	{
		if (ft_strcmp(av[1], "--help") == 0)
			errors_controller(USER_HELP);
		init_term();
		modify_term();
		ft_select(av);
	}
}
