/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 05:55:31 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/01 23:55:25 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb += 2000000000;
		}
		nb *= -1;
	}
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int main()
{
	ft_putnbr(45545);
	return 0;
}
