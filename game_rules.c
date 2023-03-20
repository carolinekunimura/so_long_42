/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:03 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/20 16:36:04 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_init_game(t_data *data) /* inicializa a conexão, janela e jogo*/
{
	data->mlx_ptr = mlx_init(); /* iniciando a conexão com X-server */
	if (data->mlx_ptr == NULL)
	{
		ft_print_error(ERROR_12"\n");
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->col * PIXEL_SIZE, data->line * PIXEL_SIZE, "Vai Capiii!"); /* criando uma janela | As medidas são estabelecida na macro definida na biblioteca 
	ponteiro janela = função(ponteiro tela, largura, altura, Título da Janela ) */
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr); /* em caso de algum erro na conexão, a memória é desalocada e retorna código de erro */
		ft_print_error(ERROR_12"\n");
		return(1);
	}
	data->movements = 0 /* zera o contador de movimentos */
	ft_put_sprites(data); /* coloca as imagens na tela */
	data->capi = data->capi_down; /* define a imagem inicial do player */
}

void	ft_put_sprites(t_data *data) /* relaciona o arquivo .xpm a variavel */
{
	ft_sprites(data, &data->capi_left, "imgs/capi_left.xpm");
	ft_sprites(data, &data->capi_right, "imgs/capi_right.xpm");
	ft_sprites(data, &data->capi_up, "imgs/capi_up.xpm");
	ft_sprites(data, &data->capi_down, "imgs/capi_down.xpm");
	ft_sprites(data, &data->lemon_set, "imgs/lemon_set.xpm");
	ft_sprites(data, &data->exit_block, "imgs/blocked_exir.xpm");
	ft_sprites(data, &data->exit_open, "imgs/exit_set.xpm");
	ft_sprites(data, &data->tree_set, "imgs/tree_set.xpm");
	ft_sprites(data, &data->tile_set, "imgs/tile_set.xpm");
}

void	ft_sprites(t_data *data, void **image, char *path) /* coloca os sprites na tela usando a função mlx_xpm_file_to_image da minilibx */
{
	int	w;
	int	h;

	*image = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &h); /* converte o .xpm em pixels para serem mostrados na tela.. var image recebe as dimensões da imagem*/
	if(*image == NULL)
	{
		ft_print_error(ERROR_13"\n");
		ft_close(data);
	}
}

int	ft_close(t_data *data) /* funÇão que destroi as imagens e libera a memória alocada */
{
	mlx_destroy_image(data->mlx_ptr, data->capi_left);
	mlx_destroy_image(data->mlx_ptr, data->capi_right);
	mlx_destroy_image(data->mlx_ptr, data->capi_up);
	mlx_destroy_image(data->mlx_ptr, data->capi_down);
	mlx_destroy_image(data->mlx_ptr, data->lemon_set);
	mlx_destroy_image(data->mlx_ptr, data->exit_block);
	mlx_destroy_image(data->mlx_ptr, data->exit_open);
	mlx_destroy_image(data->mlx_ptr, data->tree_set);
	mlx_destroy_image(data->mlx_ptr, data->tile_set);
	ft_free_matrix(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return(0);
}

