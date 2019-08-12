/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 01:35:47 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/12 22:20:43 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_check_base(char *base)
{
	char *p;

	if (!*base || !*(base + 1))
		return (0);
	while (*base)
	{
		p = base + 1;
		if (('a' <= *base && *base <= 'z')
			&& 'A' <= *base && *base <= 'Z'
			&& '0' <= *base && *base <= ' ')
			return (0);
		while (*p)
			if (*p++ == *base)
				return (0);
		base++;
	}
	return (1);
}

int		ft_check_nbr(char **nbr)
{
	int sign;

	sign = 1;
	while ((9 <= **nbr && **nbr <= 13) || **nbr == ' ')
		*nbr += 1;
	while (**nbr == '+' || **nbr == '-')
	{
		if (**nbr == '-')
			sign *= -1;
		*nbr += 1;
	}
	return (sign);
}

int		ft_inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_pow(int a, int n)
{
	if (n == 0)
	{
		return (1);
	}
	return (a * ft_pow(a, n - 1));
}

int		ft_size(int nbr, int n)
{
	int power;

	power = 1;
	while (nbr > ft_pow(n, power))
		power++;
	return (power);
}
