/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:13:52 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/09 15:27:40 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_str_joined_len(int size, char **strs, char *sep)
{
	int result;
	int sep_len;

	sep_len = ft_strlen(sep);
	result = 0;
	while (size--)
	{
		result += ft_strlen(*strs);
		result += ft_strlen(sep) * (size - 1);
		strs++;
	}
	return (result);
}

void	ft_strcat(char *dest, char *src)
{
	int j;
	int i;

	i = 0;
	j = ft_strlen(dest);
	while (i < ft_strlen(src))
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_str_joined_len(size, strs, sep);
	ret = (char *)malloc(len * sizeof(char));
	*ret = 0;
	i = 0;
	while (size--)
	{
		ft_strcat(ret, *(strs + i));
		if (size)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}
