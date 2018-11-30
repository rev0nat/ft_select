/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_art.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:23:33 by aguillot          #+#    #+#             */
/*   Updated: 2018/11/29 15:17:22 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ascii_art(void)
{
	ft_putstr(" ^ ^ ^ ^ ^        FT_SELECT: Utility to search files\n");
	ft_putstr("|         |       - Use arrows to move through selections\n");
	ft_putstr("| x    @  |       - Use space to select/deselect\n");
	ft_putstr("|         |       - Use a/u keys to selectall/deselectall\n");
	ft_putstr(" \\   #   /        - Use enter once you've finished to submit\
			results!\n");
	ft_putstr("                  - Use delete/suppr key to erase a choice\n");
	ft_putstr("                  - Use escape key to flee from the prgrm\n");
}
