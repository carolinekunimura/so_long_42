/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:34:27 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/01 17:28:13 by ckunimur         ###   ########.fr       */
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

typedef struct s_data /*criamos uma struct para manipular diferentes dados em funções passando o parâmetro (t_data) funciona como um gabario que ira reservar espaço de memória para a quantidade de variáveis declaradas aqui.*/
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		img_width;
	int		img_height;
}	t_data;

/*Funções*/
int ft_destroy_mlx(t_data *data); /*função para fechar as janelas e desalocar memória*/
int	handle_no_event(void *data); /*Essa função serve para tratar eventos vazios ou ausentes, quando nenhum comando(evento) é recebido */
int	handle_input(int keysym, t_data *data); /*Essa função iá receber os eventos do usuário e acionar as funções de acordo com os comandos executados pelo usuário */

#endif