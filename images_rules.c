/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:02:34 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 16:12:53 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int		ft_valid_walls(t_mlx *window);
int		ft_check_characters(t_mlx *window, int e, int p, int invalid);
int		ft_valid_character(t_mlx *window);
int		ft_check_path(char **copy, t_mlx *window);
void	ft_test_path(char **copy, int line, int col, t_mlx *window);