/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:06:17 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 12:17:17 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	ft_print_moves(t_data *data)
{
	char	*str;

	str = ft_itoa (data->count_moves);
	write (1, "Moves :", 7);
	write (1, str, ft_strlen(str));
	write (1, "\n", 1);
	free (str);
}

int	count_exit_player(t_data *data)
{
	int	x;
	int	y;
	int	c;
	int	p;

	c = 0;
	p = 0;
	x = 0;
	while (data->map[x] != NULL)
	{
		y = -1;
		while (data->map[x][++y] != '\0')
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
