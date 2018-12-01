/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:00:06 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 12:48:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_quote_check(int quote, char c)
{
	if (c == '\'' && !(quote & (Q_BSLASH | Q_DQUOTE)))
		quote ^= Q_SQUOTE;
	if (c == '"' && !(quote & (Q_BSLASH | Q_SQUOTE)))
		quote ^= Q_DQUOTE;
	if (c == '`' && !(quote & (Q_BSLASH | Q_SQUOTE)))
		quote ^= Q_BQUOTE;
	if (c == '\\' && (!(quote & (Q_BSLASH | Q_SQUOTE))))
		quote |= Q_BSLASH;
	else
		quote &= ~Q_BSLASH;
	return (quote);
}

int		rl_quote(t_rl *rl)
{
	int		i;
	int		j;

	rl->quote_status = 0;
	if (rl->mode & NO_QUOTE)
		return (rl->quote_status);
	i = 0;
	while (i < rl->row_max)
	{
		j = 0;
		rl->quote_status &= ~Q_BSLASH;
		while (j < rl->row[i].bsize)
		{
			rl->quote_status = rl_quote_check(rl->quote_status,
					rl->row[i].buf[j]);
			j++;
		}
		i++;
	}
	return (rl->quote_status);
}
