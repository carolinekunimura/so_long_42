/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:03:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/03/20 18:18:16 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_count_lines(int fd, char *gnl, t_data *window)
{
	int	count;

	count = 0
	window->img_line =	0;
	window->img_col	= ft_count_col(gnl);

	while (gnl)
	{
		if (gnl[0] == '\n' && count == 0)
			count++;
		if (gnl[0] != '\n' && count != 0)
			return(ft_close_and_free(fd, gnl));
		free(gnl);
		gnl = get_next_line(fd);
		window->img_line++;
	}
}

int	ft_count_col(char *gnl)
{
	int	i;

	i = 0;
	while(gnl[i] != '\r' && gnl[i] != '\n' && gnl[i] != '\0')
		i++;
		return(i);
}

int	ft_count_collectibles(t_data *window);
{
	int l;
	int	c;
	int count;

	l = 0;
	c = 0;
	count = 0;
	while(window->map[l])
	{
		while (window->map[l][c] != '\0')
		{
			if(window->map[l][c] != 'C')
				c++;
			else
				count++;
		}
		l++;
		c = 0;
	}
	return(count);
}

int	ft_check_exit(int exit, int collec);
{
	if (collec == 0)
		
}

int	ft_close_and_free(int fd, char *gnl);
{
	close(fd);
	free(gnl);
	return(1);
}