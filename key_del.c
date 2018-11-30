/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:22:53 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:13:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	key_del_backspace(t_rl *rl)
{
	if (!(rl->index > 0))
		return ;
	ft_memmove(rl->row[rl->cy].buf + rl->index - 1, rl->row[rl->cy].buf
			+ rl->index, rl->row[rl->cy].bsize - rl->index + 1);
	rl->row[rl->cy].bsize--;
	key_cursor_left(rl);
}

void	key_del_delete(t_rl *rl)
{
	if (!(rl->index < rl->row[rl->cy].bsize))
		return ;
	ft_memmove(rl->row[rl->cy].buf + rl->index,
			rl->row[rl->cy].buf + rl->index + 1,
			rl->row[rl->cy].bsize - rl->index + 1);
	rl->row[rl->cy].bsize--;
}

void	key_del_beg(t_rl *rl)
{
	while (rl->index)
		key_del_backspace(rl);
}

void	key_del_end(t_rl *rl)
{
	while (rl->index < rl->row[rl->cy].bsize)
		key_del_delete(rl);
}
