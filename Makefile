# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 19:23:19 by yli               #+#    #+#              #
#    Updated: 2023/01/25 19:23:22 by yli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Werror -Wextra
CC = cc
SRCS = main.c pipex_util.c pipex.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(CFLAGS)

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	rm -f pipex

re: fclean
	make all

PHONY: all clean fclean re

