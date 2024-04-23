/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:34:49 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/01 18:34:10 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_flagdetector(const char *arg, int *i, t_list *t_flaggg)
{
	while (*(arg + *i) != 's' && *(arg + *i) != 'p' && *(arg + *i) != 'd'
		&& *(arg + *i) != 'i' && *(arg + *i) != 'c' && *(arg + *i) != 'u'
		&& *(arg + *i) != 'x' && *(arg + *i) != 'X' && *(arg + *i))
	{
		if (*(arg + (*i)) == '+' || *(arg + (*i)) == '-' || *(arg + (*i)) == '#'
			|| *(arg + (*i)) == ' ' || *(arg + (*i)) == '0')
		{
			ft_flagdet(t_flaggg, *(arg + (*i)));
			(*i)++;
		}
		else if (*(arg + (*i)) == '.')
		{
			(*i)++;
			t_flaggg->dot = ft_atoi(arg + (*i));
			if (*(arg + (*i)) >= '0' && *(arg + (*i)) <= '9')
				(*i) += ft_numlen(t_flaggg->dot, '\0');
		}
		else if (*(arg + (*i)) > '0' && *(arg + (*i)) <= '9')
		{
			t_flaggg->width = ft_atoi(arg + (*i));
			(*i) += ft_numlen(t_flaggg->width, '\0');
		}
		else
			break ;
	}
}

static void	ft_liststart(t_list *t_flaggg, int *i)
{
	if (i == '\0')
	{
		t_flaggg->hastag = '\0';
		t_flaggg->upper = '\0';
		t_flaggg->minus = '\0';
		t_flaggg->plus = '\0';
		t_flaggg->space = '\0';
		t_flaggg->zero = '\0';
		t_flaggg->dot = -1;
		t_flaggg->width = '\0';
		t_flaggg->typ = '\0';
	}
	else
	{
		write(1, "%", 1);
		i[0] = i[0] + 2;
		i[1]++;
	}
}

static t_list	*ft_vaflags(const char *arg, int *i)
{
	t_list	*t_flaggg;

	t_flaggg = malloc(sizeof(t_list));
	ft_liststart(t_flaggg, (int *) '\0');
	ft_flagdetector(arg, i, t_flaggg);
	if (*(arg + *i) == 's')
		t_flaggg->typ = 2;
	if (*(arg + *i) == 'p')
		t_flaggg->typ = 3;
	if (*(arg + *i) == 'd')
		t_flaggg->typ = 4;
	if (*(arg + *i) == 'i')
		t_flaggg->typ = 5;
	if (*(arg + *i) == 'c')
		t_flaggg->typ = 1;
	if (*(arg + *i) == 'u')
		t_flaggg->typ = 6;
	if (*(arg + *i) == 'x' || *(arg + *i) == 'X')
		t_flaggg->typ = 7;
	if (*(arg + *i) == 'X')
		t_flaggg->upper = 1;
	if (t_flaggg->typ != '\0')
		(i[0])++;
	return (t_flaggg);
}

static int	ft_flagprinter(int *i, const char *arg, va_list lis)
{
	t_list	*t_flag;

	t_flag = NULL;
	if (*(arg + i[0] + 1) != '%' && *(arg + i[0] + 1))
	{
		i[0]++;
		t_flag = ft_vaflags((arg), i);
		if (t_flag->typ == 1)
			i[1] += ft_printer_c2(t_flag, va_arg(lis, int));
		else if (t_flag->typ == 2)
			i[1] += ft_printer_s2(t_flag, va_arg(lis, char *));
		else if (t_flag->typ == 3)
			i[1] += ft_printer_p2(t_flag, va_arg(lis, void *));
		else if (t_flag->typ == 4 || t_flag->typ == 5)
			i[1] += ft_printer_d2(t_flag, va_arg(lis, int));
		else if (t_flag->typ == 6)
			i[1] += ft_printer_u2(t_flag, va_arg(lis, unsigned int));
		else if (t_flag->typ == 7)
			i[1] += ft_printer_x2(t_flag, va_arg(lis, unsigned int));
		free (t_flag);
	}
	return (i[0]);
}

int	ft_printf(const char *arg, ...)
{
	int		i[2];
	va_list	lis;

	i[1] = 0;
	i[0] = 0;
	va_start(lis, arg);
	while (*(arg + i[0]))
	{
		if (*(arg + i[0]) != '%')
		{
			write(1, &(*(arg + i[0])), 1);
			i[0]++;
			i[1]++;
		}
		else if (*(arg + i[0] + 1) == '%')
			ft_liststart((t_list *) '\0', i);
		else
			ft_flagprinter(&(i[0]), arg, lis);
	}
	va_end(lis);
	return (i[1]);
}

/*int main(void)
{
	char c;
	char *s = "%0#X, %-8.5c, %-0.5#i, %4.0p, %03.9#u, %7s\n";
	int i;
	unsigned int	u;
	char *p;
	char *s2 = "asd";
	int	x;

	c = 'f';
	i = -234;
	u = 456;
	p = 17987;
	x = 33;
	ft_printf(s, x, c, i, p, u, s2);
	printf(s, x, c, i, p, u, s2);
	return (0);
}*/
