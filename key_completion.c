/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_completion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:16:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 13:27:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		word_begin(t_rl *rl)
{
	int		i;

	i = rl->index;
	while (i > 0)
	{
		i--;
		if (ft_strchr(" ;|", rl->row[rl->cy].buf[i]))
		{
			i++;
			break ;
		}
	}
	return (i);
}

static int		word_get(char **pstr, t_rl *rl)
{
	char	*word;
	int		i;
	int		size;

	i = word_begin(rl);
	size = rl->index - i;
	word = ft_strnew(size);
	ft_strncpy(word, &rl->row[rl->cy].buf[i], size);
	*pstr = word;
	while (i > 0 && !ft_strchr(";|", rl->row[rl->cy].buf[i]))
	{
		if (ft_strchr(" 	", rl->row[rl->cy].buf[i]))
			return (0);
		i--;
	}
	return (1);
}

static void		replace_buf(t_rl *rl, char *new, char *str, char *word)
{
	int	size;
	int	index;

	size = word_begin(rl);
	ft_memcpy(new, rl->row[rl->cy].buf, size);
	index = size;
	size = ft_strlen(str);
	ft_memcpy(new + index, str, size);
	index += size;
	size = word_begin(rl) + ft_strlen(word);
	ft_memcpy(new + index, rl->row[rl->cy].buf + size,
			rl->row[rl->cy].bsize - size);
	ft_strdel(&rl->row[rl->cy].buf);
	rl->row[rl->cy].buf = new;
	rl->row[rl->cy].bsize = ft_strlen(new);
	rl->index = rl->row[rl->cy].bsize;
	rl->cx = ft_min(rl->index, rl->win_col);
}

void			key_completion(t_rl *rl)
{
	char	*str;
	char	*word;
	int		is_command_name;
	char	*new;
	int		size;

	word = NULL;
	is_command_name = word_get(&word, rl);
	str = rl_completion(rl, word, is_command_name);
	if (str)
	{
		size = rl->row[rl->cy].bsize + ft_strlen(str) - ft_strlen(word);
		new = ft_strnew(size);
		replace_buf(rl, new, str, word);
	}
	ft_strdel(&word);
	ft_strdel(&str);
}
