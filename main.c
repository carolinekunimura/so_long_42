/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/01 15:13:24 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

int	handle_no_event(void *data) /*Essa função serve para tratar eventos vazios ou ausentes, quando nenhuma é envida pelo usuário */
{
	return (0);
}
int	handle_input(int keysym, t_data *data) /*Essa função iá receber os eventos do usuário e acionar as funções de acordo com os comandos executados pelo usuário */
{
	printf("%i\n", keysym); /*keysym se refere ao conjunto de símbolos e teclas do sistema, são valores inteiros usados para identificar as teclas em um evento que use teclado*/
	return (0);
}

int main()
	{
		t_data data; /* ponteiros armazenados em formato de estrutura */

		data.mlx_ptr = mlx_init(); /* iniciando a conexão com X-server */
		if (data.mlx_ptr == NULL)
			return(MLX_ERROR);
		data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Vai Capiii!"); /* criando uma janela | As medidas são estabelecida na macro definida na biblioteca */
		/*ponteiro janela = função(ponteiro tela, largura, altura, Título da Janela )*/
		if (data.win_ptr == NULL)
		{
			free(data.win_ptr); 
			return(MLX_ERROR);
		}
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); /* */
		mlx_key_hook(data.win_ptr, &handle_input, &data); /*Função que executa os eventos pré definidos */
		mlx_hook(data.win_ptr, 17, 0, &ft_destroy_mlx, &data);/* Função que habilita o botão Fechar(x) */
		mlx_loop(data.mlx_ptr);/*Função que mantém a janela aberta enquanto os eventos acontecem. O prgrama só fecha manualmente */
	}


