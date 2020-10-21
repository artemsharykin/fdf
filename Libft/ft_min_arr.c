/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:37:12 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 14:37:12 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_min_double_arr(long **arr, size_t sizex, size_t sizey)
{
	long	min;
	size_t	i;
	size_t	j;

	min = 3000000000;
	i = 0;
	if (!(arr))
		return (min);
	while (i < sizey)
	{
		if (!(arr[i]))
			return (min);
		j = 0;
		while (j < sizex)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
			j++;
		}
		i++;
	}
	return (min);
}

long	ft_max_double_arr(long **arr, size_t sizex, size_t sizey)
{
	long	max;
	size_t	i;
	size_t	j;

	max = -3000000000;
	if (!(arr))
		return (max);
	i = 0;
	while (i < sizey)
	{
		if (!(arr[i]))
			return (max);
		j = 0;
		while (j < sizex)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

long	ft_min_point_arr(t_point *arr, size_t size)
{
	size_t	i;
	long	min;

	min = 3000000000;
	if (!(arr))
		return (min);
	i = 0;
	while (i < size)
	{
		if ((long)arr[i].z < min)
			min = (long)arr[i].z;
		i++;
	}
	return (min);
}

long	ft_max_point_arr(t_point *arr, size_t size)
{
	size_t	i;
	long	max;

	max = -3000000000;
	if (!(arr))
		return (max);
	i = 0;
	while (i < size)
	{
		if ((long)(arr[i].z) > max)
			max = (long)arr[i].z;
		i++;
	}
	return (max);
}
