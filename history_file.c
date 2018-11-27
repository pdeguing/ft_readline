/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:05:25 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/27 15:33:14 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	history_file_write(char **args)
{
	char	*filename;
	int		fd;

	if (args[1])
		filename = args[1];
	else
		filename = ft_strdup(".42sh_history");
	fd = open(filename, O_WRONLY | O_CREAT);
	if (fd == -1)
		ft_putendl_fd("history_file_open: open failed", 2);
	else
	{
		history_print(fd, 0);
		close(fd);
	}
	if (!args[1])
		ft_strdel(&filename);
}
