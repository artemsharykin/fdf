/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:25:59 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 14:38:16 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_min(size_t a, size_t b, size_t c, size_t d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < a && b < c && b < d)
		return (b);
	else if (c < a && c < b && c < d)
		return (c);
	else
		return (d);
}

size_t		ft_max(size_t a, size_t b, size_t c, size_t d)
{
	if (a > b && a > c && a > d)
		return (a);
	else if (b > a && b > c && b > d)
		return (b);
	else if (c > a && c > b && c > d)
		return (c);
	else
		return (d);
}

long		ft_min_arr(long *arr, size_t size)
{
	long	min;
	size_t	i;

	min = 3000000000;
	i = 0;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

long		ft_max_arr(long *arr, size_t size)
{
	long	max;
	size_t	i;

	max = -3000000000;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
