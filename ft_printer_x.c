/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:24:11 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/02 21:31:14 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_asigner(t_list *t_fl, int *j, char *r, unsigned int d)
{
	j[4] = 0;
	j[0] = 0;
	j[1] = ft_hexalen((void *) '\0', d) - 2;
	if (j[1] < t_fl->dot)
		j[1] = t_fl->dot;
	if (t_fl->hastag == 1 && d != 0)
		j[1] = j[1] + 2;
	j[2] = j[1];
	if (t_fl->width > j[1])
		j[1] = t_fl->width;
	j[3] = j[1];
	r[0] = ' ';
	if (t_fl->zero == 1 && t_fl->dot == -1)
		r[0] = '0';
	r[1] = 'x';
	if (t_fl->upper == 1)
		r[1] = 'X';
	if (d == '\0' && t_fl->dot == 0)
	{
		t_fl->upper = 2;
		j[1] = (ft_hexalen((void *) '\0', d) - 2) + t_fl->width;
		j[2] = j[1];
		j[3] = t_fl->width;
		j[0] = 7;
	}
}

static void	ft_modwri(char r, int *j, int mode, unsigned int d)
{
	if (mode == 1)
	{
		write(1, "0", 1);
		write(1, &(r), 1);
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
		if (d != '\0' || j[0] != 7)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		j[2]--;
		j[1]--;
	}
}

int	ft_printer_x2(t_list *t_fl, unsigned int d)
{
	int		j[5];
	char	r[2];

	ft_asigner(t_fl, j, r, d);
	if (d != 0 && t_fl->hastag == 1 && ((t_fl->zero == 1
				&& t_fl->dot == -1) || j[2] == j[1]))
		ft_modwri(r[1], j, 1, d);
	while (t_fl->minus == '\0' && j[1] > j[2])
		ft_modwri(r[0], j, 2, d);
	if (d != 0 && t_fl->hastag == 1 && ((t_fl->zero != 1
				|| t_fl->dot != -1)) && j[4] == 0)
		ft_modwri(r[1], j, 1, d);
	while ((t_fl->minus == '\0' && j[1] > ft_hexalen((void *) '\0', d) - 2)
		|| (t_fl->minus == 1 && j[2] > ft_hexalen((void *) '\0', d) - 2))
		ft_modwri('\0', j, 3, d);
	if (t_fl->upper == 1)
		ft_putnbr_base(0, d, "0123456789ABCDEF");
	if (t_fl->upper == '\0')
		ft_putnbr_base(0, d, "0123456789abcdef");
	j[1] = j[1] - (ft_hexalen((void *) '\0', d) - 2);
	while (t_fl->minus == 1 && j[1] > 0)
		ft_modwri(' ', j, 2, d);
	return (j[3]);
}
