/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:23:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/13 15:08:51 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_destroy_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr); /* Apagando a janela criada para exibir a tela do jogo*/
	mlx_destroy_display(data->mlx_ptr); /* Apagando a tela do jogo */
	free(data->mlx_ptr); /* Liberando o espaço alocado pelo programa */
	exit(0);
}

void	ft_print_error(char	*error)
{
	write(1, error, ft_strlen(error));
}

size_t  ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return(0);
	while(s1[i] != !0 && s1[i] == s2[i] && i < n -1)
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i];
}

int	handle_no_event(void *data) /*Essa função serve para tratar eventos vazios ou ausentes, quando nenhum comando(evento) é recebido */
{
	return (0);
}
int	handle_input(int keysym, t_data *data) /*Essa função iá receber os eventos do usuário e acionar as funções de acordo com os comandos executados pelo usuário */
{
	printf("%i\n", keysym); /*keysym se refere ao conjunto de símbolos e teclas do sistema, são valores inteiros usados para identificar as teclas em um evento que use teclado*/
	return (0);
}
