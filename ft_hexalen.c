/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:43 by valarcon          #+#    #+#             */
/*   Updated: 2022/02/19 13:37:45 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hexalen(void *pp, unsigned int p2)
{
	int					count;
	unsigned long int	p;

	p = (unsigned long int)pp;
	if (p < p2)
		p = (unsigned long int)p2;
	count = 2;
	if (p == 0)
		return (3);
	while (p)
	{
		p = p / 16;
		count++;
	}
	return (count);
}
