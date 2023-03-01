/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:23:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/02/27 11:39:49 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_destroy_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr); /* Apagando a janela criada para exibir a tela do jogo*/
	mlx_destroy_display(data->mlx_ptr); /* Apagando a tela do jogo */
	free(data->mlx_ptr); /* Liberando o espaço alocado pelo programa */
	exit(0);
}