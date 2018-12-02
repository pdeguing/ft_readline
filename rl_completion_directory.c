/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_completion_directory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:52:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 17:02:48 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_list		*rl_completion_directory_list(char *path)
{
	t_list	*directory;

	directory = NULL;
	if (!ft_strchr(path, '/'))
		ft_lstadd(&directory, ft_lstnew(".", ft_strlen(".") + 1));
	else if (path[0] == '/')
		ft_lstadd(&directory, ft_lstnew(path, ft_strlen(path) + 1));
	else
		ft_lstadd(&directory, ft_lstnew(ft_strjoin("./", path),
					ft_strlen(path) + 3));
	return (directory);
}

static t_list		*rl_completion_directory_path(void)
{
	char	*env_path;
	char	**path;
	t_list	*directory;
	int		i;

	directory = NULL;
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

t_list				*rl_completion_directory(char *path, int is_command_name)
{
	if (ft_strchr(path, '/') || !is_command_name)
		return (rl_completion_directory_list(path));
	else
		return (rl_completion_directory_path());
}
