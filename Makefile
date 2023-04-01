# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 16:49:04 by ckunimur          #+#    #+#              #
#    Updated: 2023/03/22 16:57:11 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJS = $(SOURCES:%.c=%.o)

SOURCES = so_long.c

MLX_FLAGS = -lmlx -lXext -lX11

FLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS) 
		cc $(OBJS) $(MLX_FLAGS) $(FLAGS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re