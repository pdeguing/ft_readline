/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_clipboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:29:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:25:57 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char						*g_clipboard = NULL;

void	key_copy(t_rl *rl)
{
	ft_strdel(&g_clipboard);
	g_clipboard = ft_strdup(rl->row[rl->cy].buf);
}

void	key_paste(t_rl *rl)
{
	ft_strdel(&rl->row[rl->cy].buf);
	rl->row[rl->cy].buf = ft_strdup(g_clipboard);
	rl->row[rl->cy].bsize = ft_strlen(rl->row[rl->cy].buf);
	rl->index = rl->row[rl->cy].bsize;
	rl->cx = ft_min(rl->index, rl->win_col);
}
