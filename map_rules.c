/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:23 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/20 17:16:25 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_create_map(t_data *window, char *path)
{
	
}


void	ft_put_image_to_window(t_data *window, void *image, int x, int y);

char	**ft_dup_map(t_data *window);

int	ft_read_map(t_data *window, char *path);

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free(matrix);
}