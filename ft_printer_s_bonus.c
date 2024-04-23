/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:27 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/01 18:33:19 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf_bonus.h"

static char	ft_asignr(int z, int m)
{
	if (z == 1 && m == '\0')
		return ('0');
	else
		return (' ');
}

static void	ft_modeline(char r, int *p, int mode, t_list *t_fl)
{
	if (mode == 1)
	{
		write (1, &r, 1);
		p[2]--;
	}
	if (mode == 2)
	{
		write(1, &r, 1);
		p[0]--;
	}
	else if (mode == 3)
	{
		while (p[2] > p[1] && t_fl->minus == '\0')
		{
			write(1, &r, 1);
			p[2]--;
		}
		write (1, "(null)", p[1]);
		p[2] -= p[1];
		while (p[2] > 0 && t_fl->minus == 1)
		{
			write(1, &r, 1);
			p[2]--;
		}
	}
}

static void	ft_null(int *p, t_list *t_fl)
{
	char	r;

	p[1] = t_fl->dot;
	if (p[1] > 6 || t_fl->dot == -1)
		p[1] = 6;
	p[2] = t_fl->width;
	if (p[1] >= t_fl->width)
	{
		p[2] = t_fl->dot;
		if (p[2] > 6)
			p[2] = 6;
	}
	p[0] = p[1];
	if (p[2] > p[1])
		p[0] = p[2];
	r = ' ';
	if (t_fl->minus == '\0' && t_fl->zero == 1)
		r = '0';
	while (p[2] > p[1] && t_fl->minus == '\0')
		ft_modeline(r, p, 1, t_fl);
	ft_modeline(r, p, 3, t_fl);
	while (p[2] > p[1] && t_fl->minus == 1)
		ft_modeline(r, p, 1, t_fl);
}

int	ft_printer_s2(t_list *t_fl, char *s)
{
	int		p[4];
	char	r;

	if (s == '\0')
		ft_null(p, t_fl);
	if (s == '\0')
		return (p[0]);
	p[1] = ft_strlen(s);
	p[0] = t_fl->width;
	if (p[0] < p[1])
		p[0] = p[1];
	if (t_fl->dot < p[0] && t_fl->width <= t_fl->dot)
		p[0] = t_fl->dot;
	if (t_fl->dot != -1 && ft_strlen(s) > t_fl->dot)
		p[1] = t_fl->dot;
	p[3] = p[0];
	r = ft_asignr(t_fl->zero, t_fl->minus);
	while (p[0]-- > p[1] && t_fl->minus == '\0')
		write (1, &r, 1);
	p[2] = p[1] - 1;
	while (p[1]-- > 0)
		ft_modeline(*(s + p[2] - p[1]), p, 2, t_fl);
	while (p[0]-- > p[1] && t_fl->minus == 1)
		write (1, &r, 1);
	return (p[3]);
}
