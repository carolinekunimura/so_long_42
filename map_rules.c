/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:23 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 17:06:21 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int		ft_create_map(t_mlx *window, char *path);


void	ft_put_image_to_window(t_mlx *window, void *image, int x, int y);
char	**ft_dup_map(t_mlx *window);
int		ft_read_map(t_mlx *window, char *path);
void	ft_free_matrix(char **matrix);