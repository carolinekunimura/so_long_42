/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:39:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/01 21:10:20 by ckunimur         ###   ########.fr       */
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
# include <stdio.h>


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
	void	*b_exit;
	void	*exit_set;
	void	*tree_set;
	void	*tile_set;
	int		col;
	int		line;
	char	**map;
	int		capi_x;
	int		capi_y;
	int		count_lemon;
	int		count_moves;

}				t_data;

typedef	struct	s_moves
{
	int x;
	int y;
}				t_moves;


# endif

/*------------------functions so_long.c --------------------------------------------*/

int		close_window(t_data	*data);
int		press_button(int key, t_data *data);
int		ft_create_map(t_data *data, char *argv);
int		valid_map(t_data *data);


/*--------------------------functions map_rules.c ------------------------------------*/

int		ft_check_ber(char	*argv);
int		ft_check_map( t_data *data, char *argv);
int		ft_check_border(t_data *data);
int		ft_check_invalid_char(t_data *data, char *str);
void	find_capi(t_data *data);
int		ft_check_path(t_data *data);
void	flood_fill(char **map_dup, int x, int y);
void	free_matrix(char **matrix);



/*--------------------------------functions utils.c --------------------------*/

size_t	ft_strlen(const char *str);
int		ft_print_error(char *error);
int		ft_close_and_free(int fd, char *gnl);
int		ft_strncmp(const char *s1, const char *s2, size_t n);



char	*ft_strdup(const char *s);
/*-------------------------------functions imges_rules.c --------------------*/

void	ft_sprites(t_data *data, void **img, char *path);
void	ft_put_sprites(t_data *data);
int		render(t_data *data);
int		ft_move(t_data *data, int key);
int		count_exit_player(t_data *data);
int		count_lemon(t_data *data);
void	ft_play(t_data *data, int x, int y);
