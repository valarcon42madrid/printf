/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:02:20 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/02 21:31:03 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_asigner(t_list *t_fl, unsigned int d, int *p)
{
	p[1] = 0;
	p[2] = 0;
	p[6] = 0;
	p[5] = 0;
	p[0] = ft_numlen('\0', d);
	p[4] = ft_numlen('\0', d);
	if (p[0] < t_fl->dot)
		p[0] = t_fl->dot;
	p[3] = p[0];
	if (p[0] < t_fl->width)
		p[0] = t_fl->width;
	p[7] = p[0];
	if (t_fl->zero == 1 && t_fl->dot == -1 && t_fl->minus == '\0')
		return ('0');
	else
		return (' ');
}

static void	ft_error(t_list *t_fl, unsigned int d, int *p)
{
	if (t_fl->dot == 0 && d == 0)
	{
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
		p[3] = 0;
		p[4] = 0;
		p[5] = 0;
		p[6] = 0;
		p[7] = t_fl->width;
		while (p[2] < p[7])
		{
			write(1, " ", 1);
			p[2]++;
		}
	}
}

static void	ft_modewritting(char r, int *p, int mode)
{
	if (mode == 1)
	{
		write(1, &(r), 1);
		p[0]--;
	}
	if (mode == 2)
	{
		write(1, "0", 1);
		p[0]--;
		p[3]--;
	}
	if (mode == 3)
	{
		write (1, &(r), 1);
		p[6]++;
		p[0]--;
	}
}

int	ft_printer_u2(t_list *t_fl, unsigned int d)
{
	int		p[8];
	char	*r;
	char	l;

	l = ft_asigner(t_fl, d, p);
	ft_error(t_fl, d, p);
	while (t_fl->minus == '\0' && p[0] > p[3])
		ft_modewritting(l, p, 1);
	while ((t_fl->minus == '\0' && p[0] > p[4])
		|| (t_fl->minus == 1 && p[3] > p[4]))
		ft_modewritting('\0', p, 2);
	r = ft_itoa('\0', d);
	while (p[6] < p[4])
		ft_modewritting(r[p[6]], p, 3);
	free(r);
	while (t_fl->minus == 1 && p[0] > 0)
		ft_modewritting(' ', p, 1);
	return (p[7]);
}
