/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:52:14 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 12:48:05 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_dlist			*g_history = NULL;
int				g_history_size = 0;

static t_dlist	*history_new(void)
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

void			history_add(char *line)
{
	t_dlist	*new;

	if (!line)
		return ;
	new = history_new();
	if (!new)
		return ;
	new->line = ft_strdup(line);
	if (g_history)
	{
		new->next = g_history;
		g_history->prev = new;
	}
	g_history = new;
	g_history_size++;
}
