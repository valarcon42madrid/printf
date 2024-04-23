/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:12:31 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/01 18:32:52 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_resting(int *p, int mode, char c)
{
	if (mode == 1)
	{
		p[0]--;
		p[3]--;
		write(1, &c, 1);
		if (c == '-' || c == '+')
			p[2] = 1;
	}
	else if (mode == 2)
	{
		p[1] = 3;
		p[3] = 0;
		p[4] = 0;
		p[5] = 0;
		p[6] = 0;
	}
	else if (mode == 3)
	{
		p[6]++;
		p[0]--;
	}
	else
		while (p[0]-- > 0 && mode == 4)
			write(1, " ", 1);
}

static void	ft_sign(t_list *t_fl, int *p, int d, int m)
{
	if (m == 2)
	{
		p[0] = t_fl->width;
		p[3] = 0;
		p[4]++;
		p[6] = p[4];
		p[7] = t_fl->width;
	}
	else
		p[1]++;
	if (p[1] == 1 && d < 0 && m == 1 && (t_fl->minus == 1
			|| (t_fl->zero == 1 && t_fl->dot == -1) || t_fl->dot > t_fl->width))
		ft_resting(p, 1, '-');
	else if (m == 1 && p[1] == 1 && t_fl->plus == 1 && (t_fl->minus == 1
			|| (t_fl->zero == 1 && t_fl->dot == -1) || t_fl->dot > t_fl->width))
		ft_resting(p, 1, '+');
	if (m == 1 && p[1] == 2 && p[2] == 0 && d < 0)
		ft_resting(p, 1, '-');
	else if (m == 1 && p[1] == 2 && p[2] == 0 && t_fl->plus == 1)
		ft_resting(p, 1, '+');
}

static void	ft_error(int *p, int d, t_list *t_fl)
{
	char	r;

	if (d == -2147483648)
	{
		ft_resting(p, 2, '\0');
		if (t_fl->dot >= 11 || (t_fl->zero == 1
				&& t_fl->width > 11 && t_fl->dot == -1))
		{
			r = '0';
			write (1, "-", 1);
		}
		else
			r = ' ';
		while (p[0]-- > 11 && (t_fl->minus == '\0' || t_fl->dot >= t_fl->width))
			write(1, &r, 1);
		if (r == ' ')
			write (1, "-", 1);
		write(1, "2147483648", 10);
		p[0] -= 10;
		while (p[0]-- > 0 && t_fl->minus == 1 && t_fl->dot < t_fl->width)
			write(1, " ", 1);
	}
	if (d == 0 && t_fl->dot == 0)
		ft_sign(t_fl, p, d, 2);
}

static char	ft_asigner(t_list *t_fl, int d, int *p)
{
	p[1] = 0;
	p[2] = 0;
	p[6] = 0;
	p[5] = d;
	if (d < 0 && d != -2147483648)
		p[5] *= (-1);
	p[0] = ft_numlen(d, '\0');
	p[4] = ft_numlen(d, '\0');
	if (p[0] < t_fl->dot)
		p[0] = t_fl->dot;
	if (d < 0 || t_fl->plus == 1)
		p[0]++;
	p[3] = p[0];
	if (p[0] < t_fl->width)
		p[0] = t_fl->width;
	p[7] = p[0];
	ft_error(p, d, t_fl);
	ft_sign(t_fl, p, d, 1);
	if (t_fl->space > 0 && d >= 0)
		p[7]++;
	if (t_fl->space > 0 && d >= 0)
		write (1, " ", 1);
	if (t_fl->zero == 1 && t_fl->dot == -1 && t_fl->minus == '\0')
		return ('0');
	return (' ');
}

int	ft_printer_d2(t_list *t_fl, int d)
{
	int		p[8];
	char	*l;
	char	r;

	r = ft_asigner(t_fl, d, p);
	while (t_fl->minus == '\0' && p[0] > p[3])
	{
		write(1, &(r), 1);
		p[0]--;
	}
	ft_sign(t_fl, p, d, 1);
	while ((t_fl->minus == '\0' && p[0] > p[4])
		|| (t_fl->minus == 1 && p[3] > p[4]))
		ft_resting(p, 1, '0');
	l = ft_itoa(p[5], '\0');
	while (p[6] < p[4])
	{
		write (1, &(l[p[6]]), 1);
		ft_resting(p, 3, '\0');
	}
	free(l);
	if (t_fl->minus == 1)
		ft_resting(p, 4, '\0');
	return (p[7]);
}
