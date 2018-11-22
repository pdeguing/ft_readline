# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 07:33:11 by pdeguing          #+#    #+#              #
#    Updated: 2018/11/22 08:35:58 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLFAGS		= -Wall -Wextra -Werror

NAME		= ft_readline.a

SRCS		= ft_readline.c rl_char.c rl_display.c \
			  rl_row.c key_clipboard.c key_ctl_arrow.c key_cursor.c \
			  key_del.c key_history.c key_newline.c key_sig.c \
			  raw_mode.c

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