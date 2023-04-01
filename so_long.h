/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:39:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/27 15:56:56 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl_42/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "errors.h"


typedef struct	s_data
{
	void	*mlx;
	void	*window;
	void	*capi;
	void	*capi_left;
	void	*capi_right;
	void	*capi_up;
	void	*capi_down;
	void	*lemon_set;
	void	*exit_block;
	void	*exit_open;
	void	*tree_set;
	void	*tile_set;
	int		col;
	int		line;
	char	**map;

}				t_data;

typedef	struct	s_moves
{
	int x;
	int y;
}				t_moves;


# endif