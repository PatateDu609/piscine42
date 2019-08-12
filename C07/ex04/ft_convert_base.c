/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:27:59 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/12 22:20:41 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_check_base(char *base);
int		ft_check_nbr(char **nbr);
int		ft_inbase(char c, char *base);
int		ft_size(int nbr, int n);

int		ft_atoi_base(char *nbr, char *base_from)
{
	int result;
	int pos;
	int n;

	n = 0;
	while (base_from[n])
		n++;
	result = 0;
	while ((pos = ft_inbase(*nbr, base_from)) != -1)
	{
		result = result * n + pos;
		nbr++;
	}
	return (result);
}

char	*ft_printnbr_base(int nbr, char *base_to, char *result, int sign)
{
	int n;
	int i;
	int size;

	n = 0;
	i = 0;
	while (base_to[n])
		n++;
	size = ft_size(nbr, n);
	if (sign < 1)
	{
		result[0] = '-';
		i = 1;
	}
	while (i < size)
	{
		result[size - i] = base_to[nbr % n];
		nbr /= n;
		i++;
	}
	result[i + 1] = 0;
	return ((sign < 0) ? result : result + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		inter;
	char	*final_result;
	int		n;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	if (!(sign = ft_check_nbr(&nbr)))
		return (0);
	inter = ft_atoi_base(nbr, base_from);
	n = 0;
	while (base_to[n])
		n++;
	n = (sign > 1) ? ft_size(inter, n) + 1 : ft_size(inter, n) + 2;
	final_result = (char *)malloc(n);
	return (ft_printnbr_base(inter, base_to, final_result, sign));
}
