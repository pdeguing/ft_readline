/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_completion_match.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:42:30 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 17:02:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char		*rl_completion_match_get(t_list *match, char *word)
{
	int		i;
	int		is_match;
	char	to_match;
	t_list	*head;

	i = ft_strlen(word);
	is_match = 1;
	while (is_match)
	{
		head = match;
		to_match = *((char *)head->content + i);
		while (head)
		{
			if (!(is_match = (*((char *)head->content + i)
							&& *((char *)head->content + i) == to_match)))
				break ;
			head = head->next;
		}
		i++;
	}
	i--;
	if (i > ft_strlen(word))
		return (ft_strndup(match->content, i));
	return (NULL);
}

static t_list	*rl_completion_match_list(t_list *directory, char *file)
{
	struct dirent	*entry;
	DIR				*dirp;
	t_list			*head;
	t_list			*match;

	head = directory;
	match = NULL;
	while (head)
	{
		dirp = opendir(head->content);
		head = head->next;
		if (!dirp)
			continue ;
		while ((entry = readdir(dirp)))
		{
			if (!ft_strncmp(entry->d_name, file, ft_strlen(file)))
				ft_lstadd(&match, ft_lstnew(entry->d_name,
							ft_strlen(entry->d_name) + 1));
		}
		closedir(dirp);
	}
	return (match);
}

char			*rl_completion_match(t_list *directory, char *file)
{
	t_list	*match;
	char	*completion;

	match = rl_completion_match_list(directory, file);
	if (!match)
		completion = NULL;
	else if (!match->next)
		completion = ft_strdup(match->content);
	else
		completion = rl_completion_match_get(match, file);
	rl_free_list(&match);
	return (completion);
}
