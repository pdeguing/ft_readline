/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:46:42 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 16:44:29 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	raw_mode_enable(void)
{
	t_termios	raw;
	char		*tname;
	char		tbuf[1024];

	tname = getenv("TERM");
	tgetent(tbuf, tname);
	tcgetattr(STDERR_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
}

void	raw_mode_disable(void)
{
	t_termios	raw;

	tcgetattr(STDERR_FILENO, &raw);
	raw.c_lflag |= (ECHO | ICANON | ISIG);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
}
