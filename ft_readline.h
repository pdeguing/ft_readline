/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 07:24:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 08:25:39 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <termios.h>
# include <termcap.h>
# include "../libft/includes/libft.h"

typedef struct s_dlist		t_dlist;
typedef struct s_io			t_io;
typedef struct s_keymap		t_keymap;
typedef struct termios		t_termios;
typedef struct s_rl			t_rl;
typedef struct s_row		t_row;


/* History ****************************************************************** */

struct						s_dlist
{
	char					*line;
	t_dlist					*prev;
	t_dlist					*next;
};

t_dlist						*history_new(void);

void						history_add(char *line, t_dlist **history);
void						history_print(t_dlist **history);

/* Readline ****************************************************************** */

/* Execution modes */

# define DEFAULT			0x0
# define NO_QUOTE			0b0000001
# define NO_HISTORY			0b0000010

# define IS_QUOTE(c)		ft_strchr("\\\'\"", c)

# define Q_BSLASH			0b00000001
# define Q_SQUOTE			0b00000010
# define Q_DQUOTE			0b00000100

struct						s_row
{
	int						bsize;
	char					*buf;
};

enum						e_keys
{
	 KEY_CURSOR_LEFT = 4479771,
	 KEY_CURSOR_RIGHT = 4414235,
	 KEY_DEL_BACKSPACE = 127,
	 KEY_DEL_DELETE = 2117294875,
	 KEY_DEL_BEG = 21,
	 KEY_DEL_END = 11,
	 KEY_HISTORY_UP = 4283163,
	 KEY_HISTORY_DOWN = 4348699,
	 KEY_HISTORY_SEARCH,
	 KEY_CURSOR_BEG = 4741915,
	 KEY_CURSOR_END = 4610843,
	 KEY_CTL_ARROW = 993090331,
	 KEY_NEWLINE = 10,
	 KEY_COPY = 16,
	 KEY_PASTE = 12,
	 KEY_SIG_INT = 3,
	 KEY_SIG_EOF = 4,
	 KEY_MAX = 16
};


# define KEY_CTL_UP			16693
# define KEY_CTL_DOWN		16949
# define KEY_CTL_LEFT		17461
# define KEY_CTL_RIGHT		17205

struct						s_keymap
{
	int						key;
	void					(*f)(t_rl *);
};

void						key_cursor_left(t_rl *rl);
void						key_cursor_right(t_rl *rl);
void						key_del_backspace(t_rl *rl);
void						key_del_delete(t_rl *rl);
void						key_del_beg(t_rl *rl);
void						key_del_end(t_rl *rl);
void						key_history_up(t_rl *rl);
void						key_history_down(t_rl *rl);
void						key_newline(t_rl *rl);
void						key_cursor_beg(t_rl *rl);
void						key_cursor_end(t_rl *rl);
void						key_copy(t_rl *rl);
void						key_paste(t_rl *rl);
void						key_sig_int(t_rl *rl);
void						key_sig_eof(t_rl *rl);
void						key_ctl_arrow(t_rl *rl);
void						key_ctl_up(t_rl *rl);
void						key_ctl_down(t_rl *rl);
void						key_ctl_left(t_rl *rl);
void						key_ctl_right(t_rl *rl);

struct						s_rl
{
	int						key;
	t_row					*row;
	int						row_max;
	int						prompt_size;
	int						quote_status;
	int						cx;
	int						cy;
	int						win_col;
	int						win_row;
	t_dlist					*history_head;
	int						history_state;
	int						status;
};

void						raw_mode_enable(void);
void						raw_mode_disable(void);

void						rl_char_insert(t_rl *rl);

void						rl_row_insert(t_rl *rl, char *buf);
char						*rl_row_join(t_rl *rl);

void						rl_display_print(t_rl *rl);
void						rl_display_clear(t_rl *rl);

char						*rl_readline(const char *prompt, int psize, int mode);






#endif
