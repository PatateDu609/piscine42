/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:02:00 by gboucett          #+#    #+#             */
/*   Updated: 2019/08/09 11:13:06 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min++ < max)
	{
		*(*range + i) = min - 1;
		i++;
	}
	return (i);
}
