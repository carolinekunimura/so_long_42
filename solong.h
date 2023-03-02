/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:34:27 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/02 13:40:34 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl_42/get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include "errors.h"

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT (WINDOW_WIDTH / 2)

typedef struct s_data /*criamos uma struct para manipular diferentes dados em funções passando o parâmetro (t_data) funciona como um gabario que ira reservar espaço de memória para a quantidade de variáveis declaradas aqui.*/
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	*capi;
	void	*capi_left;
	void	*capi_right;
	void	*capi_up;
	void	*capi_down;
	void	*lemon_set;
	void	*exit_block;
	void	*exit_open;
	void	*tree_set;
	void	*tile_set;
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