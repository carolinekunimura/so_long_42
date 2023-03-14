/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:01:22 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 16:13:03 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int		ft_show_map(t_mlx *window);
int		ft_show_moves(t_mlx *window);
void	ft_locate_player(t_mlx *window);
int		ft_key_input(int key, t_mlx *window);
void	ft_hook_limits(t_mlx *window, int col, int line);