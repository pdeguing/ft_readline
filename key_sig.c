/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:01:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 08:22:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	key_sig_int(t_rl *rl)
{
	rl->status = -1;
}

void	key_sig_eof(t_rl *rl)
{
	if (!rl->row[0].bsize)
	{
		rl->row[0].buf = ft_strdup("exit");
		rl->row[0].bsize = ft_strlen(rl->row[0].buf);
		rl->status = 1;
	}
}
