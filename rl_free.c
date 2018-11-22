/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:59:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 11:36:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_free(t_rl *rl)
{
	int		i;

	i = 0;
	while (i < rl->row_max)
	{
		if (rl->row[i].buf)
			ft_strdel(&rl->row[i].buf);
		i++;
	}
	free(rl->row);
	free(rl);
}
