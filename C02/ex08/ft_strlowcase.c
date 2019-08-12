/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:44:54 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/04 11:42:00 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	return (str);
}