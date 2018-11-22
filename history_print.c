/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:38:47 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 09:46:07 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	history_print(t_dlist **history)
{
	t_dlist	*last_command;
	t_dlist	*head;

	last_command = (*history);
	head = (*history);
	while (1)
	{
		ft_printf("history: %s\n", head->line);
		head = head->next;
		if (head == last_command)
			break ;
	}
}
