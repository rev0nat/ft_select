/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:39:33 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 16:05:07 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	handle_input(int keynum)
{
	if (keynum == KEY_UP || keynum == KEY_DOWN || keynum == KEY_RIGHT ||\
		keynum == KEY_LEFT)
		movement_manager(keynum);
	else if (keynum == KEY_SP || keynum == KEY_A || keynum == KEY_U)
		selection_manager(keynum);
	else if (keynum == KEY_ESC || keynum == KEY_ERASE || keynum == KEY_DEL ||\
		keynum == KEY_RET)
		action_manager(keynum);
}

void		get_input(void)
{
	int	key_value;

	key_value = 0;
	while (read(0, &key_value, 4) > 0)
	{
		handle_input(key_value);
		key_value = 0;
	}
}
