/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:00:46 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 15:24:15 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long	ft_count_z(long a, t_fdf *fdf)
{
	return ((long)(fdf->scale * fdf->step * a));
}

void	draw_sharp(t_point *p1, t_point *p2, int dir, t_fdf *fdf)
{
	int		error;
	int		x;
	int		y;
	t_line	line;

	error = 0;
	line.p1 = *p1;
	line.p2 = *p2;
	if (p1->y > p2->y)
		ft_swap_points(&line);
	dir = (p1->y > p2->y) ? -dir : dir;
	x = line.p1.x;
	y = line.p1.y--;
	while (++y <= line.p2.y)
	{
		put_pixel(fdf, x + fdf->begin.x, y + fdf->begin.y,
				ft_grad_y(line.p1, line.p2, y - line.p1.y));
		error = error + abs(line.p2.x - line.p1.x) + 1;
		if (error >= (abs(line.p2.y - line.p1.y) + 1))
		{
			x = x + dir;
			error = error - (abs(line.p2.y - line.p1.y) + 1);
		}
	}
}

void	draw_narrow(t_point *p1, t_point *p2, int dir, t_fdf *fdf)
{
	int		error;
	int		x;
	int		y;
	t_line	line;

	error = 0;
	line.p1 = *p1;
	line.p2 = *p2;
	if (p1->x > p2->x)
		ft_swap_points(&line);
	dir = (p1->x > p2->x) ? -dir : dir;
	x = line.p1.x;
	y = line.p1.y;
	while (++x <= line.p2.x)
	{
		put_pixel(fdf, x + fdf->begin.x, y + fdf->begin.y,
				ft_grad_x(line.p1, line.p2, x - line.p1.x));
		error = error + abs(p2->y - p1->y) + 1;
		if (error >= (abs(p2->x - p1->x) + 1))
		{
			y = y + dir;
			error = error - (abs(p2->x - p1->x) + 1);
		}
	}
}

void	draw_line_plain(t_point p1, t_point p2, int dir, t_fdf *fdf)
{
	int		error;
	int		x;
	int		y;
	t_line	line;

	error = 0;
	line.p1 = p1;
	line.p2 = p2;
	x = line.p1.x--;
	y = line.p1.y;
	while (++x <= line.p2.x)
	{
		mlx_pixel_put(fdf->ptr, fdf->window, x, y,
				ft_grad_x(line.p1, line.p2, x - line.p1.x));
		error = error + abs(p2.y - p1.y) + 1;
		if (error >= (abs(p2.x - p1.x) + 1))
		{
			y = y + dir;
			error = error - (abs(p2.x - p1.x) + 1);
		}
	}
}

void	draw_line_n(t_point a, t_point b, t_fdf *fdf)
{
	int diry;
	int dirx;

	diry = (b.y - a.y) > 0 ? 1 : -1;
	dirx = (b.x - a.x) > 0 ? 1 : -1;
	if (abs(b.y - a.y) < (abs(b.x - a.x)))
		draw_narrow(&a, &b, diry, fdf);
	else
		draw_sharp(&a, &b, dirx, fdf);
}
