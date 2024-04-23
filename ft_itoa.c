/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:34:56 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/24 11:34:58 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int	ft_buf(long cpy, char **res, long size)
{
	if (size == 0)
	{
		while (cpy != 0)
		{
			size++;
			cpy = cpy / 10;
		}
	}
	else
	{
		while (cpy != 0)
		{
			size--;
			*(*res + size) = (char)((cpy % 10) + 48);
			cpy = cpy / 10;
		}
	}
	return (size);
}

char	*ft_itoa(int n, unsigned int m)
{
	long	size;
	long	cpy;
	char	*res;

	if (n < 0)
		n *= (-1);
	if (m == '\0')
		m = (unsigned int)n;
	cpy = (long)m;
	size = 0;
	size = ft_buf(cpy, (char **) '\0', size);
	if (m == 0)
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (res == '\0')
		return (0);
	*(res + size) = '\0';
	cpy = (long)m;
	if (cpy == 0)
		*(res) = (char)48;
	size = ft_buf(cpy, &res, size);
	return (res);
}
