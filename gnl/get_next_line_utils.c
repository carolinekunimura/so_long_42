/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:37 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/26 12:20:31 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t reader)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	size_len;
	size_t	len1;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	size_len = len1 + reader;
	p = ft_calloc((size_len + 1), (sizeof(char)));
	while (i < size_len)
	{
		if (i < len1)
			p[i] = s1[i];
		if (i >= len1)
			p[i] = s2[j++];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*p;

	s_len = ft_strlen(s);
	i = 0;
	if (len >= s_len)
		len = (s_len - start);
	if (start >= s_len)
	{
		return (ft_calloc(1, (sizeof(char))));
	}
	p = ft_calloc(len + 1, (sizeof(char)));
	if (s)
	{
		while (i < len && s[start + i] != '\0')
		{
			p[i] = s[start + i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
