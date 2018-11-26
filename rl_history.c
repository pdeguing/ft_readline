/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:36:42 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/26 08:50:03 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_dlist			*g_history = NULL;

static t_dlist	*rl_history_new(void)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->line = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			rl_history_add(char *line)
{
	t_dlist	*new;

	if (!line)
		return ;
	new = rl_history_new();
	if (!new)
		return ;
	new->line = ft_strdup(line);
	new->prev = NULL;
	new->next = NULL;
	if (g_history)
	{
		new->next = g_history;
		g_history->prev = new;
	}
	g_history = new;
}
