/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 06:22:02 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/27 15:33:15 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void		history_usage()
{
	ft_printf("usage: history [n] or history -c or history -d number \
			or history -w [filename]\n"); 
}

int		history_builtin(char **args)
{
	if (!args[0])
		history_print(1, 0);
	else if (ft_isdigit(*args[0]))
		history_print(1, ft_atoi(args[0]));
	else if (!ft_strcmp("-c", args[0]))
		history_clear_all();
	else if (!ft_strcmp("-d", args[0]) && (args[1] && ft_isdigit(*args[1])))
			history_clear(ft_atoi(args[1]));
	else if (!ft_strcmp("-w", args[0]))
		history_file_write(args);
	else
		history_usage();
	return (0);
}
