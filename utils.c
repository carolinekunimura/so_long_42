/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:29:10 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 17:32:30 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_print_error(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	return (1);
}

int	ft_close_and_free(int fd, char *gnl)
{
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}

void	free_matrix(char **matrix)
{
	int	x;

	x = 0;
	if (matrix == NULL)
		return ;
	while (matrix[x] != NULL)
	{
		free(matrix[x]);
		x++;
	}
	free(matrix);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_print_error(ERROR_11));
	data->window = mlx_new_window(data->mlx, data->col * PIXEL_SIZE, \
		data->line * PIXEL_SIZE, "Vai Capiii");
	if (data->window == NULL)
	{
		free(data->mlx);
		return (ft_print_error(ERROR_12));
	}
	ft_put_sprites (data);
	data->capi = data->capi_down;
	return (0);
}
