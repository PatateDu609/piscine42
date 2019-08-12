/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:41:04 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/07 02:25:40 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putnbr_base(int nbr, char *base);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_alphanum(char c)
{
	return (('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z')
			|| ('0' <= c && c <= '9'));
}

int		ft_check(char *base)
{
	char *c;

	if (!*base)
		return (0);
	if (!*(base + 1))
		return (0);
	while (*base)
	{
		c = base + 1;
		if (!ft_is_alphanum(*base))
			return (0);
		while (*c)
		{
			if (*c == *base)
				return (0);
			c++;
		}
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int n;

	if (ft_check(base))
	{
		n = ft_strlen(base);
		if (nbr < 0)
		{
			if (nbr == -2147483648)
			{
				ft_putnbr_base(nbr / n, base);
				ft_putnbr_base(-1 * (nbr % n), base);
				return ;
			}
			write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr / n)
			ft_putnbr_base(nbr / n, base);
		write(1, base + (nbr % n), 1);
	}
}
