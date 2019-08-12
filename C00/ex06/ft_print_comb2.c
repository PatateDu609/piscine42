/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:40:34 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/01 15:48:40 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int a)
{
	int b;

	if (a != 0)
	{
		b = a % 10;
		a /= 10;
		ft_putchar(a + '0');
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar('0' + a);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (a++ < 98)
	{
		b = 0;
		while (b++ <= 98)
		{
			ft_print(a);
			ft_putchar(' ');
			ft_print(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
		}
	}
}
