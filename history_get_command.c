/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_get_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:40:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/29 12:29:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char		*history_get_command_back(int number)
{
	t_dlist	*head;

	head = g_history;
	if (!head)
		return (NULL);
	while (number < 0)
	{
		head = head->next;
		if (!head)
			return (NULL);
		number++;
	}
	if (head->line)
		return (ft_strdup(head->line));
	return (NULL);
}

static char		*history_get_command_n(int number)
{
	t_dlist	*head;

	head = g_history;
	if (!head)
		return (NULL);
	while (head && head->next)
		head = head->next;
	while (number > 1)
	{
		head = head->prev;
		if (!head)
			return (NULL);
		number--;
	}
	if (head->line)
		return (ft_strdup(head->line));
	return (NULL);
}

char			*history_get_command(int number)
{
	char	*command;

	command = NULL;
	if (number <= 0)
		command = history_get_command_back(number);
	else
		command = history_get_command_n(number);
	return (command);
}
