/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:24:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:26:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	key_cursor_left(t_rl *rl)
{
	if (rl->index == 0)
		return ;
	if (rl->cx > 0)
	{
		ft_putstr(tgetstr("le", NULL));
		rl->cx--;
	}
	else
		rl->offset--;
	rl->index--;
}

void	key_cursor_right(t_rl *rl)
{
	if (rl->index >= rl->row[rl->cy].bsize || rl->cx > rl->index)
		return ;
	if (rl->cx < rl->win_col - rl->prompt_size)
	{
		ft_putstr(tgetstr("nd", NULL));
		rl->cx++;
	}
	else
		rl->offset++;
	rl->index++;
}

void	key_cursor_beg(t_rl *rl)
{
	while (rl->index)
		key_cursor_left(rl);
}

void	key_cursor_end(t_rl *rl)
{
	while (rl->index < rl->row[rl->cy].bsize)
		key_cursor_right(rl);
}
