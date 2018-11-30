/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:27:40 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/30 15:37:24 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/colors.h"

/*
** DEFINE ERROR CODES
*/
# define USAGE 1
# define USER_HELP 2
# define ERROR_INTERRUPT 3
# define NO_TERM_ENV 4
# define NO_TERM_INFO 5
# define CANT_MODIFY_TERM 6
# define MALLOC_ERROR 7
# define MANUAL_TRANSMISSION_ERROR 8

/*
** DEFINE FILE TYPES
*/
# define C_FILE 1
# define O_FILE 2
# define RB_FILE 3
# define PY_FILE 4
# define SH_FILE 5
# define HTML_FILE 6
# define ISO_FILE 7
# define LIB_FILE 8
# define PDF_FILE 9

/*
*** DEFINE CHARACTERS SEQUENCES
*/
# define KEY_UP 4283163
# define KEY_DOWN 4348699
# define KEY_RIGHT 4414235
# define KEY_LEFT 4479771
# define KEY_SP 32
# define KEY_A 97
# define KEY_U 117
# define KEY_RET 10
# define KEY_ESC 27
# define KEY_ERASE 2117294875
# define KEY_DEL 127
# define KEY_A 97
# define KEY_D 100

typedef struct			s_term_info
{
	struct termios		origin;
	struct termios		capa;
	struct winsize		max;
}						t_term_info;

typedef struct			s_arg_node
{
	char				*name;
	int					x_pos;
	int					y_pos;
	int					underline;
	int					rv;
	int					type;
	int					len;
	struct s_arg_node	*next;
	struct s_arg_node	*prev;
}						t_arg_node;

typedef struct			s_arg_list
{
	t_arg_node			*head;
	t_arg_node			*tail;
	int					len;
	int					max_node_len;
	int					total_node_len;
}						t_arg_list;

typedef struct			s_select
{
	t_term_info			term_info;
	t_arg_list			*arg_list;
}						t_select;

t_select				g_select;

void					init_signals(void);
void					signal_handler(int signo);
void					errors_controller(int errorno);
void					modify_term(void);
void					ft_select(char **av);
t_arg_list				*new_arg_list(void);
void					create_node(char *name);
void					reset_term(void);
void					colors_printer(t_arg_node *arg_node);
void					view_controller(void);
void					get_input(void);
t_arg_node				*get_underlined(void);
void					movement_manager(int keynum);
void					selection_manager(int keynum);
void					action_manager(int keynum);
void					free_arg_list(void);
void					key_esc_fn(void);
void					remove_node(void);
#endif
