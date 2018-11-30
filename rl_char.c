/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:06:46 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:27:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void			rl_char_insert(t_rl *rl)
{
	char *tmp;

	tmp = rl->row[rl->cy].buf;
	rl->row[rl->cy].bsize++;
	rl->row[rl->cy].buf = ft_strnew(rl->row[rl->cy].bsize + 1);
	if (tmp)
	{
		ft_strcpy(rl->row[rl->cy].buf, tmp);
		ft_memmove(rl->row[rl->cy].buf + rl->index + 1,
				rl->row[rl->cy].buf + rl->index,
				rl->row[rl->cy].bsize - rl->index);
	}
	rl->row[rl->cy].buf[rl->index] = rl->key;
	ft_strdel(&tmp);
	key_cursor_right(rl);
}
