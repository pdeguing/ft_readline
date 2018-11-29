/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 07:58:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/29 11:51:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char		*completion_get(t_list *match, char *word)
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

static t_list	*match_list(t_list *directory, char *word)
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
		while ((entry = readdir(dirp)))
		{
			if (!ft_strncmp(entry->d_name, word, ft_strlen(word)))
				ft_lstadd(&match, ft_lstnew(entry->d_name,
							ft_strlen(entry->d_name) + 1));
		}
		closedir(dirp);
		head = head->next;
	}
	return (match);
}

static t_list	*directory_list(int is_command_name)
{
	char	*env_path;
	char	**path;
	t_list	*directory;
	int		i;

	directory = NULL;
	if (!is_command_name)
	{
		ft_lstadd(&directory, ft_lstnew(".", ft_strlen(".") + 1));
		return (directory);
	}
	env_path = ft_getenv("PATH");
	if (!env_path)
		return (NULL);
	path = ft_strsplit(env_path, ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		ft_lstadd(&directory, ft_lstnew(path[i], ft_strlen(path[i]) + 1));
		i++;
	}
	ft_strvdel(path);
	return (directory);
}

static void		free_list(t_list **ref)
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

char			*rl_completion(t_rl *rl, char *word, int is_command_name)
{
	char	*completion;
	t_list	*directory;
	t_list	*match;

	directory = directory_list(is_command_name);
	match = match_list(directory, word);
	if (!match)
		completion = NULL;
	else if (!match->next)
		completion = ft_strdup(match->content);
	else
		completion = completion_get(match, word);
	free_list(&directory);
	free_list(&match);
	return (completion);
}
