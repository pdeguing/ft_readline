/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:28:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 16:46:16 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_display_clear(t_rl *rl)
{
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2));
	ft_putstr(tgetstr("ce", NULL));
}

void	rl_display_print(t_rl *rl)
{
	int	i;

	if (rl->row[rl->cy].buf)
		ft_putstr(rl->row[rl->cy].buf);
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size + rl->cx));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2 + rl->cx));
}
