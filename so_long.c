/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/02 13:46:28 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

int main()
	{

		t_data data; /* ponteiros armazenados em formato de estrutura */

		data.mlx_ptr = mlx_init(); /* iniciando a conexão com X-server */
		if (data.mlx_ptr == NULL)
			return(MLX_ERROR);
		data.win_ptr = mlx_new_window(data.mlx_ptr, 900, (900 / 2), "Vai Capiii!"); /* criando uma janela | As medidas são estabelecida na macro definida na biblioteca */
		/*ponteiro janela = função(ponteiro tela, largura, altura, Título da Janela )*/
		if (data.win_ptr == NULL)
		{
			free(data.win_ptr); /*em caso de algum erro na conexão, a memória é desalocada e retorna código de erro */
			return(MLX_ERROR);
		}
		
		data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "imgs/tile_set.xpm", &data.img_width, &data.img_height); /* função que converte arquivo .xpm em imagem */
		if (!data.img_ptr)
			exit(1);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); /* Função de callback chamadando a função handle_no_event */
		mlx_key_hook(data.win_ptr, &handle_input, &data); /*Função que executa os eventos pré definidos */
		mlx_hook(data.win_ptr, 17, 0, &ft_destroy_mlx, &data);/* Função que habilita o botão Fechar(x) */
		mlx_loop(data.mlx_ptr);/* Função que mantém a janela aberta enquanto os eventos acontecem. O programa só fecha manualmente */
	}


