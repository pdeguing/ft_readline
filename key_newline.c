/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:38:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 12:42:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	key_newline(t_rl *rl)
{
	rl_row_insert(rl, NULL);
	rl->cx = 0;
	rl->index = 0;
	rl->cy++;
	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr("> ");
	ft_putstr(tgetstr("sc", NULL));
}
