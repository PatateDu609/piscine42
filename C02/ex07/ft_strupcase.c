/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:03:45 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/03 13:36:05 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	return (str);
}