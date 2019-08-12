/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:46:49 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/05 11:37:57 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		continue;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				l;

	l = ft_strlen(dest);
	dest[l - 1] = '\0';
	i = -1;
	while (++i < n && src[i] && dest[i])
		dest[i] = src[i];
	while (dest[++i])
		dest[i] = '\0';
	if (n < (unsigned int)ft_strlen(src))
		return (n);
	else
		return (ft_strlen(src));
}
