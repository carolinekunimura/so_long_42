/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:45:24 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/01 21:19:40 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprites(t_data *data, void **img, char *path)
{
	int x;
	int y;

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
	int x;
	int y;

	x = 0;
	y = 0;
	while(data->map[x] != NULL)
	{
		while(y < data->col)
		{
			if (data->map[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->tile_set, y * PIXEL_SIZE, x * PIXEL_SIZE);
			else if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->tree_set, y * PIXEL_SIZE, x * PIXEL_SIZE);
			else if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->capi, y * PIXEL_SIZE, x * PIXEL_SIZE);
			else if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->lemon_set, y * PIXEL_SIZE, x * PIXEL_SIZE);
			else if (data->map[x][y] == 'E' && data->count_lemon > 0)
				mlx_put_image_to_window(data->mlx, data->window, data->b_exit, y * PIXEL_SIZE, x * PIXEL_SIZE);
			else
				mlx_put_image_to_window(data->mlx, data->window, data->exit_set, y * PIXEL_SIZE, x * PIXEL_SIZE);
			y++;
		}
	y = 0;
	x++;
	}
	return (0);
}

int	ft_move(t_data *data, int key)
{
	if (key == XK_Left || key == XK_a)
		data->capi = data->capi_left;
	else if (key == XK_Right || key == XK_d)
		data->capi = data->capi_right;
	else if (key == XK_Up || key == XK_w)
		data->capi = data->capi_up;
	else if (key == XK_Down || key == XK_s)
		data->capi = data->capi_down;
	render(data);
	return (0);
}

int		count_lemon(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map[x] != NULL)
	{
		while(data->map[x][y] != '\0')
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

int		count_exit_player(t_data *data)
{
	int x;
	int y;
	int c;
	int p;

	c = 0;
	p = 0;
	x = 0;
	while (data->map[x] != NULL)
	{
		y = -1;
		while(data->map[x][++y] != '\0')
		{
			if (data->map[x][y] == 'E')
				c++;
			if (data->map[x][y] == 'P')
				p++;
		}
	x++;
	}
	if (c == 0)
		return (ft_print_error(ERROR_8));
	if (p > 1)
		return (ft_print_error(ERROR_7));
	return (0);
}

