/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:34:27 by ckunimur          #+#    #+#             */
/*   Updated: 2023/02/28 14:41:08 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT (WINDOW_WIDTH / 2)

# define MLX_ERROR 1

typedef struct s_data /*criamos uma struct para manipular diferentes dados em funções passando o parâmetro (t_data)*/
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*aadr;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_data;

/*Funções*/
int ft_destroy_mlx(t_data *data); /*função para fechar as janelas e desalocar memória*/

#endif