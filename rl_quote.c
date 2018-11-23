/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:00:06 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 17:18:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		rl_quote_check(int quote, char c)
{
	if (c == '\'' && !(quote & (Q_BSLASH | Q_DQUOTE)))
		quote ^= Q_SQUOTE;
	if (c == '"' && !(quote & (Q_BSLASH | Q_SQUOTE)))
		quote ^= Q_DQUOTE;
	if (c == '\\' && (!(quote & (Q_BSLASH | Q_SQUOTE))))
		quote |= Q_BSLASH;
	else
		quote &= ~Q_BSLASH;
	return (quote);
}

int				rl_quote(t_rl *rl)
{
	int		i;
	int		j;
	int		quote;

	quote = 0;
	if (rl->mode & NO_QUOTE)
		return (quote);
	i = 0;
	while (i < rl->row_max)
	{
		j = 0;
		while (j < rl->row[i].bsize)
		{
			quote = rl_quote_check(quote, rl->row[i].buf[j]);
			j++;
		}
		i++;
	}
	return (quote);
}
