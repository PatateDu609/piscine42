/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:52:47 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/05 21:35:09 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha(char c)
{
	return (('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z')
			|| ('0' <= c && c <= '9'));
}

int		ft_is_lowercase(char c)
{
	return (('a' <= c && c <= 'z'));
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int maj;

	ft_strlowcase(str);
	i = -1;
	if (!ft_is_alpha(str[0]) || ft_is_lowercase(str[0]))
		maj = 1;
	else
		maj = 0;
	while (str[++i])
	{
		if (ft_is_alpha(str[i]) && maj && ft_is_lowercase(str[i]))
		{
			str[i] -= 'a' - 'A';
			maj = 0;
		}
		else if (!ft_is_alpha(str[i]))
			maj = 1;
		else if (ft_is_alpha(str[i]) && !ft_is_lowercase(str[i]))
			maj = 0;
	}
	return (str);
}
