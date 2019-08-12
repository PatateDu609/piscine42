/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:24:23 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/05 12:57:22 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec_hex(int a, char *code)
{
	if (a % 16 <= 9)
		code[1] = a % 16 + '0';
	else
		code[1] = a % 16 + 'A' - 10;
	if (a / 16 == 0)
		code[0] = '0';
	else if (a / 16 <= 9)
		code[0] = a / 16 + '0';
	else
		code[0] = a / 16 + 'a' - 10;
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	code[3];

	i = -1;
	code[2] = '\0';
	code[1] = 1;
	code[0] = 4;
	while (str[++i])
	{
		if (str[i] < 32)
		{
			write(1, "\\", 1);
			ft_dec_hex(str[i], code);
			write(1, code, 2);
		}
		else
			write(1, str + i, 1);
	}
}
