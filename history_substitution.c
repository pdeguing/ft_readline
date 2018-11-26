/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_substitution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:00:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/26 11:19:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char			*history_substitution(char *line)
{
	int			i;
	int			quote;

	if (!line)
		return (NULL);
	i = 0;
	quote = 0;
	while (line[i])
	{
		quote = rl_quote_check(quote, line[i]);
		if (!(quote & (Q_BSLASH | Q_SQUOTE)) && line[i] == '!'
				&& !ft_strchr(" 	\n", line[i + 1]))
		{
			line = history_event(line, i);
			if (!line)
				return (NULL);
			i = 0;
			quote = 0;
		}
		i++;
	}
	return (line);
}
