/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:58:45 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 11:42:45 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	iso(t_point a, t_fdf *fdf, char bull)
{
	t_point result;

	if (bull != 0)
	{
		result.x = (a.x - a.y) * cos(fdf->iso);
		result.y = -a.z + (a.x + a.y) * sin(fdf->iso);
		result.z = a.z;
		result.color = a.color;
	}
	else
	{
		result.x = a.x;
		result.y = a.y;
		result.z = a.z;
		result.color = a.color;
	}
	return (result);
}

t_point	init_point(int x, int y, int z)
{
	t_point result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.color = 0;
	return (result);
}

t_point	make_point(int x, int y, int z, int color)
{
	t_point result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.color = color;
	return (result);
}

t_line	*ft_swap_points(t_line *line)
{
	t_point temp;

	temp = line->p1;
	line->p1 = line->p2;
	line->p2 = temp;
	return (line);
}
