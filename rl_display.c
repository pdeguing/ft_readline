/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:28:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 19:59:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		rl_display_clear(t_rl *rl)
{
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2));
	ft_putstr(tgetstr("ce", NULL));
}

void		rl_display_print(t_rl *rl)
{
	int		size;

	if (rl->row[rl->cy].buf)
	{
		size = rl->win_col - rl->prompt_size;
		if (rl->row[rl->cy].bsize >= size)
			ft_printf("%.*s", size, rl->row[rl->cy].buf + rl->offset);
		else
			ft_printf(rl->row[rl->cy].buf);
	}
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size + rl->cx));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2 + rl->cx));
}
