# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 04:29:08 by ckunimur          #+#    #+#              #
#    Updated: 2023/03/01 15:28:00 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc main.c utils.c -lX11 -lXext -lmlx 
# flags para compilação em conjunto com as bibliotecas da minilibx 

clean:
	rm ./a.out

re:	clean all
