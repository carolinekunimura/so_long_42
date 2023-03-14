/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 16:55:33 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/solong.h"

int main(int argc, char** argv)
{
	int		size;
	t_data	data; /*declarando uma estrutura do tipo t_data*/

	if (argc != 2) /*verificando a quantidade de parametros passados para função*/
	{
		ft_print_error(ERROR_0"\n");
		return (1);
	}
	size = ft_strlen(argv[1]);
	if (size < 5 || ft_strncmp(".ber", argv[1] + size - 4, 5)) /*verifica se o arquivo passar por parametro contém a extensão .ber */
	{
		ft_print_error(ERROR_1"\n");
		return (1);
	}
	ft_struct_init(&data); /* inicializa as variáves da struct */
	if (ft_check_errors(&data, argv[i] == 1)) /* verifica possivesis erros nas variáveis da struct*/
		return(1);
	return(ft_init_game(&data)); /*depois de tudo verificado, inicia o jogo */
}


/* iniciar var contador de movimentos = 0 */

void	ft_struct_init(t_mlx *window); /* inicializa as variáveis da struct */
int		ft_check_errors(t_mlx *window, char *path); /* verifica erros no mapa */
void	ft_print_error(char *error); /* informa o erro encontrado */
int		ft_strncmp(const char *s1, const char *s2, size_t n); /* compara string */



		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);  Função de callback chamadando a função handle_no_event 
		mlx_key_hook(data.win_ptr, &handle_input, &data); Função que executa os eventos pré definidos 
		mlx_hook(data.win_ptr, 17, 0, &ft_destroy_mlx, &data); Função que habilita o botão Fechar(x) 
		mlx_loop(data.mlx_ptr); Função que mantém a janela aberta enquanto os eventos acontecem. O programa só fecha manualmente 
}
