/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:29:10 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/01 16:38:36 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_print_error(char *error)
{
	write(1, error, ft_strlen(error));
	return(1);
}

int	ft_close_and_free(int fd, char *gnl)
{
	close(fd);
	free(gnl);
	return (1);
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
