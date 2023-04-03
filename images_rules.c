/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:45:24 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 12:49:05 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	ft_sprites(t_data *data, void **img, char *path)
{
	int	x;
	int	y;

	*img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	if (*img == NULL)
	{
		ft_print_error(ERROR_5);
		close_window(data);
	}
}

void	ft_put_sprites(t_data *data)
{	
	ft_sprites(data, &data->tree_set, "imgs/tree_set.xpm");
	ft_sprites(data, &data->capi_down, "imgs/capi_down.xpm");
	ft_sprites(data, &data->capi_up, "imgs/capi_up.xpm");
	ft_sprites(data, &data->capi_left, "imgs/capi_left.xpm");
	ft_sprites(data, &data->capi_right, "imgs/capi_right.xpm");
	ft_sprites(data, &data->lemon_set, "imgs/lemon_set.xpm");
	ft_sprites(data, &data->tile_set, "imgs/tile_set.xpm");
	ft_sprites(data, &data->exit_set, "imgs/exit_set.xpm");
	ft_sprites(data, &data->b_exit, "imgs/b_exit.xpm");
}

int	render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = -1;
		while (++y < data->col)
		{
			if (data->map[x][y] == '0')
				ft_put_render(data, x, y, data->tile_set);
			else if (data->map[x][y] == '1')
				ft_put_render(data, x, y, data->tree_set);
			else if (data->map[x][y] == 'P')
				ft_put_render(data, x, y, data->capi);
			else if (data->map[x][y] == 'C')
				ft_put_render(data, x, y, data->lemon_set);
			else if (data->map[x][y] == 'E' && data->count_lemon > 0)
				ft_put_render(data, x, y, data->b_exit);
			else
				ft_put_render(data, x, y, data->exit_set);
		}
	x++;
	}
	return (0);
}

void	ft_put_render(t_data *data, int x, int y, void *image)
{
	mlx_put_image_to_window (data->mlx, data->window, image, \
		y * PIXEL_SIZE, x * PIXEL_SIZE);
}

int	count_lemon(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x] != NULL)
	{
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'C')
				data->count_lemon++;
			y++;
		}
	y = 0;
	x++;
	}
	if (data->count_lemon == 0)
		return (ft_print_error(ERROR_9));
	return (0);
}
