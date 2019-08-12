/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 02:20:43 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/08 04:29:47 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	a;
	int sign;
	int nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\r'
			|| str[a] == '\v' || str[a] == '\f' || str[a] == ' ')
		a++;
	while (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] && str[a] >= '0' && str[a] <= '9')
	{
		nbr = (nbr * 10);
		nbr = nbr + (int)(str[a] - '0');
		a++;
	}
	return (nbr * sign);
}
