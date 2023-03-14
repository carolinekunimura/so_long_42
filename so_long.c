/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/14 14:53:27 by ckunimur         ###   ########.fr       */
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

int	ft_init_game(t_mlx *data)
{
		data.mlx_ptr = mlx_init(); /* iniciando a conexão com X-server */
		if (data.mlx_ptr == NULL)
			return(1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, 900, (900 / 2), "Vai Capiii!");  criando uma janela | As medidas são estabelecida na macro definida na biblioteca 
		ponteiro janela = função(ponteiro tela, largura, altura, Título da Janela )
		if (data.win_ptr == NULL)
		{
			free(data.win_ptr); em caso de algum erro na conexão, a memória é desalocada e retorna código de erro 
			return(1);
		}
		
		int	ft_show_map(t_data	*window)
		{
			int	x;
			int	y;

			y = -1;
			while (x <window->map[++y])  ++y indica que deve haver incremente antes de a função ser executada
			
		
		
		if (!data.img_ptr)
			exit(1);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);  Função de callback chamadando a função handle_no_event 
		mlx_key_hook(data.win_ptr, &handle_input, &data); Função que executa os eventos pré definidos 
		mlx_hook(data.win_ptr, 17, 0, &ft_destroy_mlx, &data); Função que habilita o botão Fechar(x) 
		mlx_loop(data.mlx_ptr); Função que mantém a janela aberta enquanto os eventos acontecem. O programa só fecha manualmente 
	}
}