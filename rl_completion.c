/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 07:58:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 11:35:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void			rl_free_list(t_list **ref)
{
	t_list		*head;
	t_list		*tmp;

	head = *ref;
	while (head)
	{
		ft_strdel((char **)&head->content);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*ref = NULL;
}

static void		word_split(char *word, char **path, char **file)
{
	int		i;

	i = ft_strlen(word) - 1;
	while (i >= 0 && word[i] != '/')
		i--;
	i++;
	*path = ft_strsub(word, 0, i);
	*file = ft_strsub(word, i, ft_strlen(word) - i);
}

char			*rl_completion(t_rl *rl, char *word, int is_command_name)
{
	t_list	*directory;
	char	*path;
	char	*file;
	char	*match;
	char	*tmp;

	path = NULL;
	file = NULL;
	word_split(word, &path, &file);
	directory = rl_completion_directory(path, is_command_name);
	match = rl_completion_match(directory, file);
	rl_free_list(&directory);
	ft_strdel(&file);
	if (path && match)
	{
		tmp = match;
		match = ft_strjoin(path, match);
		ft_strdel(&tmp);
	}
	ft_strdel(&path);
	return (match);
}
