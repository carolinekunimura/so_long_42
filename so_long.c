/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:57 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 14:58:10 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	close_window(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->capi_down);
	mlx_destroy_image(data->mlx, data->capi_left);
	mlx_destroy_image(data->mlx, data->capi_up);
	mlx_destroy_image(data->mlx, data->capi_right);
	mlx_destroy_image(data->mlx, data->tile_set);
	mlx_destroy_image(data->mlx, data->tree_set);
	mlx_destroy_image(data->mlx, data->lemon_set);
	mlx_destroy_image(data->mlx, data->exit_set);
	mlx_destroy_image(data->mlx, data->b_exit);
	mlx_destroy_window(data->mlx, data->window);
	free_matrix(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	press_button(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data);
	if (key == XK_Left || key == XK_a)
	{
		data->capi = data->capi_left;
		ft_play(data, 0, -1);
	}
	else if (key == XK_Right || key == XK_d)
	{
		data->capi = data->capi_right;
		ft_play(data, 0, 1);
	}
	else if (key == XK_Up || key == XK_w)
	{
		data->capi = data->capi_up;
		ft_play(data, -1, 0);
	}
	else if (key == XK_Down || key == XK_s)
	{
		data->capi = data->capi_down;
		ft_play(data, 1, 0);
	}
	ft_print_moves(data);
	render(data);
	return (0);
}

void	ft_play(t_data *data, int x, int y)
{
	if (data->map[data->capi_x + x][data->capi_y + y] == '0')
	{
		data->map[data->capi_x + x][data->capi_y + y] = 'P';
		data->map[data->capi_x][data->capi_y] = '0';
		data->count_moves++;
		data->capi_x += x;
		data->capi_y += y;
	}
	else if (data->map[data->capi_x + x][data->capi_y + y] == 'C')
	{
		data->map[data->capi_x + x][data->capi_y + y] = 'P';
		data->count_lemon--;
		data->map[data->capi_x][data->capi_y] = '0';
		data->count_moves++;
		data->capi_x += x;
		data->capi_y += y;
	}
	else if (data->map[data->capi_x + x][data->capi_y + y] == 'E' \
				&& data->count_lemon == 0)
	{
		data->map[data->capi_x][data->capi_y] = '0';
		data->count_moves++;
		write(1, "Enjoy your bath!!\n", 18);
		close_window(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	data = (t_data){0};
	i = 0;
	if (argc != 2)
		return (ft_print_error(ERROR_0));
	if (ft_check_ber(argv[1]) != 0)
		return (ft_print_error(ERROR_3));
	if (ft_check_map(&data, argv[1]) != 0)
		return (1);
	if (ft_create_map(&data, argv[1]) != 0)
		return (1);
	if (valid_map(&data) != 0)
		return (1);
	if (count_lemon(&data) != 0)
		return (1);
	if (count_exit_player(&data) != 0)
		return (1);
	ft_init_game (&data);
	mlx_hook (data.window, 17, 1L << 17, close_window, &data);
	mlx_hook (data.window, 2, 1L << 0, press_button, &data);
	render (&data);
	mlx_loop (data.mlx);
	return (0);
}
