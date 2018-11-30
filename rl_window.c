/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:31:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 11:16:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_window(t_rl *rl)
{
	t_winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	rl->win_col = window.ws_col;
	rl->win_row = window.ws_row;
}
