# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 07:33:11 by pdeguing          #+#    #+#              #
#    Updated: 2018/12/01 09:55:01 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLFAGS		= -Wall -Wextra -Werror

NAME		= libft_readline.a

SRCS		= ft_readline.c rl_char.c rl_display.c rl_quote.c \
			  rl_row.c key_clipboard.c key_ctl_arrow.c key_cursor.c \
			  key_del.c key_history.c key_newline.c key_sig.c key_completion.c \
			  raw_mode.c history_list.c rl_free.c history_print.c rl_init.c \
			  history_substitution.c history_event.c history_get_command.c \
			  history_builtin.c history_clear.c history_file.c rl_completion.c \
			  rl_window.c ft_min.c rl_completion_match.c rl_completion_directory.c

all: $(NAME)

$(NAME): cmp 
	@ ar rcs $(NAME) *.o 
	@ ranlib $(NAME)

cmp:
	@ gcc -c $(CFLAGS) $(SRCS)

clean:
	@ /bin/rm -f *.o

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

norm:
	@ norminette $(SRCS) ft_readline.h

.PHONY: clean fclean all re
