/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:57 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/27 17:09:39 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int	close_window(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->capi);
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
size_t	ft_strlen(const char	*str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}
int	ft_print_error(char *error)
{
	write(1, error, ft_strlen(error));
	return(1);
}

int	ft_close_and_free(int fd, char *gnl)
{
	close(fd);
	free(gnl);
	return (1);
}

int	ft_check_ber(char	*argv)
{
	char	*ber;
	int		check;
	int	len;

	ber = ".ber";
	len = ft_strlen(argv);
	if (len <= 4)
		return (1);
	check = ft_strncmp(argv[len - 4], ber, 5);
	if (check != 0)
		return (1);
	return(0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n) /* compara string */
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

int	ft_check_char(char *line)
{
	int	i;
	
	i = 0;
	while (line [i] != '\0')
	{
		
	}
		
}

int	ft_check_map( t_data *data, char *argv)
{
	int		fd;
	char	line;
	
	fd = open(argv, O_RDONLY)
	if (fd == -1)
		return (ft_print_error(ERROR_2));
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_close_and_free(fd, line) + ft_print_error(ERROR_12));
	data->col = ft_strlen(line) - 1;
	while (line)
	{
		data->line++;
		line = get_next_line(fd);
		if (ft_strchr(line, '\n') && data->col != ft_strlen(line) - 1 && line != NULL)
			return (ft_close_and_free(fd, line) + ft_print_error(ERROR_3));
	}
	close(fd);
	if (data->line < 3 || data->col < 5)
		return (ft_print_error(ERROR_3));
	return (0);
}
int	ft_create_map(t_data *data, char *argv)
{
	int	i;

	i = 0;
	data->map = (char **)malloc((data->line + 1) * sizeof(char *));
	if (data->map == NULL)
		return (ft_print_error(ERROR_14));
	fd = open(argv, O_RDONLY)
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

int		ft_check_char(t_data *data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] != '1' || data->map[i][data->col - 1] != '1')
			return (ft_print_error(ERROR_4));
		i++;	
	}
	while (j < data->col)
	{	
		if (data->map[0][j] != '1' || data->map[data->line][j] != '1')
				return (ft_print_error(ERROR_4))
		j++;
	}
	i = 1;
	j = 1;
	while (i < data->line - 1)
	{
		while (j < data->col - 1)
		{
			if (data->map[i][j] != '0' )
				return (ft_print_error(ERROR_10));
			if (data->map[i][j] != 'P')
				return (ft_print_error(ERROR_10));
			if (data->map[i][j] != 'C')
				return (ft_print_error(ERROR_10));
			if (data->map[i][j] != 'E')
				return (ft_print_error(ERROR_10));
			j++;
		}
	j = 1;
	i++;
	}
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
	if (ft_check_char(argv[1]) != 0)
		return (1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_print_error(ERROR_11));
	data.window = mlx_new_window(data.mlx, 900, 600, "Vai Capiii");
		if (data.window == NULL)
	{
		free(data.mlx);
		return (ft_print_error(ERROR_12));
	}
	mlx_hook(data.window, 17, 1L<<17, close_window ,&data);
	mlx_hook(data.window, 2, 1L<<0, press_button, &data);
	mlx_loop(data.mlx);
	return (0);
}
