/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctl_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:52:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:11:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	key_ctl_arrow(t_rl *rl)
{
	rl->key = 0;
	read(0, &rl->key, 4);
	if (rl->key == KEY_CTL_UP)
		key_ctl_up(rl);
	else if (rl->key == KEY_CTL_DOWN)
		key_ctl_down(rl);
	else if (rl->key == KEY_CTL_LEFT)
		key_ctl_left(rl);
	else if (rl->key == KEY_CTL_RIGHT)
		key_ctl_right(rl);
}

void	key_ctl_up(t_rl *rl)
{
	if (rl->cy == 0)
		return ;
	ft_putstr(tgetstr("up", NULL));
	rl->cy--;
	if (rl->cx > rl->row[rl->cy].bsize)
		rl->cx = rl->row[rl->cy].bsize;
	if (rl->index > rl->row[rl->cy].bsize)
		rl->index = rl->row[rl->cy].bsize;
}

void	key_ctl_down(t_rl *rl)
{
	if (rl->cy >= rl->row_max - 1)
		return ;
	ft_putstr(tgetstr("do", NULL));
	rl->cy++;
	if (rl->cx > rl->row[rl->cy].bsize)
		rl->cx = rl->row[rl->cy].bsize;
	if (rl->index > rl->row[rl->cy].bsize)
		rl->index = rl->row[rl->cy].bsize;
}

void	key_ctl_left(t_rl *rl)
{
	while (rl->index && !ft_strchr(" 	", rl->row[rl->cy].buf[rl->index]))
		key_cursor_left(rl);
	while (rl->index && ft_strchr(" 	", rl->row[rl->cy].buf[rl->index]))
		key_cursor_left(rl);
}

void	key_ctl_right(t_rl *rl)
{
	while (rl->index < rl->row[rl->cy].bsize &&
			!ft_strchr(" 	", rl->row[rl->cy].buf[rl->index]))
		key_cursor_right(rl);
	while (rl->index < rl->row[rl->cy].bsize &&
			ft_strchr(" 	", rl->row[rl->cy].buf[rl->index]))
		key_cursor_right(rl);
}
