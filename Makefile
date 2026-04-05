# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/28 00:00:00 by opektas           #+#    #+#              #
#    Updated: 2026/03/28 00:00:00 by opektas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr_base.c \
		ft_putnbr.c \
		ft_putptr.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
