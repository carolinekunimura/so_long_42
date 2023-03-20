/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:34:27 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/20 18:37:06 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl_42/get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include "errors.h"

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT (WINDOW_WIDTH / 2)

typedef struct s_data /*criamos uma struct para manipular diferentes dados em funções passando o parâmetro (t_data) funciona como um gabario que ira reservar espaço de memória para a quantidade de variáveis declaradas aqui.*/
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
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
	void	*img_ptr;
	char	*img_data;
	int		img_line;
	int		img_col;
	size_t	movements;
	
}	t_data;

/*------------------------SO_LONG FUNCTIONS----------------------------*/
int		main(int argc, char **argv); /* recebe parametros, verifica, inicia o jogo*/
void	ft_struct_init(t_data *window); /* inicializa as variáveis da struct */
int		ft_check_errors(t_data *window, char *path); /* verifica erros no mapa */
void	ft_print_error(char *error); /* informa o erro encontrado */
int		ft_strncmp(const char *s1, const char *s2, size_t n); /* compara string */

/*-----------------------GAME_RULES FUNCTIONS--------------------------*/
int		ft_init_game(t_data *window); /* inicializa a conexão, janela e jogo*/
void	ft_put_sprites(t_data *window); /* */
void	ft_sprites(t_data *window, void **image, char *path);
int		ft_close(t_data *window);

/*-----------------------MAP_RULES FUNCTIONS---------------------------*/
int		ft_create_map(t_data *window, char *path);
void	ft_put_image_to_window(t_data *window, void *image, int x, int y);
char	**ft_dup_map(t_data *window);
int		ft_read_map(t_data *window, char *path);
void	ft_free_matrix(char **matrix);

/*-----------------------MAP_RULES_UTILS FUNCTIONS--------------------*/
int		ft_show_map(t_data *window);
int		ft_show_moves(t_data *window);
void	ft_locate_player(t_data *window);
int		ft_key_input(int key, t_data *window);
void	ft_hook_limits(t_data *window, int col, int line);

/*-------------------------IMAGES_RULES FUNCTIONS---------------------*/
int		ft_valid_walls(t_data *window);
int		ft_check_characters(t_data *window, int e, int p, int invalid);
int		ft_valid_character(t_data *window);
int		ft_check_path(char **copy, t_data *window);
void	ft_test_path(char **copy, int line, int col, t_data *window);

/*--------------------IMAGES_RULES_UTILS FUNCTIONS--------------------*/
int		ft_count_lines(int fd, char *temp, t_data *window);
int		ft_count_col(char *temp);
int		ft_count_collectibles(t_data *window);
int		ft_check_exit(int exit, int collec);
int		ft_close_and_free(int fd, char *temp);

#endif
