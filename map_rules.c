/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:27:26 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 12:16:37 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_check_ber(char *argv)
{
	char	*ber;
	int		check;
	int		len;

	ber = ".ber";
	len = ft_strlen(argv);
	if (len <= 4)
		return (1);
	check = ft_strncmp(&argv[len - 4], ber, 5);
	if (check != 0)
		return (1);
	return (0);
}

int	ft_check_map( t_data *data, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
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
		if (ft_strchr(line, '\n') && \
				data->col != (int)ft_strlen(line) - 1 && line != NULL)
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
	int	fd;

	i = 0;
	data->map = (char **)malloc((data->line + 1) * sizeof(char *));
	if (data->map == NULL)
		return (ft_print_error(ERROR_14));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_print_error(ERROR_2));
	while (i <= data->line)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

int	valid_map(t_data *data)
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
	return (0);
}
