# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 16:49:04 by ckunimur          #+#    #+#              #
#    Updated: 2023/04/03 12:36:23 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJS = $(SOURCES:%.c=%.o)

GNL_PATH = gnl/
GNL_FILES = get_next_line.c get_next_line_utils.c 

SOURCES = so_long.c utils.c map_rules.c images_rules.c ft_itoa.c map_utils.c images_utils.c
SOURCES += $(addprefix $(GNL_PATH), $(GNL_FILES))

MLX_FLAGS = -lmlx -lXext -lX11

FLAGS = -Wall -Werror -Wextra -g3

%.o: %.c
	cc -c $< $(FLAGS) -o $@ 

all: $(NAME)

$(NAME): $(OBJS) 
		cc $(OBJS) $(MLX_FLAGS) $(FLAGS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
