/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 22:06:18 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/07 22:59:32 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int j;
	int len;

	len = ft_strlen(dest);
	j = 0;
	i = (size - 1) - len;
	while (src[j] != '\0' && j < i)
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (ft_strlen(src) + len);
}
