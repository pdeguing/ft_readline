/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:14:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/01 17:55:03 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_keymap g_keymap[KEY_MAX] = {
	{KEY_CURSOR_LEFT, &key_cursor_left},
	{KEY_CURSOR_RIGHT, &key_cursor_right},
	{KEY_DEL_BACKSPACE, &key_del_backspace},
	{KEY_DEL_DELETE, &key_del_delete},
	{KEY_DEL_BEG, &key_del_beg},
	{KEY_DEL_END, &key_del_end},
	{KEY_HISTORY_UP, &key_history_up},
	{KEY_HISTORY_DOWN, &key_history_down},
	{KEY_NEWLINE, &key_newline},
	{KEY_CURSOR_BEG, &key_cursor_beg},
	{KEY_CURSOR_END, &key_cursor_end},
	{KEY_CTL_ARROW, &key_ctl_arrow},
	{KEY_COPY, &key_copy},
	{KEY_PASTE, &key_paste},
	{KEY_SIG_INT, &key_sig_int},
	{KEY_SIG_EOF, &key_sig_eof},
	{KEY_COMPLETION, &key_completion}
};

static int	rl_key_control(t_rl *rl)
{
	int		i;

	i = 0;
	while (i < KEY_MAX)
	{
		if (rl->key == g_keymap[i].key)
		{
			g_keymap[i].f(rl);
			break ;
		}
		i++;
	}
	return (0);
}

static void	rl_loop(t_rl *rl)
{
	while (!rl->status)
	{
		rl_window(rl);
		rl_display_clear(rl);
		rl_display_print(rl);
		rl->key = 0;
		read(0, &rl->key, 4);
		if (rl->key == '\n' && !rl_quote(rl))
			break ;
		if (ft_isprint(rl->key))
			rl_char_insert(rl);
		else
			rl_key_control(rl);
	}
}

char		*ft_readline(const char *prompt, int psize, int mode)
{
	t_rl			*rl;
	char			*line;

	rl = rl_init(mode);
	raw_mode_enable();
	rl->prompt_size = psize;
	if (prompt)
		ft_printf(prompt);
	rl_loop(rl);
	line = NULL;
	if (rl->status >= 0)
		line = rl_row_join(rl);
	rl_free(rl);
	raw_mode_disable();
	ft_putstr("\n");
	return (line);
}
