/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 06:22:02 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/29 11:54:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void		history_usage(void)
{
	ft_printf("usage: history [n] or history -c or history -d number");
	ft_printf(" or history -w [filename]\n");
}

int				history_builtin(char **args)
{
	if (!args[1])
		history_print(1, 0);
	else if (ft_isdigit(*args[1]))
		history_print(1, ft_atoi(args[1]));
	else if (!ft_strcmp("-c", args[1]))
		history_clear_all();
	else if (!ft_strcmp("-d", args[1]) && (args[2] && ft_isdigit(*args[2])))
		history_clear(ft_atoi(args[2]));
	else if (!ft_strcmp("-w", args[1]))
		history_file_write(args);
	else
		history_usage();
	return (0);
}
