/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:06:46 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 08:23:01 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void		rl_char_quote(t_rl *rl)
{
	if (rl->key == '\'' && !(rl->quote_status & (Q_BSLASH | Q_DQUOTE)))
		rl->quote_status ^= Q_SQUOTE;
	if (rl->key == '"' && !(rl->quote_status & (Q_BSLASH | Q_SQUOTE)))
		rl->quote_status ^= Q_DQUOTE;
	if (rl->key == '\\' && (!(rl->quote_status & (Q_BSLASH | Q_SQUOTE))))
		rl->quote_status |= Q_BSLASH;
	else
		rl->quote_status &= ~Q_BSLASH;
}

void			rl_char_insert(t_rl *rl)
{
	char *tmp;

	if (IS_QUOTE(rl->key))
		rl_char_quote(rl);
	tmp = rl->row[rl->cy].buf;
	rl->row[rl->cy].bsize++;
	rl->row[rl->cy].buf = ft_strnew(rl->row[rl->cy].bsize + 1);
	if (tmp)
	{
		ft_strcpy(rl->row[rl->cy].buf, tmp);
		ft_memmove(rl->row[rl->cy].buf + rl->cx + 1,
				rl->row[rl->cy].buf + rl->cx, rl->row[rl->cy].bsize - rl->cx);
	}
	rl->row[rl->cy].buf[rl->cx] = rl->key;
	ft_strdel(&tmp);
	key_cursor_right(rl);
}
