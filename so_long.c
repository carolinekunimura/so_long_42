/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:57 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/01 20:13:08 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->capi_down);
	mlx_destroy_image(data->mlx, data->capi_left);
	mlx_destroy_image(data->mlx, data->capi_up);
	mlx_destroy_image(data->mlx, data->capi_right);
	mlx_destroy_image(data->mlx, data->tile_set);
	mlx_destroy_image(data->mlx, data->tree_set);
	mlx_destroy_image(data->mlx, data->lemon_set);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return(0);
}

int	press_button(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data);
	return(0);
}

int	ft_create_map(t_data *data, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	data->map = (char **)malloc((data->line + 1) * sizeof(char *));
	if (data->map == NULL)
		return (ft_print_error(ERROR_14));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_print_error(ERROR_2));
	while(i <= data->line)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

int		valid_map(t_data *data)
{
	if (ft_check_border(data) != 0)
		return (1);
	if (ft_check_invalid_char(data, "01PCE") != 0)
		return (1);
	if (ft_check_path(data) != 0)
		return (1);
	return (0);
}

int	ft_check_border(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] != '1' || data->map[i][data->col - 1] != '1')
			return (ft_print_error(ERROR_4));
		i++;	
	}
	while (j < data->col - 1)
	{	
		if (data->map[0][j] != '1' || data->map[data->line - 1][j] != '1')
				return (ft_print_error(ERROR_4));
		j++;
	}
	return(0);
}

int	ft_check_invalid_char(t_data *data, char *str)
{
	int	i;
	int j;

	i = 1;
	while (i < data->line - 1)
	{
		j = 1;
		while (j < data->col - 1)
		{
			if (ft_strchr(str, data->map[i][j]) == 0)
				return (ft_print_error(ERROR_10));
			j++;
		}
		i++;
	}
	return (0);
}

void	find_capi(t_data *data)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while(data->map[x] != NULL)
	{
		while(data->map[x][y] != '\0')
		{
			if (data->map[x][y] != 'P')
				y++;
			else
			{
				data->capi_x = x;
				data->capi_y = y;
				return;
			}
		}
	y = 1;
	x++;
	}
}

int	ft_check_path(t_data *data)
{
	int i;
	t_data	dup_data;

	i = 0;
	dup_data.line = data->line;
	dup_data.col = data->col;
	dup_data.map = calloc((data->line + 1), sizeof (char *));
	
	if (dup_data.map == NULL)
		return (ft_print_error(ERROR_14));
	while (i < data->line)
	{
		dup_data.map[i] = ft_strdup(data->map[i]);
		if (dup_data.map[i] == NULL)
		{
			free_matrix(dup_data.map);
			return (ft_print_error(ERROR_14));
		}
		i++;
	}
	find_capi(data);
	flood_fill(dup_data.map, data->capi_x, data->capi_y);
	if (ft_check_invalid_char(&dup_data, "XS1") != 0)
		return (ft_print_error(ERROR_6));
	free_matrix(dup_data.map);
	return (0);
}

void flood_fill(char **map_dup, int x, int y)
{
	if (map_dup[x][y] == 'X' || map_dup[x][y] == '1' || map_dup[x][y] == 'S')
		return;
	if (map_dup[x][y] == 'E')
	{
		map_dup[x][y] = 'S';
		return ;
	}
	map_dup[x][y] = 'X';

	flood_fill(map_dup, x + 1, y);
	flood_fill(map_dup, x, y + 1);
	flood_fill(map_dup, x - 1, y);
	flood_fill(map_dup, x, y - 1);
}

void	free_matrix(char **matrix)
{
	int x;
	
	x = 0;
	if (matrix == NULL)
		return;
	while (matrix[x] != NULL)
	{
		free(matrix[x]);
		x++;
	}
	free(matrix);
}

int main(int argc, char **argv)
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
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_print_error(ERROR_11));
	data.window = mlx_new_window(data.mlx, data.col * PIXEL_SIZE, data.line * PIXEL_SIZE, "Vai Capiii");
		if (data.window == NULL)
	{
		free(data.mlx);
		return (ft_print_error(ERROR_12));
	}
	ft_put_sprites(&data);
	mlx_hook(data.window, 17, 1L<<17, close_window ,&data);
	mlx_hook(data.window, 2, 1L<<0, press_button, &data);
	render(&data);
	mlx_loop(data.mlx);
	return (0);
}
