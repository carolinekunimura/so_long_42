/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:03:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 17:06:15 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int		ft_count_lines(int fd, char *temp, t_mlx *window);
int		ft_count_col(char *temp);
int		ft_count_collectibles(t_mlx *window);
int		ft_check_exit(int exit, int collec);
int		ft_close_and_free(int fd, char *temp);