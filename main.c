/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/13 14:30:54 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/solong.h"

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
			free(data.win_ptr); /*em caso de algum erro na conexão, a memória é desalocada e retorna código de erro */
			return(MLX_ERROR);
		}
		
		data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "tile_set.xpm", &img_width, &img_height);
		if (!img_ptr)
			exit(1); /* tentando colocar alguma imagem na tela, nao facço ideia do que esta acontecendo*/
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); /* Função de callback chamadando a função handle_no_event */
		mlx_key_hook(data.win_ptr, &handle_input, &data); /*Função que executa os eventos pré definidos */
		mlx_hook(data.win_ptr, 17, 0, &ft_destroy_mlx, &data);/* Função que habilita o botão Fechar(x) */
		mlx_loop(data.mlx_ptr);/* Função que mantém a janela aberta enquanto os eventos acontecem. O programa só fecha manualmente */
	}


