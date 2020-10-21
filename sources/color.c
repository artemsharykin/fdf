/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:01:01 by yalona           #+#    #+#             */
/*   Updated: 2020/03/08 15:53:42 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned int	rgb;

	rgb = 0;
	rgb = blue | (green << 8) | (red << 16);
	return ((int)rgb);
}

int		find_rgb(t_point cur, t_fdf *fdf)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (fdf->max_height == fdf->min_height || cur.z == fdf->min_height)
		return (fdf->grad.begin);
	if (cur.z == fdf->max_height)
		return (fdf->grad.end);
	red = (unsigned char)(((((fdf->grad.end & 0x00FF0000) >> 16) -
			((fdf->grad.begin & 0x00FF0000) >> 16))
			/ (float)abs(fdf->max_height - fdf->min_height))
					* (cur.z - fdf->min_height) +
					((fdf->grad.begin & 0x00FF0000) >> 16));
	green = (unsigned char)(((((fdf->grad.end & 0x0000FF00) >> 8) -
			((fdf->grad.begin & 0x0000FF00) >> 8)) /
					(float)abs(fdf->max_height - fdf->min_height))
							* (cur.z - fdf->min_height) +
							((fdf->grad.begin & 0x0000FF00) >> 8));
	blue = (unsigned char)(((((fdf->grad.end & 0x000000FF) -
			(fdf->grad.begin & 0x000000FF))) /
					(float)abs(fdf->max_height - fdf->min_height)) *
							(cur.z - fdf->min_height) +
							(fdf->grad.begin & 0x000000FF));
	return (ft_rgb(red, green, blue));
}

int		ft_grad_y(t_point min, t_point max, int cur)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				begin;
	int				end;

	begin = min.color;
	end = max.color;
	if (max.y == min.y)
		return (end);
	red = (unsigned char)(((((end & 0x00FF0000) >> 16) -
			((begin & 0x00FF0000) >> 16))
			/ (float)abs(max.y - min.y)) * cur +
					((begin & 0x00FF0000) >> 16));
	green = (unsigned char)(((((end & 0x0000FF00) >> 8) -
			((begin & 0x0000FF00) >> 8))
			/ (float)abs(max.y - min.y)) * cur +
					((begin & 0x0000FF00) >> 8));
	blue = (unsigned char)(((((end & 0x000000FF) - (begin & 0x000000FF)))
			/ (float)abs(max.y - min.y)) * cur + (begin & 0x000000FF));
	return (ft_rgb(red, green, blue));
}

int		ft_grad_x(t_point min, t_point max, int cur)
{
	unsigned char	red;
	unsigned		green;
	unsigned		blue;
	int				begin;
	int				end;

	begin = min.color;
	end = max.color;
	if (max.x == min.x)
		return (end);
	red = (unsigned)(((((end & 0x00FF0000) >> 16) -
			((begin & 0x00FF0000) >> 16))
			/ (float)abs(max.x - min.x)) * cur + ((begin & 0x00FF0000) >> 16));
	green = (unsigned)(((((end & 0x0000FF00) >> 8) -
			((begin & 0x0000FF00) >> 8))
			/ (float)abs(max.x - min.x)) * cur + ((begin & 0x0000FF00) >> 8));
	blue = (unsigned)(((((end & 0x000000FF) - (begin & 0x000000FF)))
			/ (float)abs(max.x - min.x)) * cur + (begin & 0x000000FF));
	return (ft_rgb(red, green, blue));
}
