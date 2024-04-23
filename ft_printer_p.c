/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:06 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/02 21:30:42 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static char	ft_asigner(t_list *t_fl, int *j, void *d)
{
	j[4] = 0;
	j[1] = ft_hexalen(d, '\0') - 2;
	if (j[1] < t_fl->dot)
		j[1] = t_fl->dot;
	j[1] = j[1] + 2;
	j[2] = j[1];
	if (t_fl->width > j[1])
		j[1] = t_fl->width;
	j[3] = j[1];
	if (t_fl->zero == 1 && t_fl->dot == -1)
		return ('0');
	else
		return (' ');
}

static void	ft_modewrit(char r, int *j, int mode)
{
	if (mode == 1)
	{
		write(1, "0x", 2);
		j[1] = j[1] - 2;
		j[2] = j[2] - 2;
		j[4] = 1;
	}
	if (mode == 2)
	{
		write(1, &(r), 1);
		j[1]--;
	}
	if (mode == 3)
	{
		write(1, "0", 1);
		j[2]--;
		j[1]--;
	}
}

int	ft_printer_p2(t_list *t_fl, void *d)
{
	int		j[5];
	char	r;

	r = ft_asigner(t_fl, j, d);
	if (t_fl->dot == '\0' && d == 0 && t_fl->width != 0)
		ft_modewrit(r, j, 2);
	if (t_fl->dot == '\0' && d == 0 && t_fl->width != 0)
		j[1]++;
	if (t_fl->dot == '\0' && d == 0 && t_fl->width == 0)
		j[3]--;
	if (((t_fl->zero == 1 && t_fl->dot == -1) || j[1] == j[2]))
		ft_modewrit('\0', j, 1);
	while (t_fl->minus == '\0' && j[1] > j[2])
		ft_modewrit(r, j, 2);
	if (((t_fl->zero == 0 || t_fl->dot != -1)) && j[4] == 0)
		ft_modewrit('\0', j, 1);
	while ((t_fl->minus == '\0' && j[1] > ft_hexalen(d, '\0') - 2)
		|| (t_fl->minus == 1 && j[2] > ft_hexalen(d, '\0') - 2))
		ft_modewrit('\0', j, 3);
	if (t_fl->dot != 0 || d != 0)
		ft_putnbr_base(d, '\0', "0123456789abcdef");
	j[1] = j[1] + 2 - ft_hexalen(d, '\0');
	while (t_fl->minus == 1 && j[1] > 0)
		ft_modewrit(' ', j, 2);
	return (j[3]);
}
