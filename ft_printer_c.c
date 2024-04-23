/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:36:36 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/02 21:30:20 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static void	ft_putchar(int c)
{
	char	k;

	k = (char)c;
	write(1, &k, 1);
}

int	ft_printer_c2(t_list *t_fl, int a)
{
	int		p;
	char	r;

	p = t_fl->width;
	r = ' ';
	if (t_fl->zero == 1 && t_fl->minus == '\0')
		r = '0';
	while (p > 1 && t_fl->minus == '\0')
	{
		write(1, &r, 1);
		p--;
	}
	ft_putchar(a);
	while (p > 1 && t_fl->minus == 1)
	{
		write(1, &r, 1);
		p--;
	}
	p = t_fl->width;
	if (p == '\0')
		p = 1;
	return (p);
}
