/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 08:17:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/09 04:13:10 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int r;

	if (nb <= 1)
		return (0);
	r = 2;
	while (nb % r)
	{
		if (r > nb)
			break ;
		r++;
	}
	if (r == nb)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
