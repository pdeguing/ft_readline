/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 06:22:02 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/27 08:43:26 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		history_builtin(char **args)
{
	if (!args[0])
		history_print(0);
	else if (ft_isdigit(*args[0]))
		history_print(ft_atoi(args[0]));
	else if (!ft_strcmp("-c", args[0]))
		history_clear_all();
	else if (!ft_strcmp("-d", args[0]))
	{
		if (args[1] && ft_isdigit(*args[1]))
			history_clear(ft_atoi(args[1]));
		/*
		else
			print_error();
			*/
	}
	/*
	else if (!ft_strcmp("-w", args[0]))
	else
		print_error();
		*/
	return (0);
}
