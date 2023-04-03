/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:48:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/04/03 12:16:29 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static int	ft_intlen(int n)
{
	int				l;
	unsigned int	nbr;

	l = 1;
	nbr = n;
	if (n < 0)
	{
		l++;
		nbr = n * -1;
	}
	while (nbr > 9)
	{
		nbr = (nbr / 10);
		if (nbr != 0)
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int				l;
	char			*p;
	unsigned int	nbr;
	int				i;

	nbr = n;
	l = ft_intlen(n);
	p = (char *)malloc((l + 1) * sizeof(char));
	i = -1;
	while (++i <= l)
		p[i] = 0;
	if (!p)
		return (0);
	if (n < 0)
	{
		nbr = n * -1;
		p[0] = '-';
	}
	while (l - 1 >= 0 && p[l - 1] == '\0')
	{
		p[l - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		l--;
	}
	return (p);
}
