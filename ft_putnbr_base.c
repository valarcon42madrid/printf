/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:55 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/24 11:15:04 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static unsigned int	ft_recursivenum(unsigned long int nb, int bs, char *b)
{
	unsigned long int	ncpy;

	while (nb != 0)
	{
		ncpy = (nb % bs);
		nb = nb - ncpy;
		nb = nb / bs;
		nb = ft_recursivenum(nb, bs, b);
		write (1, (b + ncpy), 1);
	}
	return (nb);
}

void	ft_putnbr_base(void *nb, unsigned int nb2, char *base)
{
	char				*basz;
	int					bs;
	unsigned long int	nbr;

	nbr = (unsigned long int)nb;
	if (nbr < nb2)
		nbr = (unsigned long int)nb2;
	basz = base;
	bs = 0;
	while (*basz)
	{
		bs++;
		basz++;
	}
	if (nbr == 0)
		write (1, "0", 1);
	while (nbr != 0)
		nbr = ft_recursivenum(nbr, bs, base);
}
