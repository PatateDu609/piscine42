/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:49:44 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/12 17:49:47 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_check_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_count(char *str, char *charset)
{
	int result;

	result = 1;
	while (*str)
	{
		if (ft_check_charset(*str, charset))
			result++;
		str++;
	}
	return (result);
}

char	*ft_create_str(char *str, char *charset, int *index)
{
	char	*ret;
	int		l;

	l = 0;
	while (str[l] && !ft_check_charset(str[l], charset))
		l++;
	l++;
	ret = (char *)malloc(sizeof(char) * l);
	l = 0;
	while (str[l] && !ft_check_charset(str[l], charset))
	{
		ret[l] = str[l];
		l++;
	}
	*index += l;
	ret[l] = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		n;

	n = ft_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (n + 1));
	i = 0;
	n = 0;
	while (str[i])
	{
		ret[n++] = ft_create_str(str + i, charset, &i);
		i++;
	}
	return (ret);
}
