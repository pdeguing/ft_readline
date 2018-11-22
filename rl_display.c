/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:28:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 13:28:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_display_clear(t_rl *rl)
{
	ft_putstr(tgetstr("rc", NULL));
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2));
	/*
	ft_putstr(tgetstr("ce", NULL));
	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cr", NULL));
	*/
	ft_putstr(tgetstr("cd", NULL));
}

void	rl_display_print(t_rl *rl)
{
	int	i;

	ft_putstr(tgetstr("sc", NULL));
	if (rl->row[rl->cy].buf)
		ft_putstr(rl->row[rl->cy].buf);
	if (rl->cy == 0)
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size + rl->cx));
	else
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2 + rl->cx));
	i = rl->cy + 1;
	/*
	ft_putstr(tgetstr("sc", NULL));
	while (i < rl->row_max)
	{
		ft_putstr(tgetstr("do", NULL));
		ft_putstr(tgetstr("cr", NULL));
		ft_putstr("> ");
		ft_putstr(rl->row[i].buf);
		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 2 + rl->cx));
		i++;
	}
	ft_putstr(tgetstr("rc", NULL));
	*/
}
