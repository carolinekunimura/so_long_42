/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:47 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 15:32:04 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	line = takenextline(fd);
	return (line);
}

char	*takenextline(int fd)
{
	char	*buffer;
	char	*line;
	size_t	reader;

	line = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		while (line == NULL)
		{
			buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
			reader = read(fd, buffer, BUFFER_SIZE);
			buffer[reader] = '\0';
			if (reader == 0)
			{
				buffer[reader] = '\0';
				line = ft_makestr(buffer, '\n', reader);
				free(buffer);
				return (line);
			}
			line = ft_makestr(buffer, '\n', reader);
			free(buffer);
		}
	}
	return (line);
}

char	*ft_makestr(char *buffer, char c, size_t reader)
{
	char		*line;
	char		*rmd;
	static char	*remainder;

	if (reader == 0 && !ft_strchr(remainder, '\n'))
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}
	buffer = ft_strjoin(remainder, buffer, reader);
	rmd = ft_strchr(buffer, c);
	free(remainder);
	remainder = NULL;
	if (!rmd)
	{
		remainder = ft_strdup(buffer);
		free((char *)buffer);
		return (NULL);
	}
	if (rmd[1] != '\0')
		remainder = ft_strdup(rmd + 1);
	line = ft_substr(buffer, 0, (ft_strlen(buffer)) - (ft_strlen(remainder)));
	free((char *)buffer);
	return (line);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*buffer;
	size_t	size_t_max;

	i = 0;
	buffer = NULL;
	size_t_max = -1;
	if (nmemb * size == 0 || (size != 0 && nmemb > size_t_max / size))
		return (NULL);
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (NULL);
	size_t_max = nmemb * size;
	i = 0;
	while (i < size_t_max)
	{
		((char *)buffer)[i] = '\0';
		i++;
	}
	return (buffer);
}
