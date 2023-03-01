/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:23:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/01 17:22:57 by ckunimur         ###   ########.fr       */
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

int	handle_no_event(void *data) /*Essa função serve para tratar eventos vazios ou ausentes, quando nenhum comando(evento) é recebido */
{
	return (0);
}
int	handle_input(int keysym, t_data *data) /*Essa função iá receber os eventos do usuário e acionar as funções de acordo com os comandos executados pelo usuário */
{
	printf("%i\n", keysym); /*keysym se refere ao conjunto de símbolos e teclas do sistema, são valores inteiros usados para identificar as teclas em um evento que use teclado*/
	return (0);
}
