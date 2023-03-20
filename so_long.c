/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:20 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/20 18:28:01 by ckunimur         ###   ########.fr       */
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
	if (size < 5 || ft_strncmp(".ber", argv[1] + size - 4, 5)) /* verifica se o arquivo passar por parametro contém a extensão .ber */
	{
		ft_print_error(ERROR_1"\n");
		return (1);
	}
	ft_struct_init(&data); /* inicializa as variáves da struct */
	if (ft_check_errors(&data, argv[1]) == 1) /* verifica possiveis erros nas variáveis da struct*/
		return(1);
	return(ft_init_game(&data)); /*depois de tudo verificado, inicia o jogo */
}

void	ft_struct_init(t_data *window); /* inicializa as variáveis da struct */
{
	window = (t_data *){0};
}


int		ft_check_errors(t_data *window, char *path); /* verifica erros no mapa */
{
	int		fd;
	int		c_lines;
	char	*gnl;
		
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_print_error(ERROR_2);
	gnl = get_next_line(fd);
	if (gnl == NULL)
		ft_print_error(ERROR_11);
	c_lines = ft_count_lines(fd, gnl, window)
	if (c_lines > 0)
		ft_print_error(ERROR_3)
	
}

void	ft_print_error(char *error); /* informa o erro encontrado */
{
	write(1, error, ft_strlen(error));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n) /* compara string */
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
