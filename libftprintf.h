/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:38:40 by valarcon          #+#    #+#             */
/*   Updated: 2022/03/02 21:29:47 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int	typ;
	int	upper;
	int	hastag;
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	dot;
	int	width;
}	t_list;

int		ft_atoi(const char *str);
void	ft_putnbr_base(void *nb, unsigned int nb2, char *base);
int		ft_hexalen(void *pp, unsigned int p2);
int		ft_strlen(const char *str);
int		ft_numlen(int n, unsigned int m);
char	*ft_itoa(int n, unsigned int m);
void	ft_flagdet(t_list *t_fl, char x);
int		ft_printer_c2(t_list *t_fl, int a);
int		ft_printer_s2(t_list *t_fl, char *s);
int		ft_printer_p2(t_list *t_fl, void *p);
int		ft_printer_x2(t_list *t_fl, unsigned int p);
int		ft_printer_d2(t_list *t_fl, int d);
int		ft_printer_u2(t_list *t_fl, unsigned int auxd);
int		ft_printf(const char *arg, ...);
#endif
