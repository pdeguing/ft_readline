/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:38:47 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/26 08:43:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	history_print(void)
{
	t_dlist	*last_command;
	t_dlist	*head;

	last_command = g_history;
	head = g_history;
	while (head)
	{
		ft_printf("history: %s\n", head->line);
		head = head->next;
	}
}
