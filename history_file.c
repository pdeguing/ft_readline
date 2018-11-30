/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:05:25 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/30 09:20:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	history_file_write(char **args)
{
	char	*filename;
	int		fd;

	if (args && args[2])
		fd = open(args[2], O_RDONLY);
	else
		fd = open(".42sh_history", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_putendl_fd("history_file: open failed", 2);
	else
	{
		history_print(fd, 0);
		close(fd);
	}
}

void	history_file_read(char **args)
{
	int		fd;
	char	*line;

	if (args && args[2])
		fd = open(args[2], O_RDONLY);
	else
		fd = open(".42sh_history", O_RDONLY);
	if (fd == -1)
		return ;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		history_add(line + 6);
		ft_strdel(&line);
	}
	close(fd);
}
