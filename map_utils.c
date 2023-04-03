/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:31:23 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 14:49:40 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_check_invalid_char(t_data *data, char *str)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->line)
	{
		j = 1;
		while (j < data->col)
		{
			if (ft_strchr(str, data->map[i][j]) == 0)
				return (ft_print_error(ERROR_10));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_invalid_dup(char **map_dup)
{
	int	i;
	int	j;

	i = 1;
	while (map_dup[i])
	{
		j = 1;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == 'C' || map_dup[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_capi(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (data->map[x] != NULL)
	{
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] != 'P')
				y++;
			else
			{
				data->capi_x = x;
				data->capi_y = y;
				return ;
			}
		}
	y = 1;
	x++;
	}
}

int	ft_check_path(t_data *data)
{
	int		i;
	char	**dup_data;

	i = 0;
	dup_data = ft_calloc(data->line + 1, sizeof (char *));
	if (dup_data == NULL)
		return (ft_print_error(ERROR_14));
	while (i < data->line)
	{
		dup_data[i] = ft_strdup(data->map[i]);
		if (dup_data[i] == NULL)
		{
			free_matrix(dup_data);
			return (ft_print_error(ERROR_14));
		}
		i++;
	}
	find_capi(data);
	flood_fill(dup_data, data->capi_x, data->capi_y);
	if (ft_check_invalid_dup(dup_data) != 0)
		return (ft_print_error(ERROR_6));
	free_matrix(dup_data);
	return (0);
}

void	flood_fill(char **map_dup, int x, int y)
{
	if (map_dup[x][y] == 'X' || map_dup[x][y] == '1' || map_dup[x][y] == 'S')
		return ;
	if (map_dup[x][y] == 'E')
	{
		map_dup[x][y] = 'S';
		return ;
	}
	map_dup[x][y] = 'X';
	flood_fill (map_dup, x + 1, y);
	flood_fill (map_dup, x, y + 1);
	flood_fill (map_dup, x - 1, y);
	flood_fill (map_dup, x, y - 1);
}
