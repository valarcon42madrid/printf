/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagdet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:02:33 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/26 13:16:30 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flagdet(t_list *t_fl, char x)
{
	if (x == '+')
		t_fl->plus = 1;
	else if (x == '-')
		t_fl->minus = 1;
	else if (x == '#')
		t_fl->hastag = 1;
	else if (x == ' ')
		t_fl->space++;
	else if (x == '0')
		t_fl->zero = 1;
}
