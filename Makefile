# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 04:29:08 by ckunimur          #+#    #+#              #
#    Updated: 2023/03/02 13:55:24 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

GNL_PATH = gnl_42/

GNL_FILES = get_next_line_utils.c get_next_line.c
GNL_OBJS = $(addprefix $(GNL_PATH), $(GNL_FILES: .c=.o))

FILES = so_long.c utils.c
OBJS = $(FILES: .c=.o)

CFLAGS = -Wall -Werror -Wextra -g3
MLX_FLAGS = -lX11 -lXext -lmlx # flags para compilação em conjunto com as bibliotecas da minilibx 

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)
	gcc so_long.c utils.c 

$(NAME): $(GNL_OBJS) $(OBJS)
	cc $(CFLAGS) $^ $(MLX_FLAGS) -o $@


clean:
	rm -f $(GNL_OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re

val: @valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=teste -s 