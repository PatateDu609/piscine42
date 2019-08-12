/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:36:27 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/07 22:51:37 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(char *str, char *to_find)
{
	while (*str && *to_find && *str == *to_find)
	{
		str++;
		to_find++;
	}
	return (!*to_find);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
			if (ft_check(str, to_find))
				return (str);
		str++;
	}
	return (0);
}
