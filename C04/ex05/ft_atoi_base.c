/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:02:43 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/07 19:08:23 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		continue;
	return (i);
}

int	ft_pow(int a, int n)
{
	if (n == 0)
		return (1);
	return (a * ft_pow(a, n - 1));
}

int	ft_is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (*base)
	{
		i++;
		if (*base == c)
			return (i - 1);
		base++;
	}
	return (-1);
}

int	ft_checkbase(char *base)
{
	int i;

	if (ft_strlen(base) < 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| base[i] == '\n' || base[i] == '\t' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == '\v')
			return (0);
		if (ft_is_in_base(base[i], base + i + 1) != -1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int result;
	int i;
	int sign;
	int c;
	int j;

	if (!ft_checkbase(base))
		return (0);
	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	j = ft_strlen(str + i) - 1;
	while ((c = ft_is_in_base(str[i], base)) != -1)
	{
		result += c * ft_pow(ft_strlen(base), j);
		i++;
		j--;
	}
	return ((result) / ft_pow(ft_strlen(base), j + 1) * sign);
}
