/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 08:43:52 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/29 12:29:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		history_event_command(char *line, char **command, int index)
{
	int			size;
	int			number;

	size = 1;
	number = 0;
	if (line[index] == '!')
		size++;
	else if (line[index] == '-' || ft_isdigit(line[index]))
	{
		number = ft_atoi(line + index);
		while (line[index] && (line[index] == '-' || ft_isdigit(line[index])))
		{
			index++;
			size++;
		}
	}
	*command = history_get_command(number);
	return (size);
}

char			*history_event(char *line, int index)
{
	char		*new;
	char		*prefix;
	char		*command;
	char		*suffix;
	int			size;

	new = NULL;
	command = NULL;
	size = history_event_command(line, &command, index + 1);
	if (!command)
		ft_putendl_fd("history: event incorrect", 2);
	else
	{
		if (index > 0)
			prefix = ft_strsub(line, 0, index);
		else
			prefix = ft_strnew(0);
		new = ft_strfjoin(prefix, command);
		suffix = ft_strsub(line, index + size, ft_strlen(line + index + size));
		new = ft_strfjoin(new, suffix);
	}
	ft_strdel(&line);
	return (new);
}
