/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:03:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 12:26:25 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rl	*rl_init(int mode)
{
	t_rl	*new;

	new = (t_rl *)malloc(sizeof(t_rl));
	if (!new)
		return (NULL);
	new->key = 0;
	new->row = NULL;
	new->row_max = 0;
	new->index = 0;
	new->offset = 0;
	rl_row_insert(new, NULL);
	new->prompt_size = 0;
	new->quote_status = 0;
	new->cx = 0;
	new->cy = 0;
	new->win_col = 0;
	new->win_row = 0;
	new->status = 0;
	new->history_head = g_history;
	new->history_status = 0;
	new->mode = mode;
	return (new);
}
