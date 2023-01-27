/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/01/27 21:36:08 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Incluindo a biblioteca MinilibX */
# include "solong.h"


int main()
	{
		void	*mlx_ptr; /* a função mlx_init() retorna um identificador que será armazenado em mlx_ptr; */
		void	*win_ptr; /* a função mlx_new_window retorna um identificador para a janela criada */
		
		mlx_ptr = mlx_init(); /* iniciando a conexão com X-server */
		win_ptr = mlx_new_window(mlx_ptr, 500, 300, "Sonic"); /* criando uma janela */
		mlx_loop(mlx_ptr);
	}


