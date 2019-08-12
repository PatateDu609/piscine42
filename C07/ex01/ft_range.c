/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:51:52 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/09 11:01:23 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ret;
	int i;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min++ < max)
	{
		ret[i] = min - 1;
		i++;
	}
	return (ret);
}
