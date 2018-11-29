/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 07:36:49 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/29 11:52:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void		history_clear_node(t_dlist *node)
{
	ft_strdel(&node->line);
	free(node);
	node = NULL;
}

void			history_clear_all(void)
{
	t_dlist		*tmp;
	t_dlist		*head;

	head = g_history;
	while (head)
	{
		tmp = head->next;
		history_clear_node(head);
		head = tmp;
	}
	g_history_size = 0;
	g_history = NULL;
}

void			history_clear(int index)
{
	t_dlist	*head;
	int		i;

	head = g_history;
	if (!head || !index || index > g_history_size)
		return ;
	i = 0;
	while (g_history_size - i > index)
	{
		if (!head)
			return ;
		head = head->next;
		i++;
	}
	if (head->prev)
		head->prev->next = head->next;
	if (head->next)
		head->next->prev = head->prev;
	history_clear_node(head);
	g_history_size--;
}
